#pragma once
#include"Base\ActorClass.h"


class Box : public ActorClass
{
public:
	virtual void Initialize()
	{
		textureAddress = "data/stone01.tga"; //�ʼ��� �����ּž� ������ �����ϴ�.
		Width = 64;
		Hight = 64;
		//position = XMFLOAT3(100, 0, 0);
		SetPhysics(true);
		tag = "Box";
	};

	virtual void Update(float dt)
	{

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