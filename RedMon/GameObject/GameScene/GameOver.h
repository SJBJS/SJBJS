#pragma once
#include "RedMon\GameObject\Base\ActorClass.h"

class GameOver : public ActorClass
{
	virtual void Initialize() {
		position = XMFLOAT3(0, -100, 0);
		textureAddress = "data/ground.tga";
		tag = "";
		Width = 1280;
		Hight = 720;
		SetPhysics(false);
	}
	virtual void Update(float dt) {
	}

	virtual void OnCollisionEnter(ActorClass * other) {

	}
	virtual void OnCollisionExit(ActorClass * other) {

	}

	virtual void OnDestory() {

	}
};