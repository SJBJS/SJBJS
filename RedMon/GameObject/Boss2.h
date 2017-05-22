
#ifndef BOSS2_CLASS_H
#define BOSS2_CLASS_H

#include "Base\PawnClass.h"

class Boss2 : public PawnClass
{

private:
	PawnClass * player;
public:

	virtual void Initialize()
	{
		player = dynamic_cast<PawnClass*>(ObjectManager::Instance()->FindObjectWithTag("boss"));
		position = XMFLOAT3(500, 500, 0);
		textureAddress = "data/player.tga";
		Wight = 32;
		Hight = 32;
	}
	virtual void Update()
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
};

#endif // !PLAYER_CLASS_H
