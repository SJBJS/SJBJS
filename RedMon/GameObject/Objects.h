#pragma once

#include"BackGround.h"
#include"PlayerClass.h"
#include"Bullet.h"
#include"Box.h"
#include <cstdlib>
#include <ctime>
using namespace std;
void CreatObject()
{ /* z값이 같을 경우 맨 마지막에 동적할당한 객체가 제일 앞에 그려집니다. */
	srand((unsigned int)time(NULL));
	
	new BackGround();
	new PlayerClass();
	(new Box())->SetPosition((rand()%500)+1,-200);
	(new Box())->SetPosition(rand() % 700 - 250, -200);
	(new Box())->SetPosition(rand() % 700 - 250, -200);
	(new Box())->SetPosition(rand() % 700 - 250, -200);
	(new Box())->SetPosition(rand() % 700 - 250, -200);
	(new Box())->SetPosition(rand() % 700 - 250, -200);
	(new Box())->SetPosition(rand() % 700 - 250, -200);
	(new Box())->SetPosition(rand() % 700 - 250, -200);
}