#ifndef __BULLET_H_
#define __BULLET_H_
#include"Base\ActorClass.h"

class Bullet : public ActorClass
{
private:
	bool isStart;
	float power;
	float totalTime;
public:
	virtual void Initialize()
	{
		position = XMFLOAT3(0, 0, 2);
		textureAddress = "data/player.tga";
		tag = "bullet";
		isStart = false;
		totalTime = 0;
	};

	virtual void Update(float dt)
	{
		if (!isStart)
			return;

		LocalMove(0,power);
		totalTime += dt;
		if (totalTime > 3.0)
		{
			isStart = false;
			position.x = -1000 ;
			totalTime = 0;
			SetPhysics(false);
		}
	};
	void Fire(bool start) { isStart = start; }
	bool IsFire()const { return isStart; }
	void setWH(int wight, int hight)
	{
		this->Width = wight;
		this->Hight = hight;
	}
	void setPower(float po)
	{
		this->power = po;
	}
	void Spwan(const XMFLOAT3 &position,const float & rotate, const XMFLOAT3 &offset)
	{
		this->position = position;
		this->rotate = rotate;
		SetPhysics(true);
		LocalMove(offset.x, offset.y);
	};
};

#endif