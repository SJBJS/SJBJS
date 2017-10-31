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
	float myGrivity;
	float Accel;
	int i = 0;
public:
	virtual void Initialize()
	{
		position = XMFLOAT3(-500, -150, 0);
		SetCollistionShape(ShapeType::BoxShape);
		SetCollistionType(BodyType::DynamicBody);
		SetPhysics(true);
		SetRotateFrozen(true);
		SetGravityScale(234.0f);
		textureAddress = "data/run_32b.tga";
		HP = 3;
		jumping = false;
		tag = "player";
		Width = 80;
		Hight = 96;
		speed = 100.0f;
		Accel = 0;
		myGrivity = -9.8;
		
	};

	virtual void Update(float dt)
	{
		
		i += 64;
		
		SetTextureUV(15+i, 0, 32, imgOriginalSize.y/2);
		//TextureTranslate(2*dt, 0);

		if (!jumping) {
			if (Input->IsKeyDown(DIK_SPACE))
			{
				jumping = true;
				Accel = 12;
			}
		}
		if (jumping) {
			Accel += myGrivity*dt;
			Move(0, Accel);
		}
		//남은 HP만큼 왼쪽상단 체력바 제거
		for (int i = 0; i < 3 - HP; i++) {

			vector<ActorClass*>playerHP1 = ObjectManager::Instance()->FindObjectsWithTag("HP");
			playerHP1[i]->SetPosition(1200, 0);
		}

		float v = 0, h = 0;
		if (Input->IsKeyPressed(DIK_A))
			h = -1;
		if (Input->IsKeyPressed(DIK_D))
			h = +1;
		XMFLOAT3 dir(h, v, 0);
		XMVECTOR vNormal = XMVector2Normalize(XMLoadFloat3(&dir));
		XMFLOAT3 normal;
		XMStoreFloat3(&normal, vNormal);
		XMFLOAT3 result = normal * dt * speed;

		LocalMove(result.x, result.y + myGrivity*dt);
		if (position.y < -180) {
			position.y = -180;
			jumping = false;
		}

	};
	virtual void OnCollisionEnter(ActorClass * other)
	{
		if (other->GetTag() == "Ground")
			jumping = false;
		if (other->GetTag() == "Box")
			HP--;
		if (other->GetTag() == "sharp")
		{
			HP--;
			if(HP <= 0)
				OnDie();
		}
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
