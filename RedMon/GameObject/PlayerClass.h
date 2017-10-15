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
		position = XMFLOAT3(0, 0, 0);
		textureAddress = "data/player1.tga";
		tag = "player";
		Width = 64;
		Hight = 64;
		SetPhysics(true);
		speed = 100.0f;

		SetRotateFrozen(true);

		bulletNum = 10;
		shotNum = 0;
		myBullet = new Bullet[bulletNum];
		for (int i = 0; i < bulletNum; ++i)
		{
			myBullet->Initialize();
			myBullet[i].setWH(16, 16);
			myBullet[i].setPower(10.0f);
		}

	};

	virtual void Update(float dt)
	{
		float v = 0, h = 0;
		if (Input->IsKeyPressed(DIK_W))
			v += 1.0f;
		if (Input->IsKeyPressed(DIK_S))
			v -= 1.0f;
		if (Input->IsKeyPressed(DIK_A))
			h += -1.0f;
		if (Input->IsKeyPressed(DIK_D))
			h += 1.0f;

		if (Input->IsKeyPressed(DIK_Q))
			Rotate(5 * dt);
		if (Input->IsKeyPressed(DIK_E))
			Rotate(-5 * dt);

		if (Input->IsKeyDown(DIK_SPACE))
		{
			Fire();
		}
		if (Input->IsKeyDown(DIK_K))
			ObjectManager::Instance()->FindObjectWithTag("Box")->SetPosition(100, 0);

		//XMFLOAT3 taget =  ObjectManager::Instance()->FindObjectWithTag("Box")->GetPosition();
		//XMFLOAT3 dir = taget - position;

		XMFLOAT3 dir(h, v, 0);
		XMVECTOR vNormal = XMVector2Normalize(XMLoadFloat3(&dir));
		XMFLOAT3 normal;
		XMStoreFloat3(&normal, vNormal);
		XMFLOAT3 result = normal * dt * speed;
		//position += result;
		LocalMove(result.x, result.y );

	};
	virtual void OnCollisionEnter(ActorClass * other)
	{
	}
	virtual void OnCollisionExit(ActorClass * other)
	{
	}
	virtual void OnDestory()
	{
	}
	void Fire()
	{
		if (myBullet[shotNum].IsFire())
			return;
		myBullet[shotNum].Fire(true);
		
		myBullet[shotNum].Spwan(this->position,this->rotate,XMFLOAT3(0, 60, 0));
		shotNum = (shotNum + 1) % bulletNum;
	}
};

#endif // !PLAYER_CLASS_H
