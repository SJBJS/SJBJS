#include "ObjectManager.h"

ObjectManager* ObjectManager::objectManager = nullptr;

ObjectManager::ObjectManager()
{
	objectManager = this;
	m_ObjectList = new vector<ActorClass*>();
}
ObjectManager::~ObjectManager()
{
	if (m_ObjectList)
	{
		if (!m_ObjectList->empty())
		{
			Shutdown();
		}
		delete m_ObjectList;
		m_ObjectList = 0;
	}
}

ActorClass * ObjectManager::at(int idx)
{
	if (m_ObjectList->empty())
		return nullptr;
	if (idx >= m_ObjectList->size() || idx < 0)
		return nullptr;

	return m_ObjectList->at(idx);
}

void ObjectManager::CreateObject(ActorClass * object)
{
	if (!object)
		return;

	m_ObjectList->push_back(object);
}

ActorClass * ObjectManager::FindObjectWithTag(char * tag)
{
	if (m_ObjectList->empty())
		return false;

	vector<ActorClass*>::iterator it;

	for (it = m_ObjectList->begin(); it != m_ObjectList->end(); ++it)
	{
		if (!strcmp(tag, (*it)->GetTag()))
		{
			return *it;
		}
	}
	return nullptr;
}


bool ObjectManager::Initialize()
{

	return true;
}

void ObjectManager::Shutdown()
{
	if (m_ObjectList->empty())
		return;

	vector<ActorClass*>::iterator it;

	for (it = m_ObjectList->begin(); it != m_ObjectList->end(); ++it)
	{
		if ((*it) != NULL)
		{
			delete *it;
		}
	}
	m_ObjectList->clear();
}

bool ObjectManager::IsEmpty() const
{
	if (!m_ObjectList)
		return nullptr;
	return m_ObjectList->empty();
}

int ObjectManager::Size() const
{
	if (!m_ObjectList)
		return -1;
	return m_ObjectList->size();
}

void ObjectManager::SetScreenSize(float x, float y)
{
	screenSize.x = x;
	screenSize.y = y;
}

XMFLOAT2 ObjectManager::GetScreenSize()const
{
	return screenSize;
}

ObjectManager * ObjectManager::Instance()
{
	if (!objectManager) objectManager = new ObjectManager();
	return objectManager;
}


