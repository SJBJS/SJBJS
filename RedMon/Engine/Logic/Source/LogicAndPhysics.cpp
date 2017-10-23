#include "../LogicAndPhysics.h"
LogicAndPhysics::LogicAndPhysics()
{
	m_Logic = 0;
	m_Physics = 0;
}

LogicAndPhysics::~LogicAndPhysics()
{

}

bool LogicAndPhysics::Initialize()
{
	bool result;

	m_Logic = new Logic();
	if (!m_Logic)
	{
		return false;
	}
	result = m_Logic->Initialize();
	if (!result)
	{
		return false;
	}

	m_Physics = new Physics();
	if (!m_Physics)
	{
		return false;
	}
	result = m_Physics->Initialize();
	if (!result)
	{
		return false;
	}
	//정렬 기능 오류로 인해 주석처리.
	ObjectManager::Instance()->ObjectSort();
	return true;
}

bool LogicAndPhysics::Update(float dt)
{
	m_Physics->Update();
	m_Logic->Update(dt);

	return true;
}

void LogicAndPhysics::Shutdown()
{
	if (m_Logic)
	{
		m_Logic->Shutdown();
		delete m_Logic;
		m_Logic = 0;
	}
	if (m_Physics)
	{
		m_Physics->Shutdown();
		delete m_Physics;
		m_Physics = 0;
	}
}