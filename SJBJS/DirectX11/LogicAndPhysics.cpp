#include "LogicAndPhysics.h"

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

	return true;
}

bool LogicAndPhysics::Update()
{
	m_Logic->Update();
	m_Physics->Update();

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