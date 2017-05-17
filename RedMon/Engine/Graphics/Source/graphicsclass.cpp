////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "../graphicsclass.h"

GraphicsClass::GraphicsClass()
{
	m_Direct3D = 0;
	m_Camera = 0;
	m_BackGruond = 0;
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
	result = m_Direct3D->Initialize(screenWidth, screenHeight, false, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
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

	// Create the model object.
	m_BackGruond = new BitmapClass;
	if (!m_BackGruond)
	{
		return false;
	}

		// Initialize the model object.
	result = m_BackGruond->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), screenWidth, screenHeight, "../RedMon/data/qq-2.tga", screenWidth, screenHeight);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}
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
	if (!ObjectManager::Instance())
		return false;
	if (!ObjectManager::Instance()->IsEmpty())
	{
		m_Objects = new BitmapClass[ObjectManager::Instance()->Size()];
		if (!m_Objects)
			return false;
		for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
		{
			char textureAddress[50] = "../RedMon/";
			char* objectAddress = (*ObjectManager::Instance())[i]->GetTextureAddress();
			strcat_s(textureAddress, objectAddress);
			XMFLOAT2 textureWH = (*ObjectManager::Instance())[i]->GetTextureWH();
			result = m_Objects[i].Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), screenWidth, screenHeight, textureAddress, textureWH.x, textureWH.y);
			if (!result)
			{
				MessageBox(hwnd, L"Could not initialize the Objects",L"Error",MB_OK);
			}
		}
	}
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
	// Release the model object.
	if (m_BackGruond)
	{
		m_BackGruond->Shutdown();
		delete m_BackGruond;
		m_BackGruond = 0;
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
	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.

	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.


	result = m_BackGruond->Render(m_Direct3D->GetDeviceContext(), XMFLOAT2(0,0), deltaTime);
	if (!result)
	{
		return false;
	}
	// Render the bitmap with the texture shader.
	result = m_TextureShader->Render(m_Direct3D->GetDeviceContext(), m_BackGruond->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, m_BackGruond->GetTexture());
	if (!result)
	{
		return false;
	}
	for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
	{
		XMFLOAT2 position = XMFLOAT2((*ObjectManager::Instance())[i]->GetPosition().x, (*ObjectManager::Instance())[i]->GetPosition().y);
		result = m_Objects[i].Render(m_Direct3D->GetDeviceContext(), position, deltaTime);
		if (!result)
			return false;
		result = m_TextureShader->Render(m_Direct3D->GetDeviceContext(), m_Objects[i].GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, m_Objects[i].GetTexture());
		if (!result)
			return false;
	}

	m_Direct3D->TurnOffAlphaBlending();
	m_Direct3D->TurnZBufferOn();

	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();


	return true;
}