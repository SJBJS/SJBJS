#ifndef __MYOBJECTMANAGER_H_
#define __MYOBJECTMANAGER_H_

#include <vector>
#include<algorithm>
#include<DirectXMath.h>
#include"ActorClass.h"
using namespace std;
using namespace DirectX;

class ActorClass;

class ObjectManager
{
private:
	ObjectManager();
	ObjectManager(const ObjectManager& other) = delete;
	~ObjectManager();

	enum {LevelNum = 2};

	vector<ActorClass*>* m_ObjectList;
	static ObjectManager* objectManager;
	XMFLOAT2 screenSize;
	int curLevel;
	bool isNewState;
public:
	ActorClass * at(int idx);
	void PushObject(ActorClass * object);
	
	ActorClass *FindObjectWithTag(char * tag);
	vector<ActorClass*>* FindObjectsWithTag(char * tag);
	bool Initialize();
	void Shutdown();

	bool IsEmpty()const;
	int Size()const;

	void SetScreenSize(float x, float y);
	XMFLOAT2 GetScreenSize()const;

	static bool comp(const ActorClass *t1, const ActorClass *t2);
	void ObjectSort();

	void ChangeLevel(int levelNumber);
	bool IsNewLevel()const;
	int GetCurrentLevel()const;

	static ObjectManager* Instance();
};

#endif