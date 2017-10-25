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
	bool jumping;
	
	
public:
	virtual void Initialize()
	{
		position = XMFLOAT3(-500, -120, 0);
		
		textureAddress = "data/Spritep.tga";
		jumping = false;
		tag = "player";
		Width = 128;
		Hight = 128;
		SetPhysics(true);
		speed = 100.0f;		
		SetRotateFrozen(true);
		SetGravityScale(1.0f);
		bulletNum = 10;
		shotNum = 0;
		/*myBullet = new Bullet[bulletNum];
		for (int i = 0; i < bulletNum; ++i)
		{
			myBullet->Initialize();
			myBullet[i].setWH(16, 16);
			myBullet[i].setPower(10.0f);
		}*/
		
	};

	virtual void Update(float dt)
	{
		
		static int i = 0;
		i = 50;
		SetTextureUV(0 + i, 0, 64, imgOriginalSize.y);
		float v = 0, h = 0;
			
		
		/*if (Input->IsKeyPressed(DIK_Q))
			Rotate(5 * dt);
		if (Input->IsKeyPressed(DIK_E))
			Rotate(-5 * dt);*/
		if (!jumping) {
			Move(0, -2);
			if (position.y <= -120) {
				if (Input->IsKeyDown(DIK_SPACE))
				{
					jumping = true;
				}
			}
		}
		if (position.y < 150){
			if (jumping) {
				Move(0, 25);
			}
		}
		
		
		if (Input->IsKeyDown(DIK_K))
			ObjectManager::Instance()->FindObjectWithTag("Box")->SetPosition(100, 0);
		
		//충돌감지
		XMFLOAT3 taget =  ObjectManager::Instance()->FindObjectWithTag("Box")->GetPosition();
		XMFLOAT3 dir1 = taget - position; 
		if (dir1.x < 60) { ObjectManager::Instance()->FindObjectWithTag("Box")->SetPosition(100, 0); };

		
			XMFLOAT3 taget2 = ObjectManager::Instance()->FindObjectWithTag("sharp")->GetPosition();
			XMFLOAT3 dir2 = taget2 - position;
			if (dir1.x < 40) { ObjectManager::Instance()->FindObjectWithTag("sharp")->SetPosition(100, 0); };
		

		XMFLOAT3 dir(h, v, 0);
		XMVECTOR vNormal = XMVector2Normalize(XMLoadFloat3(&dir));
		XMFLOAT3 normal;
		XMStoreFloat3(&normal, vNormal);
		XMFLOAT3 result = normal * dt * speed;
		//position += result;
		
		LocalMove(result.x, result.y );
		
		///플레이어 포지션 바닥에 붙어 닿을시 위치 처음으로 고정  점프동안에는 중력계속적용
		//바닥 기준 y높이 -150
		if (position.y < -120) {
			SetPosition(-500, -120);
			
		}
		
		if (position.y >150) {
			
			SetGravityScale(200.0);
			jumping = false;
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
