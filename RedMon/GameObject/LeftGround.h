#pragma once
#include"Base\ActorClass.h"
class LeftGround : public ActorClass
{
	virtual void Initialize() {
		textureAddress = "data/Sprite_highground_002.tga";
		tag = "";
		Width = 256;
		Hight = 64;
		SetPhysics(true);
		SetHandleCount(0);
		SetCollistionType(BodyType::StaticBody);
	}
	virtual void Update(float dt) {
		Move(-400 * dt, 0);

		if (position.x < -700)
		{

		}

	}

	virtual void OnCollisionEnter(ActorClass * other) {

	}
	virtual void OnCollisionExit(ActorClass * other) {

	}

	virtual void OnDestory() {

	}
};
