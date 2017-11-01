#pragma once
#include"Base\ActorClass.h"
#include"LeftGround.h"
#include"RightGround.h"
#include <random>
#include <cstdlib>
#include <ctime>

class Ground : public ActorClass
{
	LeftGround *m_left;
	RightGround *m_right;

	virtual void Initialize() {
		textureAddress = "data/Sprite_highground_001.tga";
		tag = "Ground";
		Width = 512;
		Hight = 64;
		SetPhysics(true);
		SetHandleCount(0);
		SetCollistionType(BodyType::StaticBody);
	}
	virtual void Update(float dt) {

		Move(-400 * dt, 0);

		if (position.x < -900)
		{
			move();
		}
	}



	virtual void OnCollisionEnter(ActorClass * other) {
		if(other->GetTag() == "Ground")
		{
			move();
		}
	}
	virtual void OnCollisionExit(ActorClass * other) {

	}

	virtual void OnDestory() {

	}

	void move()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist1(780, 1400);
		uniform_int_distribution<> dist2(0, 4);

		int i = dist1(gen);
		int j = dist2(gen);

		if (j <= 3)
		{
			SetPosition(i, -300);

			m_left->SetPosition(i, -300);
			m_right->SetPosition(i + 10, -300);
		}
		else
		{
			SetPosition(i, -50);

			m_left->SetPosition(i, -50);
			m_right->SetPosition(i + 10, -50);
		}
	}

public:

	void SetLeftRight(LeftGround * left, RightGround * right)
	{
		m_left = left;
		m_right = right;
	}
};
