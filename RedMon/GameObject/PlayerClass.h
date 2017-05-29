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
public:
	virtual void Initialize()
	{
		position = XMFLOAT3(100, 600, 0);
		textureAddress = "data/player1.tga";
		tag = "player";
		Wight = 64;
		Hight = 64;
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
			if (myBullet[shotNum].IsFire())
				return;
			myBullet[shotNum].Fire(true);
			myBullet[shotNum].Spwan(this->position - XMFLOAT3(0,60,0));
			shotNum = (shotNum+1)%bulletNum;
		}

		XMFLOAT3 dir(h, v, 0);
		XMVECTOR vNormal = XMVector2Normalize(XMLoadFloat3(&dir));
		XMFLOAT3 normal;
		XMStoreFloat3(&normal, vNormal);
		position += normal;

		if (position.x < 80 || position.x>1200)
			position -= normal;

	};
	virtual void OnDestory()
	{
	}
};

#endif // !PLAYER_CLASS_H
