#pragma once
#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "Base\PawnClass.h"
#include "Bullet.h"

#include <windows.h>
class PlayerClass : public PawnClass
{
private:
	float Windowx;
	float speed; 
	bool jumping;  //점프중인지 판단
	float HP; //생명력
	
	
public:
	virtual void Initialize()
	{
		position = XMFLOAT3(-500, -150, 0);		
		SetCollistionShape(ShapeType::BoxShape);
		textureAddress = "data/Spritep.tga";
		HP = 3;
		jumping = false;
		tag = "player";
		Width = 128;
		Hight = 128;
		SetPhysics(true);
		speed = 100.0f;		
		SetRotateFrozen(true);
		SetGravityScale(1.0f);
		
	};

	virtual void Update(float dt)
	{
		
		float v = 0, h = 0;
			
		if (!jumping) {
			Move(0, -2);
			if (position.y <= -120) {
				if (Input->IsKeyDown(DIK_SPACE))
				{
					jumping = true;
				}
			}
		}
		if (position.y < 180){
			if (jumping) {
				Move(0, 25);
			}
		}
		//남은 HP만큼 왼쪽상단 체력바 제거
		for (int i = 0; i < 3 - HP; i++) {

			vector<ActorClass*>playerHP1 = ObjectManager::Instance()->FindObjectsWithTag("HP");
			playerHP1[i]->SetPosition(1200, 0);
		}

		XMFLOAT3 dir(h, v, 0);
		XMVECTOR vNormal = XMVector2Normalize(XMLoadFloat3(&dir));
		XMFLOAT3 normal;
		XMStoreFloat3(&normal, vNormal);
		XMFLOAT3 result = normal * dt * speed;
		//position += result;
		
		LocalMove(result.x, result.y );
		
		///플레이어 포지션 바닥에 붙어 닿을시 위치 처음으로 고정  점프동안에는 중력계속적용
		//바닥 기준 y높이 -180
		if (position.y < -180) {
			SetPosition(-500, -180);
			
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
	

	void OnDie()
	{
		ObjectManager::Instance()->ChangeLevel(2);
	}
};

#endif // !PLAYER_CLASS_H
