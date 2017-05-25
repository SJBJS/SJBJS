#pragma once
#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H

#include <random>
#include "Base\PawnClass.h"
#include "Bullet.h"
using namespace std;

class EnemyClass : public PawnClass
{
private:
	int bulletNum;
	size_t shotNum;
	Bullet * myBullet;
	float Windowx;
	random_device rand;
public:

	virtual void Initialize()
	{
		mt19937 gen(rand());
		uniform_int_distribution<> dist(1, 3);
		position = XMFLOAT3(500, 30, 0);
		textureAddress = "data/player.tga";
		tag = "enemy";
		Wight = -32;
		Hight = -32;

		bulletNum = dist(gen);
		shotNum = 0;
		myBullet = new Bullet[bulletNum];
		for (int i = 0; i < bulletNum; ++i)
		{ 
			myBullet->Initialize();
			myBullet[i].setWH(-16, -16);
			myBullet[i].setPower(-0.5f);
		}
	};

	virtual void Update()
	{
		move();
		position.y += 0.2;

		if (position.y >= 300)
			this->OnDestory();

		fire();
	};

	void move()
	{
		mt19937 gen(rand());
		uniform_int_distribution<> dist(-3, 3);
		position.x += dist(gen);
	}

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
