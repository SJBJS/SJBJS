#include "ChildWindows.h"

ChildWindows::ChildWindows(HINSTANCE hInstance) : m_hInstance(hInstance)
{
	m_applicationName = TEXT("Childe Windows");
}

ChildWindows::ChildWindows(const ChildWindows & ref){}
ChildWindows::~ChildWindows(){}

bool ChildWindows::Initialize(HWND hWndParent)
{
	m_hWndParent = hWndParent;
	if (!InitializeWindows())
		return false;
	ChildHandle = this;
	return true;
}

void ChildWindows::Run()
{
	//github test
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
	TVINSERTSTRUCT TI;
	HTREEITEM Node;

	switch(iMessage) {
	case WM_CREATE:
		InitCommonControls();
		return 0;
	case WM_DESTROY:
		return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

LRESULT ChildWindows::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return ChildHandle->MessageHandler(hWnd, msg, wParam, lParam);
}

bool ChildWindows::InitializeWindows()
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


	GetClientRect(m_hWndParent, &rectView);
	m_hwnd = CreateWindowEx(WS_EX_CLIENTEDGE || WC_TREEVIEW, m_applicationName, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES | TVS_EDITLABELS, 0, 0, rectView.right *0.1, rectView.bottom, m_hWndParent, NULL, m_hInstance, NULL);
	ShowWindow(m_hwnd, SW_SHOW);
	return true;
}

bool ChildWindows::Frame()
{
	return false;
}

void ChildWindows::resize()
{
	GetClientRect(m_hWndParent, &rectView);
	MoveWindow(m_hwnd, 0, 0, rectView.right *0.1, rectView.bottom, TRUE);
}