#include"BossClass.h"

void BossClass::Initialize()
{
	player = dynamic_cast<PawnClass*>(ObjectManager::Instance()->FindObjectWithTag("player"));
	position = XMFLOAT3(500, 500, 0);
	tag = "boss";
	textureAddress = "data/player.tga";
	Wight = 32;
	Hight = 32;
}

void BossClass::Update()
{
	XMFLOAT3 dir = player->GetPosition() - position;
	dir.z = 0;
	float dis = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
	XMFLOAT3 normal = dir / dis;
	if (dis > 100)
	{
		position += normal;
	}
}
