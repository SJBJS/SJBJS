#include "ActorClass.h"

XMFLOAT3 ActorClass::GetPosition() const
{
	return postion;
}

char* ActorClass::GetTextureAddress() const
{
	return textureAddress;
}

XMFLOAT2 ActorClass::GetTextureWH() const
{
	return XMFLOAT2(Wight, Hight);
}

void ActorClass::Initialize()
{
	postion = XMFLOAT3(0, 0, 0);
	textureAddress = "data/player.tga";
	Wight = 32;
	Hight = 32;
}

void ActorClass::Update()
{
	if (Input->IsKeyDown(DIK_W))
		postion.y += -0.1f;
	if (Input->IsKeyDown(DIK_S))
		postion.y += 0.1f;
	if (Input->IsKeyDown(DIK_A))
		postion.x += -0.1f;
	if (Input->IsKeyDown(DIK_D))
		postion.x += 0.1f;
}
