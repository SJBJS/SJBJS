#pragma once
#ifndef PHYSICS_H_
#define PHYSICS_H_

/////////////////////////
// INCLUDE
/////////////////////////
#include "../../GameObject/Base/ActorClass.h"
#include "Box2D/Box2D.h"
using namespace std;

/////////////////////////
// CLASS
/////////////////////////

class Physics
{
private:

public:
	bool Initialize();
	void Update();
	void Shutdown();
};

#endif