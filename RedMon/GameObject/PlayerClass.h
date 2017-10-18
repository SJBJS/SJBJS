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
		myBullet = new Bullet[bulletNum];
		for (int i = 0; i < bulletNum; ++i)
		{
			myBullet->Initialize();
			myBullet[i].setWH(16, 16);
			myBullet[i].setPower(10.0f);
		}
		SetTextureUV(0, 0, imgOriginalSize.x/2, imgOriginalSize.y/2);
	};

	virtual void Update(float dt)
	{
		
		float v = 0, h = 0;
		/*if (Input->IsKeyPressed(DIK_W))
			v += 2.0f;
		if (Input->IsKeyPressed(DIK_S))
			v -= 2.0f;*/
		/*if (Input->IsKeyPressed(DIK_A))
			h += -2.0f;
		if (Input->IsKeyPressed(DIK_D))
			h += 2.0f;*/
		
		if (Input->IsKeyPressed(DIK_Q))
			Rotate(5 * dt);
		if (Input->IsKeyPressed(DIK_E))
			Rotate(-5 * dt);

		if (Input->IsKeyPressed(DIK_SPACE))
		{
			power += 2;
			Move(0, 40*dt*power);
			if (power > 40) { power = 0; }
			//Fire();
		   
			
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
		if (myBullet[shotNum].IsFire())
			return;
		myBullet[shotNum].Fire(true);
		
		myBullet[shotNum].Spwan(this->position,this->rotate,XMFLOAT3(0, 60, 0));
		shotNum = (shotNum + 1) % bulletNum;
	}
};

#endif // !PLAYER_CLASS_H
