#pragma once
#include"Base\ActorClass.h"
#include"LeftGround.h"
#include"RightGround.h"
#include <cstdlib>
#include <ctime>

class Ground : public ActorClass
{
	LeftGround *m_left;
	RightGround *m_right;

	virtual void Initialize() {
		textureAddress = "data/Sprite_highground_001.tga";
		tag = "Ground";
		Width = 256;
		Hight = 64;
		SetPhysics(true);
		SetHandleCount(0);
		SetCollistionType(BodyType::StaticBody);
	}
	virtual void Update(float dt) {

		srand((unsigned int)time(NULL));

		Move(-400 * dt, 0);

		if(position.x < -900)
		{
			int i = rand() % 1400 + 700;
			int j = rand() % 25 + -25;
			
			SetPosition(i, j);
			
			m_left->SetPosition(i, j);
			m_right->SetPosition(i + 10, j);
		}
	}



	virtual void OnCollisionEnter(ActorClass * other) {

	}
	virtual void OnCollisionExit(ActorClass * other) {

	}

	virtual void OnDestory() {

	}

public:

	void SetLeftRight(LeftGround * left, RightGround * right)
	{
		m_left = left;
		m_right = right;
	}
};
