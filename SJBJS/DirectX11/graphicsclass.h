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
#include<vector>
using namespace std;
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

	bool Initialize(int, int, HWND,vector<ActorClass*>*);
	void Shutdown();
	bool Frame(XMFLOAT2 playerMove, float deltaTime);

private:
	bool Render(XMFLOAT2 playerMove, float deltaTime);

private:
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	BitmapClass* m_Bitmap;
	BitmapClass* m_BackGruond;
	TextureShaderClass* m_TextureShader;

	vector<ActorClass*> * m_ObjectsList;
	BitmapClass* m_Objects;
};

#endif