#pragma once
#ifndef _LOGIC_H_
#define _LOGIC_H_

/////////////////////////
// INCLUDE
/////////////////////////
#include<vector>
#include"ActorClass.h"

using namespace std;

/////////////////////////
// CLASS
/////////////////////////
class Logic
{
private:
	vector<ActorClass*> * m_ObjectList;
public:
	bool Initialize(vector<ActorClass*>* objectList);
	void Update();
	void Shutdown();
};
#endif