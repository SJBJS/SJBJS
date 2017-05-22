#include "../Logic.h"

bool Logic::Initialize()
{
	if (!ObjectManager::Instance())
		return false;

	for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
		ObjectManager::Instance()->at(i)->Initialize();

	return true;
}
void Logic::Update()
{
	if (ObjectManager::Instance()->IsEmpty())
		return;

	for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
	{
		ObjectManager::Instance()->at(i)->Update();
	}
}

void Logic::Shutdown()
{
}
