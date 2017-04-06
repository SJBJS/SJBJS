#pragma once
#ifndef PHYSICSLOGIC_H
#define PHYSICSLOGIC_H

#include "inputclass.h"
#include "PlayerClass.h"

typedef struct Tile{
	int leftLine, topLine;
	int width, height;
	
};
typedef struct Player {
	int leftLine, topLine;
	int width, height;
};
typedef struct Enermy {
	int leftLine, topLine;
	int width, height;
};
class PhysicsLogic
{
public:
	PhysicsLogic();
	~PhysicsLogic();

	bool IsCollision(); //충돌 확인	
	bool GetElement(); //해당 타일의 충돌가능 여부 속성
	boolean overlapPT(Player r1, Tile r2); // 플레이어와 타일 충돌확인
	boolean overlapPE(Player r1, Enermy r2); // 플레이어와 적 충돌확인
	boolean overlapET(Enermy r1, Tile r2); // 적과 타일 충돌확인

	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;
	unsigned char m_keyboardState[256];
};

#endif