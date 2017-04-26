#include "Physics.h"


bool Physics::Initialize()
{
	if (!ObjectManager::Instance())
		return false;

	return true;
}

void Physics::Update()
{
}

void Physics::Shutdown()
{
}
