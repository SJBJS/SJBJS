#pragma once
#include "Base\ActorClass.h"

class StageFlag : public ActorClass
{

	int stage = 0;

public:
	virtual void Initialize()
	{
		textureAddress = "data/flag.tga";
		Width = 20;
		Hight = 700;
		SetRotateFrozen(true);
		SetCollistionType(BodyType::StaticBody);
		SetPhysics(true);
		SetGravityScale(0);
		tag = "Flag";

	};

	virtual void Update(float dt)
	{
		Move(-400 * dt, 0);
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
public:
	void SetStageNum(int num)
	{
		stage = num;
	}
	int GetStageNum()
	{
		return stage;
	}

};