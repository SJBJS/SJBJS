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
	random_device rand;
	float checktime;
	float movetime;
	float time;
public:

	virtual void Initialize()
	{
		mt19937 gen(rand());
		uniform_int_distribution<> positionx(30, 1200);
		position = XMFLOAT3(positionx(gen), 10, 0);
		textureAddress = "data/boss1.tga";
		tag = "enemy";
		Wight = -32;
		Hight = -32;

		time = 0;
		movetime = 0.001f;
		checktime = 1.0f;
		bulletNum = 3;
		shotNum = 0;
		myBullet = new Bullet[bulletNum];		
		for (int i = 0; i < bulletNum; ++i)
		{
			myBullet->Initialize();
			myBullet[i].setWH(-16, -16);
			myBullet[i].setPower(-0.5f);
		}
	};

	virtual void Update(float dt)
	{
		time = CStopWatch::GetCurrent();

		if (position.y <= 700)
			position.y += rand() % 30 * 0.02f;
		else
			position.y = 10;
		if (time >= checktime)
		{
			fire();
			checktime += 1.0f;
		}
		move();
	};

	void move()
	{
		if (this->time >= movetime)
		{
			position.x += 0.3f;
			movetime += 0.0055f;
		}
		else
		{
			position.x -= 0.3f;
		}


	};

	void fire()
	{
		myBullet[shotNum].Fire(true);
		myBullet[shotNum].Spwan(this->position + XMFLOAT3(0, 20, 0));
		shotNum = (shotNum + 1) % bulletNum;
	};


};

#endif
#pragma once
