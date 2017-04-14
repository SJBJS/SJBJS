#pragma once
#ifndef BACKGORIND_H_
#define BACKGORIND_H_

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
class Backgorund
{
public:
	int TileWidth; //Ÿ�� ����(���� ���������� ���̾�)
	
	int TileMaxX; // Ÿ�� ���� �ִ� ����
	int TileMaxY; // Ÿ�� ���� �ִ� ����
	
	Backgorund();
	~Backgorund();
	void initTileSet(); //Ÿ�� �ʱ�ȭ
	bool IsCollision(); //Ÿ�ϼӼ�üũ	
	boolean SetElement(Tile r1); //Ÿ�� �Ӽ� ����
	bool GetElement(Tile r1); //�ش� Ÿ���� �浹���� Ȯ��
	boolean overlapPT(PlayerClass r1, Tile r2); // �÷��̾�� Ÿ�� �浹Ȯ��
	boolean overlapPE(PlayerClass r1, Enermy r2); // �÷��̾�� �� �浹Ȯ��
	boolean overlapET(Enermy r1, Tile r2); // ���� Ÿ�� �浹Ȯ��

	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;
	unsigned char m_keyboardState[256];
};

#endif