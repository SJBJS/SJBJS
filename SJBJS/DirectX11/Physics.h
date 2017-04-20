#pragma once
#ifndef PHYSICS_H_
#define PHYSICS_H_

/////////////////////////
// INCLUDE
/////////////////////////
#include "ActorClass.h"
#include <vector>

using namespace std;

/////////////////////////
// CLASS
/////////////////////////

class Physics
{
private:
	vector<ActorClass*> * m_ObjectList;
public:
	bool Initialize(vector<ActorClass*>* objectList);
	void Update();
	void Shutdown();
};

#endif