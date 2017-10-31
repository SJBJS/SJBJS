#pragma once
#include"Base\ActorClass.h"
class BackGround : public ActorClass
{
	virtual void Initialize() {
		position = XMFLOAT3(0, -145, 0);
		textureAddress = "data/back.tga";
		tag = "";
		Width = 1280;
		Hight = 720;
		SetPhysics(false);
	}
	virtual void Update(float dt) {
		TextureTranslate(0.3*dt, 0);
	}

	virtual void OnCollisionEnter(ActorClass * other) {

	}
	virtual void OnCollisionExit(ActorClass * other) {

	}

	virtual void OnDestory() {

	}
};