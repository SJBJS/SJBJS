#include "ActorClass.h"
/////////////////////////////////
//ObjectManage
/////////////////////////////////
ObjectManager* ObjectManager::objectManager = 0;

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

ActorClass * ObjectManager::FindObjectsWithTag(char * tag)
{
	return nullptr;
}

bool ObjectManager::Initialize()
{
	if (m_ObjectList->empty())
		return false;

	vector<ActorClass*>::iterator it;

	for (it = m_ObjectList->begin(); it != m_ObjectList->end(); ++it)
	{
		if ((*it) != NULL)
		{
			(*it)->Initialize();
		}
	}


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

ObjectManager * ObjectManager::Instance()
{
	if (!objectManager)
		return nullptr;
	return objectManager;
}



/////////////////////////////////
// ActorClass
/////////////////////////////////

ActorClass::ActorClass()
{
	position.x = position.y = position.z = 0;
	textureAddress = tag = "";
	Wight = Hight = 0;
	ObjectManager::Instance()->CreateObject(this);
}

ActorClass::~ActorClass()
{
}
XMFLOAT3 ActorClass::GetPosition() const
{
	return position;
}

char* ActorClass::GetTextureAddress() const
{
	return textureAddress;
}

XMFLOAT2 ActorClass::GetTextureWH() const
{
	return XMFLOAT2(Wight, Hight);
}

char * ActorClass::GetTag() const
{
	return tag;
}

void ActorClass::Initialize()
{
}

void ActorClass::Update()
{
}

void ActorClass::SetPosition(const float & x, const float & y)
{
	position.x = x;
	position.y = y;
}

XMFLOAT3 operator+(const XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	return XMFLOAT3(vec1.x + vec2.x, vec1.y+ vec2.y, vec1.z + vec2.z);
}

XMFLOAT3 operator-(const XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	return XMFLOAT3(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}

XMFLOAT3 operator*(const XMFLOAT3 & vec1, const float & scalar)
{
	return XMFLOAT3(vec1.x*scalar, vec1.y*scalar, vec1.z*scalar);
}

XMFLOAT3 operator/(const XMFLOAT3 & vec1, const float & scalar)
{
	return XMFLOAT3(vec1.x / scalar, vec1.y / scalar, vec1.z / scalar);
}

XMFLOAT3 operator+=(XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	vec1 = vec1 + vec2;
	return vec1;
}
