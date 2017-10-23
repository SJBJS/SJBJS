////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "../graphicsclass.h"

GraphicsClass::GraphicsClass()
{
	m_Direct3D = 0;
	m_Camera = 0;
	m_TextureShader = 0;
	m_Objects = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;


	// Create the Direct3D object.
	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, -5.0f);

	// Create the texture shader object.
	m_TextureShader = new TextureShaderClass;
	if (!m_TextureShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_TextureShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the color shader object.", L"Error", MB_OK);
		return false;
	}

	// Objects list setting.
	ObjectReset(screenWidth, screenHeight);
	ObjectManager::Instance()->SetScreenSize(screenWidth, screenHeight);
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the texture shader object.
	if (m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = 0;
	}
	if (m_Objects)
	{
		for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
		{
			m_Objects[i].Shutdown();
		}
		delete[] m_Objects;
		m_Objects = 0;
	}
	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the D3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}

	return;
}


bool GraphicsClass::Frame(float deltaTime)
{
	bool result;


	// Render the graphics scene.
	result = Render(deltaTime);
	if (!result)
	{
		return false;
	}

	return true;
}


bool GraphicsClass::Render(float deltaTime)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	bool result;

	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();


	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	m_Direct3D->GetProjectionMatrix(projectionMatrix);
	m_Direct3D->GetOrthoMatrix(orthoMatrix);

	m_Direct3D->TurnZBufferOff();
	m_Direct3D->TurnOnAlphaBlending();

	//if (ObjectManager::Instance()->IsNewLevel())
	//{
	//	ObjectReset(m_screenWidth,m_screenHeight);
	//}
	for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
	{
		ActorClass* taget = ObjectManager::Instance()->at(i);
		XMFLOAT2 ActorWH = taget->GetActorWH();
		XMFLOAT2 position = XMFLOAT2(taget->GetPosition().x, taget->GetPosition().y);
		float rotate = taget->GetRotate();
		result = m_Objects[i].Render(m_Direct3D->GetDeviceContext(), XMFLOAT2(ObjectManager::Instance()->GetScreenSize().x / 2 - ActorWH.x / 2, ObjectManager::Instance()->GetScreenSize().y / 2 - ActorWH.y / 2), taget->GetTextureUV(), deltaTime);

		//회전가능
		XMMATRIX W = worldMatrix * XMMatrixRotationZ(rotate)* XMMatrixTranslation(position.x, position.y, 0);
		if (!result)
			return false;
		result = m_TextureShader->Render(m_Direct3D->GetDeviceContext(), m_Objects[i].GetIndexCount(), W, viewMatrix, orthoMatrix, m_Objects[i].GetTexture(), taget->GetTextureTranlsate());
		if (!result)
			return false;
	}

	m_Direct3D->TurnOffAlphaBlending();
	m_Direct3D->TurnZBufferOn();

	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();


	return true;
}

bool GraphicsClass::ObjectReset(int screenWidth, int screenHeight)
{
	if (!ObjectManager::Instance())
		return false;
	if (!ObjectManager::Instance()->IsEmpty())
	{
		m_Objects = new BitmapClass[ObjectManager::Instance()->Size()];
		if (!m_Objects)
			return false;
		for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
		{
			ActorClass * taget = ObjectManager::Instance()->at(i);
			char textureAddress[50] = "../RedMon/";
			char* objectAddress = taget->GetTextureAddress();
			strcat_s(textureAddress, objectAddress);
			XMFLOAT2 textureWH = taget->GetActorWH();
			XMFLOAT2 imgSize;
			bool result = m_Objects[i].Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), screenWidth, screenHeight, textureAddress, textureWH.x, textureWH.y, imgSize);
			taget->SetOriginalImgSize(imgSize);
			if (!result)
			{
				return false;
			}
		}
	}
	return true;
}
