#pragma once
#ifndef _LOGIC_H_
#define _LOGIC_H_

/////////////////////////
// INCLUDE
/////////////////////////
#include"../../GameObject/Base/ActorClass.h"
#include"../../GameObject/Base/ObjectManager.h"
using namespace std;

/////////////////////////
// CLASS
/////////////////////////
class Logic
{
private:
	void DestoryObject();
public:
	bool Initialize();
	void Update(float dt);
	void Shutdown();
};
#endif