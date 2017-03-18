#include "ChildWindows.h"

ChildWindows::ChildWindows(HINSTANCE hInstance) : m_hInstance(hInstance)
{
	m_applicationName = TEXT("Childe Windows");
}

ChildWindows::ChildWindows(const ChildWindows & ref){}
ChildWindows::~ChildWindows(){}

bool ChildWindows::Initialize(HWND hWndParent)
{
	if (!InitializeWindows(hWndParent))
		return false;
	ChildHandle = this;
	return true;
}

void ChildWindows::Run()
{
}

void ChildWindows::Shutdown()
{
}

HWND ChildWindows::GetHwnd() const
{
	return m_hwnd;
}

LRESULT ChildWindows::MessageHandler(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage) {
	case WM_CREATE:
		break;
	case WM_DESTROY:
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

LRESULT ChildWindows::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return ChildHandle->MessageHandler(hWnd, msg, wParam, lParam);
}

bool ChildWindows::InitializeWindows(HWND hWndParent)
{
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = ChildWindows::WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = m_hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = m_applicationName;
	RegisterClass(&WndClass);


	GetClientRect(hWndParent, &rectView);
	m_hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, m_applicationName, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, rectView.right / 8 - 1, rectView.bottom, hWndParent, NULL, m_hInstance, NULL);
	ShowWindow(m_hwnd, SW_SHOW);
	return true;
}

bool ChildWindows::Frame()
{
	return false;
}

void ChildWindows::resize(HWND hWndParent)
{
	GetClientRect(hWndParent, &rectView);
	MoveWindow(m_hwnd, 0, 0, rectView.right / 8 - 1, rectView.bottom, TRUE);
}