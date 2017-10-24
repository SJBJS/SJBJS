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
		SetRotateFrozen(true);
		SetCollistionType(BodyType::StaticBody);
		SetPhysics(true);
		SetGravityScale(0);
		tag = "Box";
		
	};

	virtual void Update(float dt)
	{
	
		Move(-383 * dt, 0);
		//���� �ٱ����� �ڽ��� ���� ��� �ٽ� ������
		if(position.x < -700)
			SetPosition(rand() % 1400 + 700, -150);

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
class Sharpbox : public ActorClass
{
public:
	virtual void Initialize()
	{
		textureAddress = "data/player1.tga"; //�ʼ��� �����ּž� ������ �����ϴ�.
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
		//���� �ٱ����� �ڽ��� ���� ��� �ٽ� ������
		if (position.x < -700)
			SetPosition(rand() % 1400 + 700, -130);

		if (position.y < -150)
			SetPosition(position.x, -130);
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