#pragma once
#include "RedMon\GameObject\Base\ActorClass.h"

class Stage01 : public ActorClass
{
	virtual void Initialize() {
		position = XMFLOAT3(0, -100, 0);
		textureAddress = "data/ground.tga";
		tag = "stage01";
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

public:
	void SetStageClear(bool clear)
	{
		SetPhysics(clear);
	}

};