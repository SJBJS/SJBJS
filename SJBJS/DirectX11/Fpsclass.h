#pragma once
////////////////////////////////////////////////////////////////////////////////
// Filename: Fpsclass.h
////////////////////////////////////////////////////////////////////////////////

#ifndef _FPSCLASS_H
#define _FPSCLASS_H

#include "d3dclass.h"
#include "cameraclass.h"
#include "bitmapclass.h"
#include "textureshaderclass.h"
#include <windows.h> 
#include <mmsystem.h> 


class Fpsclass
{
public:
	
	Fpsclass();	
	Fpsclass(const Fpsclass&);
	~Fpsclass();
	void UpdateFPS();
	void Initialize(); 
	void Frame(); 
	int GetFps();

private:
	int m_fps, m_count; 
	unsigned long m_startTime;

};

#endif