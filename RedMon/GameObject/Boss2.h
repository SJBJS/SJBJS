#pragma once

#include "RedMon/GameObject/Base/PawnClass.h"
#include"RedMon/GameObject/Base/ObjectManager.h"

class Boss2 : public PawnClass
{
private:
	PawnClass * player;
public:
	virtual void Initialize()
	{
		player = dynamic_cast<PawnClass*>(ObjectManager::Instance()->FindObjectWithTag("player"));
		position = XMFLOAT3(1000, 600, 0);
		textureAddress = "data/boss1.tga";
		Wight = 64;
		Hight = 64;
	};

	virtual void Update(float dt)
	{
	};
};