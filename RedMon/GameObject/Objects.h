#pragma once

#include"BackGround.h"
#include"PlayerClass.h"
#include"Bullet.h"
#include"Box.h"

void CreatObject()
{ /* z���� ���� ��� �� �������� �����Ҵ��� ��ü�� ���� �տ� �׷����ϴ�. */
	new BackGround();
	new PlayerClass();
	(new Box())->SetPosition(100,0);
	(new Box())->SetPosition(50,50);
	(new Box())->SetPosition(0,100);
	(new Box())->SetPosition(-50,50);
	(new Box())->SetPosition(-100,0);
	(new Box())->SetPosition(-50,-50);
	(new Box())->SetPosition(0, -100);
	(new Box())->SetPosition(50, -50);
}