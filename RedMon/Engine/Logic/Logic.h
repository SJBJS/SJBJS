#ifndef _LOGIC_H_
#define _LOGIC_H_

/////////////////////////
// INCLUDE
/////////////////////////
#include"../../GameObject/Base/ObjectManager.h"
using namespace std;

/////////////////////////
// CLASS
/////////////////////////
class Logic
{
public:
	bool Initialize();
	void Update(float dt);
	void Shutdown();
};
#endif