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
{ /* z값이 같을 경우 맨 마지막에 동적할당한 객체가 제일 앞에 그려집니다. */
	srand((unsigned int)time(NULL));

	new BackGround();
	new PlayerClass();
	//(new Box())->SetPosition((rand() % 500) + 1, -210);
	//(new Box())->SetPosition(rand() % 1400 + 700, -150);
	//(new Box())->SetPosition(rand() % 1400 + 700, -150);
	(new Box())->SetPosition(rand() % 1400 + 700, -150);
	(new Box())->SetPosition(rand() % 1400 + 700, -150);
	
	(new HPbar())->SetPosition(-500, 300);
	(new HPbar())->SetPosition(-550, 300);
	(new HPbar())->SetPosition(-600, 300);
	(new Box())->SetPosition(rand() % 1400 + 700, -150);
	(new Sharpbox())->SetPosition(rand() % 1400 + 700, -200);
	(new Sharpbox())->SetPosition(rand() % 1400 + 700, -200);
}

static void Level1()
{
	new BackGround;
	new PlayerClass;
}
static void Level2()
{
	new PlayerClass;
}

static void CallFunc() {
	CallBack.push_back(Level0);
	CallBack.push_back(Level1);
	CallBack.push_back(Level2);
}
static vector<void(*)()>* GetCallBackVector() { return &CallBack; }