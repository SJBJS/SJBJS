//////////////////////////////////////////////////////////////////////////////// 
// Filename: inputclass.h //
////////////////////////////////////////////////////////////////////////////// 
#ifndef _INPUTCLASS_H_ 
#define _INPUTCLASS_H_


/////////////////////////////// // PRE-PROCESSING DIRECTIVES // /////////////////////////////// 
#define DIRECTINPUT_VERSION 0x0800


///////////// // LINKING // ///////////// 
#pragma comment(lib, "dinput8.lib") 
#pragma comment(lib, "dxguid.lib")

//////////////
// INCLUDES //
//////////////
#include <dinput.h>
#include <DirectXMath.h>
using namespace DirectX;

////////////////////////////////////////////////////////////////////////////////
// Class name: InputClass
////////////////////////////////////////////////////////////////////////////////
class InputClass
{
public:
	InputClass();
	InputClass(const InputClass&);
	~InputClass();

	bool Initialize(HINSTANCE, HWND, int, int);
	void Shutdown();
	bool Frame();

	bool IsEscapePressed();
	void GetMouseLocation(int&, int&);

	static bool IsKeyDown(int keyNuber);
	static bool IsKeyUp(int keyNuber);
	static bool IsKeyPressed(int keyNuber);
private:
	bool ReadKeyboard();
	bool ReadMouse();
	void ProcessInput();

private:
	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;
	unsigned char m_keyboardState[2][256];
	unsigned char *p_CurKeyStates;
	unsigned char *p_PrevKeyStates;
	DIMOUSESTATE m_mouseState;
	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY;
	
}; 

static InputClass * Input = 0;
#endif
