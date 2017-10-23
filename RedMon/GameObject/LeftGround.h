#pragma once
#include"Base\ActorClass.h"
class LeftGround : public ActorClass
{
	virtual void Initialize() {
		position = XMFLOAT3(0, -100, 0);
		textureAddress = "data/ground.tga";
		tag = "";
		Width = 64;
		Hight = 64;
		SetPhysics(true);
		SetHandleCount(0);
		SetCollistionType(BodyType::StaticBody);
	}
	virtual void Update(float dt) {
		Move(-400 * dt, 0);
	}

	virtual void OnCollisionEnter(ActorClass * other) {

	}
	virtual void OnCollisionExit(ActorClass * other) {

	}

	virtual void OnDestory() {

	}
};
