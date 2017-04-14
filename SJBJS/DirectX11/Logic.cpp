#include "Logic.h"


bool Logic::Initialize(vector<ActorClass*>* objectList)
{
	if (!objectList)
		return false;

	m_ObjectList = objectList;

	for (int i = 0; i < m_ObjectList->size(); ++i)
		(*m_ObjectList)[i]->Initialize();

	return true;
}
void Logic::Update()
{
	if (m_ObjectList->empty())
		return;

	vector<ActorClass*>::iterator it;

	for (it = m_ObjectList->begin(); it != m_ObjectList->end(); ++it)
	{
		(*it)->Update();
	}
}

void Logic::Shutdown()
{
}
