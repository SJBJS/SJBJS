#pragma once
#ifndef PHYSICSLOGIC_H
#define PHYSICSLOGIC_H

#include "inputclass.h"
#include "PlayerClass.h"


typedef struct Tile{
	bool coll; //�浹üũ
	int width, height;
	INT		Tndex;		// Tile Index
	RECT	Trect;		// Tile Image Rect
	XMFLOAT2	Tp;		// Tile Position
	
};

typedef struct Enermy {
	
	int width, height;
	RECT	Erect;		// Enermy Image Rect
	XMFLOAT2	Ep;		// Enermy Position
};
class PhysicsLogic
{
public:
	int TileWidth;
	int TileHeight;
	int TileMaxX;
	int TileMaxY;
	
	PhysicsLogic();
	~PhysicsLogic();
	void initTileSet();
	bool IsCollision(); //�浹 Ȯ��	
	boolean SetElement(Tile r1); //Ÿ�� �Ӽ� ����
	bool GetElement(Tile r1); //�ش� Ÿ���� �浹���� ���� �Ӽ�
	boolean overlapPT(PlayerClass r1, Tile r2); // �÷��̾�� Ÿ�� �浹Ȯ��
	boolean overlapPE(PlayerClass r1, Enermy r2); // �÷��̾�� �� �浹Ȯ��
	boolean overlapET(Enermy r1, Tile r2); // ���� Ÿ�� �浹Ȯ��

	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;
	unsigned char m_keyboardState[256];
};

#endif