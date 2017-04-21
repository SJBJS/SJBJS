#include "Logic.h"

bool Logic::Initialize()
{
	if (!objectManager)
		return false;


	for (int i = 0; i < objectManager->Size(); ++i)
		(*objectManager)[i]->Initialize();

	return true;
}
void Logic::Update()
{
	if (objectManager->IsEmpty())
		return;

	for (int i = 0; i < objectManager->Size(); ++i)
	{
		(*objectManager)[i]->Update();
	}
}

void Logic::Shutdown()
{
}
