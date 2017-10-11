#ifndef _LOGIC_AND_PHYSIC_H_
#define _LOGIC_AND_PHYSIC_H_

////////////////////////
// INCLUDE
////////////////////////
#include<vector>
#include"../../GameObject/Base/ActorClass.h"
#include"../../GameObject/Base/ObjectManager.h"
#include"Physics.h"
#include"Logic.h"


using namespace std;

class LogicAndPhysics
{
private: // private data.
	ObjectManager * m_objectManager;
	Physics * m_Physics;
	Logic * m_Logic;
public: // public function.
	LogicAndPhysics();
	~LogicAndPhysics();

	bool Initialize();
	bool Update(float dt);
	void Shutdown();
private:

};

#endif