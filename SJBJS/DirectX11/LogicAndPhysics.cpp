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

	m_ObjectList = new vector<ActorClass*>();
	CreateObject();

	m_Logic = new Logic();
	if (!m_Logic)
	{
		return false;
	}
	result = m_Logic->Initialize(m_ObjectList);
	if (!result)
	{
		return false;
	}

	m_Physics = new Physics();
	if (!m_Physics)
	{
		return false;
	}
	result = m_Physics->Initialize(m_ObjectList);
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
	if (m_ObjectList)
	{
		if (!m_ObjectList->empty())
		{
			DeleteObjects();
		}
		delete m_ObjectList;
		m_ObjectList = 0;
	}

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

vector<ActorClass*>* LogicAndPhysics::GetObjects() const
{
	return m_ObjectList;
}

void LogicAndPhysics::CreateObject()
{
	// 추가할 오브젝트를 넣어주세요.
	// ex)m_ObjectList->push_back(new Player);
	m_ObjectList->push_back(new ActorClass);
}

void LogicAndPhysics::DeleteObjects()
{
	if (m_ObjectList->empty())
		return;

	vector<ActorClass*>::iterator it;
	
	for (it = m_ObjectList->begin(); it != m_ObjectList->end(); ++it)
	{
		if ((*it) != NULL)
			delete *it;
	}
	m_ObjectList->clear();
}
