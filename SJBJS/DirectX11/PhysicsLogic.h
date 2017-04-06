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

	bool IsCollision(); //�浹 Ȯ��	
	bool GetElement(); //�ش� Ÿ���� �浹���� ���� �Ӽ�
	boolean overlapPT(Player r1, Tile r2); // �÷��̾�� Ÿ�� �浹Ȯ��
	boolean overlapPE(Player r1, Enermy r2); // �÷��̾�� �� �浹Ȯ��
	boolean overlapET(Enermy r1, Tile r2); // ���� Ÿ�� �浹Ȯ��

	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;
	unsigned char m_keyboardState[256];
};

#endif