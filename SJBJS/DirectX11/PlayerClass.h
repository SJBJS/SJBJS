#pragma once
#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include "PawnClass.h"

class PlayerClass : public PawnClass
{
public:
	int damage;
	int width, height;
	RECT	Prect;		// Player Image Rect
	XMFLOAT2	Pp;		// Player Position

};

#endif // !PLAYER_CLASS_H
