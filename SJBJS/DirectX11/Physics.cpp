#include "Physics.h"


bool Physics::Initialize(vector<ActorClass*>* objectList)
{
	if (!objectList)
		return false;

	m_ObjectList = objectList;

	return true;
}

void Physics::Update()
{
}

void Physics::Shutdown()
{
}
