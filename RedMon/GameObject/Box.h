#pragma once
#include"Base\ActorClass.h"


class Box : public ActorClass
{
public:
	virtual void Initialize()
	{
		textureAddress = "data/Sprite_Spike_001.tga"; //필수로 적어주셔야 오류가 없습니다.
		Width = 64;
		Hight = 128;
		//position = XMFLOAT3(100, 0, 0);
		SetRotateFrozen(true);
		SetCollistionType(BodyType::StaticBody);
		SetPhysics(true);
		SetGravityScale(0);
		tag = "Box";
		
	};

	virtual void Update(float dt)
	{
	
		Move(-383 * dt, 0);
		//왼쪽 바깥으로 박스가 나갈 경우 다시 리스폰
		if(position.x < -700)
			SetPosition(rand() % 1400 + 700, -120);

		if (position.y < -120)
			SetPosition(position.x, -120);
	};
	virtual void OnCollisionEnter(ActorClass * other)
	{
	}
	virtual void OnCollisionExit(ActorClass * other)
	{

	}
	virtual void OnDestory()
	{
	}

};
class Sharpbox : public ActorClass
{
public:
	virtual void Initialize()
	{
		textureAddress = "data/Sprite_Spike_001.tga"; //필수로 적어주셔야 오류가 없습니다.
		Width = 90;
		Hight = 180;
		//position = XMFLOAT3(100, 0, 0);
		SetRotateFrozen(true);
		SetCollistionType(BodyType::StaticBody);
		SetPhysics(true);
		SetGravityScale(0);
		tag = "sharp";

	};

	virtual void Update(float dt)
	{

		Move(-383 * dt, 0);
		//왼쪽 바깥으로 박스가 나갈 경우 다시 리스폰
		if (position.x < -700)
			SetPosition(rand() % 1400 + 700, -100);

		if (position.y < -150)
			SetPosition(position.x, -100);
	};
	virtual void OnCollisionEnter(ActorClass * other)
	{
	}
	virtual void OnCollisionExit(ActorClass * other)
	{

	}
	virtual void OnDestory()
	{
	}

};