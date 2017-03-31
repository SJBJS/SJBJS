#include "Fpsclass.h"



Fpsclass::Fpsclass()
{
}

Fpsclass::Fpsclass(const Fpsclass& other) 
{ 
}

Fpsclass::~Fpsclass()
{
}

void Fpsclass::UpdateFPS()
{
	
	DWORD frameCount = 0;            //프레임 카운트수
	float timeElapsed = 0.0f;            //흐른 시간
	DWORD lastTime = timeGetTime();   //마지막 시간(temp변수)

	DWORD curTime = timeGetTime();      //현재 시간
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.

	timeElapsed += timeDelta;

	frameCount++;

	if (timeElapsed >= 1.0f)         //흐른시간이 1초이상이면 내가 하고싶은것 처리
	{
		float fps = (float)frameCount / timeElapsed;
		frameCount = 0;
		timeElapsed = 0.0f;
	}
	else
	{
		//흐른 시간이 1초가 안되면 생략함  
		//Sleep() 해도되고 안해도 되구~ 
	}


	lastTime = curTime;

}
void Fpsclass::Initialize() 
{ 
	m_fps = 0;
	m_count = 0; 
	m_startTime = timeGetTime(); 
	return;
}
void Fpsclass::Frame() 
{ 
	m_count++; 
	if (timeGetTime() >= (m_startTime + 1000))
	{ 
		m_fps = m_count; 
		m_count = 0; 
		m_startTime = timeGetTime(); 
	}
}

int Fpsclass::GetFps() 
{ 
	return m_fps; 
}


