#pragma once
#ifndef __CHILD_H_
#define __CHILD_H_
#include<Windows.h>
class ChildWindows {
private:
	HWND m_hwnd;
	LPCTSTR m_applicationName;
	HINSTANCE m_hInstance;

public:
	ChildWindows(HINSTANCE hInstance);
	~ChildWindows();

	bool Initialize(HWND hWndParent);
	void Run();
	void Shutdown();

	HWND GetHwnd()const;

	LRESULT CALLBACK MessageHandler(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static ChildWindows * had;
private:
	ChildWindows(const ChildWindows &ref);
	bool InitializeWindows(HWND hWndParent);
	bool Frame();
};

static ChildWindows* ChildHandle = 0;
#endif