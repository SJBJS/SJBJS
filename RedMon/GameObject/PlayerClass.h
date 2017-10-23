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
	float Windowx;
	float power;
	float speed;
public:
	virtual void Initialize()
	{
		position = XMFLOAT3(-500, -150, 0);
		textureAddress = "data/player1.tga";
		tag = "player";
		Width = 128;
		Hight = 128;
		SetPhysics(true);
		speed = 100.0f;
		power = 0;
		SetRotateFrozen(true);
		SetGravityScale(1.0f);
		bulletNum = 10;
		shotNum = 0;
	};

	virtual void Update(float dt)
	{
		if (Input->IsKeyDown(DIK_W))
		{
			ObjectManager::Instance()->ChangeLevel(1);
		}
		if (Input->IsKeyDown(DIK_Q))
		{
			ObjectManager::Instance()->ChangeLevel(0);
		}
		if (Input->IsKeyDown(DIK_E))
		{
			ObjectManager::Instance()->ChangeLevel(2);
		}
		if (Input->IsKeyPressed(DIK_SPACE))
		{
			power += 2;
			Move(0, 40*dt*power);
			if (power > 40) { power = 0; }
			//Fire();
		   
			
		}	
		


		///플레이어 포지션 바닥에 붙어 닿을시 위치 처음으로 고정  점프동안에는 중력계속적용
		if (position.y < -150) {
			SetPosition(-500, -150);
			
		}
		if (position.y >= -150) {
			SetGravityScale(30.0);		
			
		}
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
	void Jump(bool jumping)
	{
		
	}
	void JumpEnd(float dt)
	{
		Move(0, -40 * dt);
	}
	void Fire()
	{
	}
};

#endif // !PLAYER_CLASS_H
