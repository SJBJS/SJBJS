#pragma once

#ifndef OBJECTMANAGER_CLASS_H
#define OBJECTMANAGER_CLASS_H

#include <vector>
#include "ActorClass.h"

class ObjectManager
{
private:
	ObjectManager();
	ObjectManager(const ObjectManager& other) = delete;
	~ObjectManager();

	vector<ActorClass*>* m_ObjectList;
	static ObjectManager* objectManager;
	XMFLOAT2 screenSize;
public:

	ActorClass * at(int idx);
	void CreateObject(ActorClass * object);
	ActorClass *FindObjectWithTag(char * tag);
	bool Initialize();
	void Shutdown();

	bool IsEmpty()const;
	int Size()const;
	void SetScreenSize(float x, float y);
	XMFLOAT2 GetScreenSize()const;
	static ObjectManager* Instance();
};

#endif