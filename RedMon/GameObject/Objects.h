#pragma once

#include"BackGround.h"
#include"PlayerClass.h"
#include"Bullet.h"
#include"Box.h"
#include <cstdlib>
#include <ctime>
using namespace std;
void CreatObject()
{ /* z���� ���� ��� �� �������� �����Ҵ��� ��ü�� ���� �տ� �׷����ϴ�. */
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