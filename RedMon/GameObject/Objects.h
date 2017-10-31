#pragma once

#include"BackGround.h"
#include"PlayerClass.h"
#include"Bullet.h"
#include"Box.h"
#include"Ground.h"
#include"StageFlag.h"
#include"GameScene\GameStart.h"
#include"GameScene\GameOver.h"
#include"GameScene\GameStage.h"
#include"GameScene\Stage\Stage01.h"
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

	(new Box())->SetPosition((rand() % 500) + 1, -280);	
	(new Box())->SetPosition(rand() % 1400 + 700, -280);
	(new Box())->SetPosition(rand() % 1400 + 700, -280);
	(new Sharpbox())->SetPosition(rand() % 1400 + 700, -230);
	(new Sharpbox())->SetPosition(rand() % 1400 + 700, -230);
	
	(new HPbar())->SetPosition(-500, 300);
	(new HPbar())->SetPosition(-550, 300);
	(new HPbar())->SetPosition(-600, 300);

	int i = 0;

	Ground *m_ground = new Ground();
	LeftGround *m_leftground = new LeftGround();
	RightGround *m_rightground = new RightGround();

	m_ground->SetPosition(i, -230);
	m_leftground->SetPosition(i, -230);
	m_rightground->SetPosition(i, -230);
	
	m_ground->SetLeftRight(m_leftground, m_rightground);

	int j = 1100;

	Ground *ground = new Ground();
	LeftGround *leftground = new LeftGround();
	RightGround *rightground = new RightGround();

	ground->SetPosition(j, -230);
	leftground->SetPosition(j, -230);
	rightground->SetPosition(j, -230);

	ground->SetLeftRight(leftground, rightground);

	StageFlag *m_flag = new StageFlag();
	m_flag->SetPosition(5000, -200);
	
}
static void Level2()
{
	new GameOver();
}


static void Level3()
{


}


static void CallFunc() {

	CallBack.push_back(Level0);
	CallBack.push_back(Level1);
	CallBack.push_back(Level2);
	CallBack.push_back(Level3);
}
static vector<void(*)()>* GetCallBackVector() { return &CallBack; }