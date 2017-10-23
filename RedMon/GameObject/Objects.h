#pragma once

#include"BackGround.h"
#include"PlayerClass.h"
#include"Bullet.h"
#include"Box.h"
#include <cstdlib>
#include <ctime>
using namespace std;

static vector<void(*)()> CallBack;

static void Level0()
{ /* z���� ���� ��� �� �������� �����Ҵ��� ��ü�� ���� �տ� �׷����ϴ�. */
	srand((unsigned int)time(NULL));

	new BackGround();
	new PlayerClass();
	(new Box())->SetPosition((rand() % 500) + 1, -200);
	(new Box())->SetPosition(rand() % 1400 + 700, -200);
	(new Box())->SetPosition(rand() % 1400 + 700, -200);
	(new Box())->SetPosition(rand() % 1400 + 700, -200);
	(new Box())->SetPosition(rand() % 1400 + 700, -200);
	(new Box())->SetPosition(rand() % 1400 + 700, -200);
	(new Box())->SetPosition(rand() % 1400 + 700, -200);
	(new Box())->SetPosition(rand() % 1400 + 700, -200);
}

static void Level1()
{
	new BackGround;
	new PlayerClass;
}

static void CallFunc() {
	CallBack.push_back(Level0);
	CallBack.push_back(Level1);
}
static vector<void(*)()>* GetCallBackVector() { return &CallBack; }