#include "ActorClass.h"
/////////////////////////////////
//ObjectManage
/////////////////////////////////

ObjectManager::ObjectManager()
{
	m_ObjectList = 0;
}
ObjectManager::~ObjectManager()
{
}
ActorClass * ObjectManager::operator[](int idx)
{
	if (m_ObjectList->empty())
		return nullptr;
	if (idx >= m_ObjectList->size() || idx < 0)
		return nullptr;

	return (*m_ObjectList)[idx];
}

void ObjectManager::CreateObject(ActorClass * object)
{
	if (!object)
		return;

	m_ObjectList->push_back(object);
}

ActorClass * ObjectManager::FindObjectWithTag(char * tag)
{
	return nullptr;
}

ActorClass * ObjectManager::FindObjectsWithTag(char * tag)
{
	return nullptr;
}

bool ObjectManager::Initialize()
{
	m_ObjectList = new vector<ActorClass*>();
	return true;
}

void ObjectManager::Shutdown()
{
	if (m_ObjectList)
	{
		if (!m_ObjectList->empty())
		{
			DeleteObject();
		}
		delete m_ObjectList;
		m_ObjectList = 0;
	}
}

void ObjectManager::DeleteObject()
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

/////////////////////////////////
// ActorClass
/////////////////////////////////
XMFLOAT3 ActorClass::GetPosition() const
{
	return postion;
}

char* ActorClass::GetTextureAddress() const
{
	return textureAddress;
}

XMFLOAT2 ActorClass::GetTextureWH() const
{
	return XMFLOAT2(Wight, Hight);
}

void ActorClass::Initialize()
{
	postion = XMFLOAT3(0, 0, 0);
	textureAddress = "data/player.tga";
	Wight = 32;
	Hight = 32;
}

void ActorClass::Update()
{
	if (Input->IsKeyDown(DIK_W))
		postion.y += -0.1f;
	if (Input->IsKeyDown(DIK_S))
		postion.y += 0.1f;
	if (Input->IsKeyDown(DIK_A))
		postion.x += -0.1f;
	if (Input->IsKeyDown(DIK_D))
		postion.x += 0.1f;
}
