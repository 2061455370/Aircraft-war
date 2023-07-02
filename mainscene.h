#pragma once
#include"Library.h"
#include "soundManager.h"

struct mainScene {
	struct scene super;
	hero* hero;
	background* bk;
	vector vecElements;
	vector vecBullets;
	int bulletGenCnt;
	vector vecEnemy;
	int mark;
	soundManager enemyDownSoundMgr;
	int soundCloseCnt;
};

void mainSceneInit(struct mainScene* s);
void mainSceneDestroy(struct mainScene* s);
void mainSceneDraw(struct mainScene* s);
void mainSceneUpDate(struct mainScene* s);
void mainSceneControl(struct mainScene* s, ExMessage* msg);
bool mainSceneIsQuit(struct mainScene* s);