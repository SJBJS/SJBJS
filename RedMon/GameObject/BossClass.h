#pragma once
#ifndef BOSS_CLASS_H
#define BOSS_CLASS_H

#include "Base\PawnClass.h"

class BossClass : public PawnClass
{
private:
	PawnClass * player;
public:
	virtual void Initialize()
	{
		player = dynamic_cast<PawnClass*>(ObjectManager::Instance()->FindObjectWithTag("player"));
		position = XMFLOAT3(1000, 100, 0);
		textureAddress = "data/boss1.tga";
		Wight = 64;
		Hight = 64;
	};

	virtual void Update(float dt)
	{
	};
};

#endif