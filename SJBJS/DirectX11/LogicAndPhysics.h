#ifndef _LOGIC_AND_PHYSIC_H_
#define _LOGIC_AND_PHYSIC_H_

////////////////////////
// INCLUDE
////////////////////////
#include<vector>
#include"ActorClass.h"
#include"Physics.h"
#include"Logic.h"


using namespace std;

class LogicAndPhysics
{
private: // private data.

	Physics * m_Physics;
	Logic * m_Logic;
public: // public function.
	LogicAndPhysics();
	~LogicAndPhysics();

	bool Initialize();
	bool Update();
	void Shutdown();
};

#endif