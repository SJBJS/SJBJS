#pragma once
#ifndef PHYSICSLOGIC_H
#define PHYSICSLOGIC_H

#include "inputclass.h"
#include "PlayerClass.h"


typedef struct Tile{
	bool coll; //충돌체크
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
	bool IsCollision(); //충돌 확인	
	boolean SetElement(Tile r1); //타일 속성 설정
	bool GetElement(Tile r1); //해당 타일의 충돌가능 여부 속성
	boolean overlapPT(PlayerClass r1, Tile r2); // 플레이어와 타일 충돌확인
	boolean overlapPE(PlayerClass r1, Enermy r2); // 플레이어와 적 충돌확인
	boolean overlapET(Enermy r1, Tile r2); // 적과 타일 충돌확인

	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;
	unsigned char m_keyboardState[256];
};

#endif