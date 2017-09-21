#include "../Logic.h"

bool Logic::Initialize()
{
	if (!ObjectManager::Instance())
		return false;

	for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
		ObjectManager::Instance()->at(i)->Initialize();

	return true;
}
void Logic::Update(float dt)
{
	if (ObjectManager::Instance()->IsEmpty())
		return;
	for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
	{
		ActorClass * taget = ObjectManager::Instance()->at(i);
		if (taget->IsCollistion())
		{
			ActorClass * other = ObjectManager::Instance()->at(i)->CollisionOther();
			switch (taget->GetCollisionMode())
			{
			case CollisionMode::Enter:
				taget->OnCollisionEnter(other);
				break;
			case CollisionMode::Stay:
				break;
			case CollisionMode::Exit:
				taget->OnCollisionExit(other);
				break;

			default:
				break;
			}
			ObjectManager::Instance()->at(i)->SetCollistion(false, nullptr, CollisionMode::None);
		}
	}
	for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
	{
		ObjectManager::Instance()->at(i)->Update(dt);
	}
}

void Logic::Shutdown()
{
	DestoryObject();
}


void Logic::DestoryObject()
{
	if (!ObjectManager::Instance())
		return;

	for (int i = 0; i < ObjectManager::Instance()->Size(); ++i)
		ObjectManager::Instance()->at(i)->OnDestory();
}