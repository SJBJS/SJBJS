////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "bitmapclass.h"
#include "textureshaderclass.h"
#include "ActorClass.h"
///////////////////////
// INCLUDES //
///////////////////////
#include<DirectXMath.h>
/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame(float deltaTime);

private:
	bool Render(float deltaTime);

private:
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	BitmapClass* m_BackGruond;
	TextureShaderClass* m_TextureShader;

	BitmapClass* m_Objects;
};

#endif