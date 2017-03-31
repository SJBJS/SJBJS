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
	
	DWORD frameCount = 0;            //������ ī��Ʈ��
	float timeElapsed = 0.0f;            //�帥 �ð�
	DWORD lastTime = timeGetTime();   //������ �ð�(temp����)

	DWORD curTime = timeGetTime();      //���� �ð�
	float timeDelta = (curTime - lastTime)*0.001f;        //timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.

	timeElapsed += timeDelta;

	frameCount++;

	if (timeElapsed >= 1.0f)         //�帥�ð��� 1���̻��̸� ���� �ϰ������ ó��
	{
		float fps = (float)frameCount / timeElapsed;
		frameCount = 0;
		timeElapsed = 0.0f;
	}
	else
	{
		//�帥 �ð��� 1�ʰ� �ȵǸ� ������  
		//Sleep() �ص��ǰ� ���ص� �Ǳ�~ 
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


