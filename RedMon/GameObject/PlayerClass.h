#pragma once
#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "Base\PawnClass.h"

class PlayerClass : public PawnClass
{
	virtual void Initialize()
	{
		position = XMFLOAT3(0, 0, 0);
		textureAddress = "data/player.tga";
		tag = "player";
		Wight = 32;
		Hight = 32;
	};

	virtual void Update()
	{
		float v = 0, h = 0;

		if (Input->IsKeyDown(DIK_W))
			v -= 1.0f;
		if (Input->IsKeyDown(DIK_S))
			v += 1.0f;
		if (Input->IsKeyDown(DIK_A))
			h += -1.0f;
		if (Input->IsKeyDown(DIK_D))
			h += 1.0f;

		XMFLOAT3 dir(h, v, 0);
		//안되는거
		//float d = sqrt(dir.x*dir.x + dir.y*dir.y);
		//XMFLOAT3 normal(dir.x/d,dir.y/d,0);

		XMVECTOR vNormal = XMVector2Normalize(XMLoadFloat3(&dir));
		XMFLOAT3 normal;
		XMStoreFloat3(&normal, vNormal);
		position += normal;


	};
};

#endif // !PLAYER_CLASS_H
