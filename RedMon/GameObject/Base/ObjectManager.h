#pragma once

#ifndef OBJECTMANAGER_CLASS_H
#define OBJECTMANAGER_CLASS_H

#include <vector>
#include "ActorClass.h"

class ObjectManager
{
private:
	vector<ActorClass * >* m_ObjectList;
	static ObjectManager* objectManager;
public:
	ObjectManager();
	~ObjectManager();

	ActorClass * at(int idx);
	void CreateObject(ActorClass * object);
	ActorClass *FindObjectWithTag(char * tag);
	ActorClass * FindObjectsWithTag(char * tag);
	bool Initialize();
	void Shutdown();

	bool IsEmpty()const;
	int Size()const;
	static ObjectManager* Instance();
};

#endif