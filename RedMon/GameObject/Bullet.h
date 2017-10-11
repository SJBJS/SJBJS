#ifndef __BULLET_H_
#define __BULLET_H_
#include"Base\ActorClass.h"

class Bullet : public ActorClass
{
private:
	bool isStart;
	float power;
public:
	virtual void Initialize()
	{
		position = XMFLOAT3(-1000 * rand()*100, 0, 0);
		textureAddress = "data/player.tga";
		tag = "bullet";
		isStart = false;
		float totalTime;
		SetPhysics(true);
	};

	virtual void Update(float dt)
	{
		if (!isStart)
			return;

		position.y -= power;
		if (this->position.y <= 0 || this->position.y >= 700)
		{
			isStart = false;
			position.x = -1000 *rand()*10 ;
		}
	};
	void Fire(bool start) { isStart = start; }
	bool IsFire()const { return isStart; }
	void setWH(int wight, int hight)
	{
		this->Wight = wight;
		this->Hight = hight;
	}
	void setPower(float po)
	{
		this->power = po;
	}
	void Spwan(XMFLOAT3 & ref)
	{
		position = ref;
	};
};

#endif