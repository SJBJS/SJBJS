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
	bool jumping;  //���������� �Ǵ�
	float HP; //�����
	
	
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
		//���� HP��ŭ ���ʻ�� ü�¹� ����
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
		
		///�÷��̾� ������ �ٴڿ� �پ� ������ ��ġ ó������ ����  �������ȿ��� �߷°������
		//�ٴ� ���� y���� -180
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
