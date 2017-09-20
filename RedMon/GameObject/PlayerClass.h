#pragma once
#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "Base\PawnClass.h"
#include "Bullet.h"
class PlayerClass : public PawnClass
{
private:
	int bulletNum;
	size_t shotNum;
	Bullet * myBullet;
	float Windowx;
	float speed;
public:
	virtual void Initialize()
	{
		position = XMFLOAT3(300, 600, 0);
		textureAddress = "data/player1.tga";
		tag = "player";
		Wight = 64;
		Hight = 64;
		
		speed = 100.0f;

		bulletNum = 10;
		shotNum = 0;
		myBullet = new Bullet[bulletNum];
		for (int i = 0; i < bulletNum; ++i)
			myBullet->Initialize();

	};

	virtual void Update(float dt)
	{
		float v = 0, h = 0;

		if (Input->IsKeyDown(DIK_A))
			h += -1.0f;
		if (Input->IsKeyDown(DIK_D))
			h += 1.0f;

		if (Input->IsKeyPressed(DIK_SPACE))
		{
			Fire();
		}

		XMFLOAT3 dir(h, v, 0);
		XMVECTOR vNormal = XMVector2Normalize(XMLoadFloat3(&dir));
		XMFLOAT3 normal;
		XMStoreFloat3(&normal, vNormal);
		XMFLOAT3 result = normal * dt * speed;
		position += result;
		if (position.x < 80 || position.x>1200)
			position -= result;

	};
	virtual void OnCollision(ActorClass * other)
	{
		Fire();
	}
	virtual void OnDestory()
	{
	}
	void Fire()
	{
		if (myBullet[shotNum].IsFire())
			return;
		myBullet[shotNum].Fire(true);
		myBullet[shotNum].Spwan(this->position - XMFLOAT3(0, 60, 0));
		shotNum = (shotNum + 1) % bulletNum;
	}
};

#endif // !PLAYER_CLASS_H
