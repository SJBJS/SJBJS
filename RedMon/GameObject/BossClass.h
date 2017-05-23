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
		position = XMFLOAT3(100, 100, 0);
		textureAddress = "data/player.tga";
		Wight = 16;
		Hight = 16;
	};

	virtual void Update()
	{
	};
};

#endif