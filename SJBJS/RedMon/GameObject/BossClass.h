#pragma once
#ifndef BOSS_CLASS_H
#define BOSS_CLASS_H

#include "PawnClass.h"

class BossClass : public PawnClass
{
private:
	PawnClass * player;
public:
	virtual void Initialize();
	virtual void Update();
};

#endif