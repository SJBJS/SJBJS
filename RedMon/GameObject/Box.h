#pragma once
#include"Base\ActorClass.h"


class Box : public ActorClass
{
public:
	virtual void Initialize()
	{
		textureAddress = "data/stone01.tga"; //�ʼ��� �����ּž� ������ �����ϴ�.
		Width = 32;
		Hight = 32;
		position = XMFLOAT3(100, 0, 0);
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