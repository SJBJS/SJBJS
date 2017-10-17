#pragma once
#include"Base\ActorClass.h"


class Box : public ActorClass
{


public:
	virtual void Initialize()
	{
		textureAddress = "data/stone01.tga"; //필수로 적어주셔야 오류가 없습니다.
		Width = 64;
		Hight = 64;
		//position = XMFLOAT3(100, 0, 0);
		SetRotateFrozen(true);
		SetPhysics(true);
		SetGravityScale(0);
		tag = "Box";
		
	};

	virtual void Update(float dt)
	{
	
		Move(-400 * dt, 0);
		//왼쪽 바깥으로 박스가 나갈 경우 다시 리스폰
		if(position.x < -700)
			SetPosition(rand() % 1400 + 700, -200);			

		if (position.y < -150)
			SetPosition(position.x, -150);
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