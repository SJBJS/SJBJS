#ifndef __BULLET_H_
#define __BULLET_H_
#include"Base\ActorClass.h"

class Bullet : public ActorClass
{
private:
	bool isStart;
public:
	virtual void Initialize()
	{
		position = XMFLOAT3(-100, 0, 0);
		textureAddress = "data/player.tga";
		tag = "bullet";
		Wight = 16;
		Hight = 16;
		isStart = false;
	};

	virtual void Update()
	{
		if (!isStart)
			return;

		position.y -= 0.01f;
	};
	void Fire(bool isStrat) { this->isStart = isStart; }
	void Spwan(XMFLOAT2 & ref)
	{
		position = ref;
};

#endif