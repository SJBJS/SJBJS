#pragma once

#include"BackGround.h"
#include"PlayerClass.h"
#include"Bullet.h"
#include"Box.h"
#include"Ground.h"
#include"GameScene\GameStart.h"
#include"GameScene\GameOver.h"
#include <cstdlib>
#include <ctime>
using namespace std;

static vector<void(*)()> CallBack;

static void Level0()
{
	new GameStart();
}

static void Level1()
{
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

	int i = rand() % 1400 + 700;

	Ground *m_ground = new Ground();
	LeftGround *m_leftground = new LeftGround();
	RightGround *m_rightground = new RightGround();

	m_ground->SetPosition(i, 50);
	m_leftground->SetPosition(i, 50);
	m_rightground->SetPosition(i, 50);
	
	m_ground->SetLeftRight(m_leftground, m_rightground);

}
static void Level2()
{
	new GameOver();
}

static void CallFunc() {
	CallBack.push_back(Level0);
	CallBack.push_back(Level1);
	CallBack.push_back(Level2);
}
static vector<void(*)()>* GetCallBackVector() { return &CallBack; }