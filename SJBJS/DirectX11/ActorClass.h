#pragma once
#ifndef  ACTOR_CLASS_H
#define ACTOR_CLASS_H

#include<vector>
#include <directxmath.h>
#include"inputclass.h"
using namespace DirectX;
using namespace std;

class ActorClass;

class ObjectManager
{
private:
	vector<ActorClass * >* m_ObjectList;
	static ObjectManager* objectManager;
public:
	ObjectManager();
	~ObjectManager();

	ActorClass * operator[](int idx);

	void CreateObject(ActorClass * object);
	ActorClass *FindObjectWithTag(char * tag);
	ActorClass * FindObjectsWithTag(char * tag);
	bool Initialize();
	void Shutdown();

	bool IsEmpty()const;
	int Size()const;
	static ObjectManager* Instance();
};


class ActorClass
{
public: //public data.
	
protected :
	XMFLOAT3 postion;
	char* textureAddress;
	float Wight, Hight;

private: //private data.

public: //public Function.
	ActorClass();
	~ActorClass();
	virtual XMFLOAT3 GetPosition() const;
	virtual char* GetTextureAddress() const;
	virtual XMFLOAT2 GetTextureWH() const;

	virtual void Initialize();
	virtual void Update();
private: //private Function.

};

#endif
