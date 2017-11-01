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

	
	(new HPbar())->SetPosition(-500, 300);
	(new HPbar())->SetPosition(-550, 300);
	(new HPbar())->SetPosition(-600, 300);


	(new Sharpbox())->SetPosition(rand() % 1400 + 800, -230);
	(new Sharpbox())->SetPosition(rand() % 1400 + 800, -230);
	(new Sharpbox())->SetPosition(rand() % 1400 + 800, -230);
	(new Sharpbox())->SetPosition(rand() % 1400 + 800, -230);
	(new Sharpbox())->SetPosition(rand() % 1400 + 800, -230);



	Ground *m_ground[3];
	LeftGround *m_leftground[3];
	RightGround *m_rightground[3];

	for (int i = 0; i < 3; i++) {

		m_ground[i] = new Ground();
		m_leftground[i] = new LeftGround();
		m_rightground[i] = new RightGround();

		m_ground[i]->SetPosition((i * 100) * 8, -300);
		m_leftground[i]->SetPosition((i * 100) * 8, -300);
		m_rightground[i]->SetPosition((i * 100) * 8, -300);

		m_ground[i]->SetLeftRight(m_leftground[i], m_rightground[i]);
	}

	StageFlag *m_flag = new StageFlag();
	m_flag->SetPosition(10000, -300);
	
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