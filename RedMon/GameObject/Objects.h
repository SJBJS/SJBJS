#pragma once

#include"BackGround.h"
#include"PlayerClass.h"
#include"Bullet.h"

void CreatObject()
{ /* z값이 같을 경우 맨 마지막에 동적할당한 객체가 제일 앞에 그려집니다. */
	new BackGround();
	new PlayerClass();
}