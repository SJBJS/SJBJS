#pragma once
#include"Base\ActorClass.h"
class BackGround : public ActorClass
{
	virtual void Initialize() {
		position = XMFLOAT3(0, 0, 0);
		textureAddress = "data/space1.tga";
		tag = "";
		Wight = 1280;
		Hight = 720;
		SetPhysics(false);
	}
	virtual void Update(float dt) {
		TextureTranslate(0.001, 0);
	}

	virtual void OnCollisionEnter(ActorClass * other) {

	}
	virtual void OnCollisionExit(ActorClass * other) {

	}

	virtual void OnDestory() {

	}
};