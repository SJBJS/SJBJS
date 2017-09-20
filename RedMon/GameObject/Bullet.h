#ifndef __BULLET_H_
#define __BULLET_H_
#include"Base\ActorClass.h"

class Bullet : public ActorClass
{
private:
	bool isStart;

	float totalTime;
public:
	virtual void Initialize()
	{
		position = XMFLOAT3(-1000 * rand()*100, 0, 0);
		textureAddress = "data/player.tga";
		tag = "bullet";
		Wight = 16;
		Hight = 16;
		isStart = false;
		float totalTime;
	};

	virtual void Update(float dt)
	{
		if (!isStart)
			return;
		position.y -= 0.5f;
		if (this->position.y <= 0)
		{
			isStart = false;
			position.x = -1000 *rand()*10 ;
		}
	};
	void Fire(bool start) { isStart = start; }
	bool IsFire()const { return isStart; }
	void Spwan(XMFLOAT3 & ref)
	{
		position = ref;
	};
};

#endif