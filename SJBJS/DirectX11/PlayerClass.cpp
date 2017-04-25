#include "PlayerClass.h"

void PlayerClass::Initialize()
{
	position = XMFLOAT3(0, 0, 0);
	textureAddress = "data/player.tga";
	tag = "player";
	Wight = 32;
	Hight = 32;
}

void PlayerClass::Update()
{
	if (Input->IsKeyDown(DIK_W))
		position.y += -1.0f;
	if (Input->IsKeyDown(DIK_S))
		position.y += 1.0f;
	if (Input->IsKeyDown(DIK_A))
		position.x += -1.0f;
	if (Input->IsKeyDown(DIK_D))
		position.x += 1.0f;
}
