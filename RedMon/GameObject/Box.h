#pragma once
#include"Base\ActorClass.h"

#include <random>

class Box : public ActorClass
{
public:
	virtual void Initialize()
	{
		textureAddress = "data/Sprite_Spike_001.tga"; //필수로 적어주셔야 오류가 없습니다.
		Width = 42;
		Hight = 64;
		//position = XMFLOAT3(100, 0, 0);
		SetRotateFrozen(true);
		SetCollistionType(BodyType::StaticBody);
		SetCollistionShape(ShapeType::TriangleShape);
		SetPhysics(true);
		SetGravityScale(0);
		tag = "Box";

	};

	virtual void Update(float dt)
	{

		//Move(-383 * dt, 0);
		////왼쪽 바깥으로 박스가 나갈 경우 다시 리스폰
		//if(position.x < -700)
		//	SetPosition(rand() % 1400 + 700, -210);

		//if (position.y < -120)
		//	SetPosition(position.x, -210);
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
		Width = 84;
		Hight = 128;
		SetRotateFrozen(true);
		SetCollistionType(BodyType::StaticBody);
		SetCollistionShape(ShapeType::TriangleShape);
		SetPhysics(true);
		SetGravityScale(0);
		tag = "sharp";


	};

	virtual void Update(float dt)
	{
		Move(-400 * dt, 0);

		if (position.x < -800)
		{
			move();
		}

		if (position.x >= 700)
		{
			move();
		}
	};
	virtual void OnCollisionEnter(ActorClass * other)
	{
		if (other->GetTag() == "player")
		{
			position.x = -800;
		}
	}
	virtual void OnCollisionExit(ActorClass * other)
	{

	}
	virtual void OnDestory()
	{
	}

	void move()
	{
		if (IsCollistion() != TRUE)
		{

			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> dist(0, 2);

			int i = dist(gen);

			vector<ActorClass*>SpikeSet = ObjectManager::Instance()->FindObjectsWithTag("Ground");
			XMFLOAT3 SpikeSetpos = SpikeSet[i]->GetPosition();
			if (SpikeSetpos.x >= 700) {
				SetPosition(SpikeSet[i]->GetPosition().x + rand() % 75 + -75, SpikeSet[i]->GetPosition().y + 70);
			}
		}
	}

};
class HPbar : public ActorClass
{
public:
	virtual void Initialize()
	{
		textureAddress = "data/hart.tga"; //필수로 적어주셔야 오류가 없습니다.
		Width = 40;
		Hight = 40;
		//position = XMFLOAT3(100, 0, 0);		
		SetPhysics(false);
		tag = "HP";

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