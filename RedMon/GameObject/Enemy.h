#pragma once
#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H

#include "Base\PawnClass.h"
#include "Bullet.h"

class EnemyClass : public PawnClass
{
private:
	int bulletNum;
	size_t shotNum;
	Bullet * myBullet;
	float Windowx;
public:

	virtual void Initialize()
	{
		position = XMFLOAT3(500, 30, 0);
		textureAddress = "data/player.tga";
		tag = "enemy";
		Wight = -16;
		Hight = -16;

		bulletNum = rand() % 3;
		shotNum = 0;
		myBullet = new Bullet[bulletNum];
		for (int i = 0; i < bulletNum; ++i)
			myBullet->Initialize();
	};

	virtual void Update()
	{
		position.y += 0.5;

		if (position.y >= 300)
			this->OnDestory();

		fire();
	};

	void fire()
	{
		if (myBullet[shotNum].IsFire())
			return;
		myBullet[shotNum].Fire(true);
		myBullet[shotNum].Spwan(this->position + XMFLOAT3(0, 20, 0));
		shotNum = (shotNum + 1) % bulletNum;
	};
};

#endif
#pragma once
