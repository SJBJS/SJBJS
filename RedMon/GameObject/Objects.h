#pragma once

#include"BackGround.h"
#include"PlayerClass.h"
#include"Bullet.h"
#include"Box.h"

void CreatObject()
{ /* z���� ���� ��� �� �������� �����Ҵ��� ��ü�� ���� �տ� �׷����ϴ�. */
	new BackGround();
	new PlayerClass();
	new Box();
}