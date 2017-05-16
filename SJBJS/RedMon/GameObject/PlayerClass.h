#pragma once
#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "PawnClass.h"

class PlayerClass : public PawnClass
{
	virtual void Initialize();
	virtual void Update();
};

#endif // !PLAYER_CLASS_H
