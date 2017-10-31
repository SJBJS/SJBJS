#pragma once
#include "RedMon\GameObject\Base\ActorClass.h"

class GameStage : public ActorClass
{
	bool clear[5];


	virtual void Initialize() {
		position = XMFLOAT3(0, -100, 0);
		textureAddress = "data/ground.tga";
		tag = "";
		Width = 1280;
		Hight = 720;
		SetPhysics(false);

		clear[0] = true;
		for (int i = 1; i < 5; i++)
			clear[i] = false;
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

	void SetClearNum(int StageNum)
	{
		clear[StageNum] = true;
	}

	bool GetClearNum(int StageNum)
	{
		return clear[StageNum];
	}
};