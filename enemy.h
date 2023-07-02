#pragma once

#include"sprite.h"
#include<easyx.h>

enum enemyType {
	enemyType0,
	enemyType1,
	enemyType2
};

enum enemyStatus {
	enemy_normal,
	enemy_down0,
	enemy_down1,
	enemy_down2,
	enemy_down3,
	enemy_down4,
	enemy_down5,
	enemy_destroy
};

struct enemy {
	struct sprite super;

	void (*hited)(struct enemy*);
	void (*destroy)(struct enemy*);

	IMAGE** imgArrEnemy;
	IMAGE** imgArrEnemyMask;
	enum enemyType enemyType;

	int v;
	int life;
	int enemyDownCnt;
	int status;
	int lastStatusBeforeDestroy;
};

void enemyInit(struct enemy);

//µÐ»ú1
struct enemy0 {
	struct enemy super;
};

void enemy0Init(struct enemy0*);
void enemy0Destroy(struct enemy0* e);

//µÐ»ú2
struct enemy1 {
	struct enemy super;
};

void enemy1Init(struct enemy1*);
void enemy1Destroy(struct enemy1* e);

//µÐ»ú3
struct enemy2 {
	struct enemy super;
};

void enemy2Init(struct enemy2*);
void enemy2Destroy(struct enemy2* e);