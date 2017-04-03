#pragma once
#ifndef __CHILD_H_
#define __CHILD_H_
#include<Windows.h>
#include <CommCtrl.h>
#include <iostream>
class ChildWindows {
private:
	HWND m_hwnd;
	HWND m_hWndParent;
	LPCTSTR m_applicationName;
	HINSTANCE m_hInstance;
	RECT rectView;

public:
	ChildWindows(HINSTANCE hInstance);
	~ChildWindows();

	bool Initialize(HWND hWndParent);
	void Run();
	void Shutdown();
	void resize();
	void InsertView(HTREEITEM pNode, int pid);

	HWND GetHwnd()const;

	LRESULT CALLBACK MessageHandler(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static ChildWindows * had;
private:
	ChildWindows(const ChildWindows &ref);
	bool InitializeWindows();
	bool Frame();
};

static ChildWindows* ChildHandle = 0;

struct ParentName
{
	int parent;
	LPWSTR Name;
};

#endif