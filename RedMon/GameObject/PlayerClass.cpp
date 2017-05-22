#include "PlayerClass.h"

void PlayerClass::Initialize()
{
	position = XMFLOAT3(500, 0, 0);
	textureAddress = "data/player.tga";
	tag = "player";
	Wight = 32;
	Hight = 32;
}

void PlayerClass::Update()
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
	

}
