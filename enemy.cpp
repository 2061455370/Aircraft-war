#include"Library.h"
#include "enemy.h"
#include "img.h"
#include <stdio.h>

static enum enemyStatus enemyStatusSquence[8] = {
	enemy_normal,
	enemy_down0,
	enemy_down1,
	enemy_down2,
	enemy_down3,
	enemy_down4,
	enemy_down5,
	enemy_destroy
};

void enemyDraw(struct enemy* e) {
	IMAGE* imgEnemy = e->imgArrEnemy[e->status];
	IMAGE* imgEnemyMask = e->imgArrEnemyMask[e->status];
	putTransparetImage(e->super.x, e->super.y, imgEnemyMask, imgEnemy);
}

void enemyUpdate(struct enemy* e) {
	e->super.y += e->v;
	if (e->life == 0) {
		e->enemyDownCnt++;
		if (e->enemyDownCnt >= 15) {
			e->enemyDownCnt = 0;
			if (e->status < e->lastStatusBeforeDestroy) {
				e->status = enemyStatusSquence[e->status + 1];
			}
			else {
				e->status = enemy_destroy;
			}
		}
	}
}

void enemyHited(struct enemy* e) {
	e->life--;
	if (e->life == 0) {
		e->status = enemy_down0;
	}
}

void enemyInit(struct enemy* e) {
	e->super.draw = (void(*)(struct sprite*))enemyDraw;
	e->super.undate = (void(*)(struct sprite*))enemyUpdate;
	e->hited = (void(*)(struct enemy*))enemyHited;

	e->enemyDownCnt = 0;
	e->status = enemy_normal;

	int m = 1;
	int n = 3;
	e->v = rand() % (n - m + 1) + m;
}

//µÐ»ú1
void enemy0Init(struct enemy0* e) {
	enemyInit((struct enemy*)e);
	e->super.destroy = (void(*)(struct enemy*))enemy0Destroy;

	e->super.super.width = 34;
	e->super.super.height = 26;
	e->super.enemyType = enemyType0;
	e->super.life = 1;
	e->super.lastStatusBeforeDestroy = enemy_down3;

	e->super.imgArrEnemy = (IMAGE**)malloc(sizeof(IMAGE*) * 5);
	e->super.imgArrEnemyMask = (IMAGE**)malloc(sizeof(IMAGE*) * 5);

	for (int i = 0; i < 5; i++) {
		e->super.imgArrEnemy[i] = new IMAGE;
		e->super.imgArrEnemyMask[i] = new IMAGE;
	}
	loadimage(e->super.imgArrEnemy[0], "asset/img/enemy0/enemy0.png");
	loadimage(e->super.imgArrEnemyMask[0], "asset/img/enemy0/enemy0_mask.png");

	char imgPuth[50];
	char imgPuthMask[50];
	for (int i = 0; i < 4; i++) {
		sprintf(imgPuth, "asset/img/enemy0/enemy0_down%d.png", i);
		sprintf(imgPuthMask, "asset/img/enemy0/enemy0_down%d_mask.png", i);
		loadimage(e->super.imgArrEnemy[i + 1], imgPuth);
		loadimage(e->super.imgArrEnemyMask[i + 1], imgPuthMask);
	}
}

void enemy0Destroy(struct enemy0* e) {
	for (int i = 0; i < 5; i++) {
		delete e->super.imgArrEnemy[i];
		delete e->super.imgArrEnemyMask[i];
	}
	free(e->super.imgArrEnemy);
	free(e->super.imgArrEnemyMask);
}

//µÐ»ú2

void enemy1Init(struct enemy1* e) {
	enemyInit((struct enemy*)e);
	e->super.destroy = (void(*)(struct enemy*))enemy1Destroy;

	e->super.super.width = 46;
	e->super.super.height = 59;
	e->super.enemyType = enemyType1;
	e->super.life = 3;
	e->super.lastStatusBeforeDestroy = enemy_down3;

	e->super.imgArrEnemy = (IMAGE**)malloc(sizeof(IMAGE*) * 5);
	e->super.imgArrEnemyMask = (IMAGE**)malloc(sizeof(IMAGE*) * 5);

	for (int i = 0; i < 5; i++) {
		e->super.imgArrEnemy[i] = new IMAGE;
		e->super.imgArrEnemyMask[i] = new IMAGE;
	}
	loadimage(e->super.imgArrEnemy[0], "asset/img/enemy1/enemy1.png");
	loadimage(e->super.imgArrEnemyMask[0], "asset/img/enemy1/enemy1_mask.png");

	char imgPuth[50];
	char imgPuthMask[50];
	for (int i = 0; i < 4; i++) {
		sprintf(imgPuth, "asset/img/enemy1/enemy1_down%d.png", i);
		sprintf(imgPuthMask, "asset/img/enemy1/enemy1_down%d_mask.png", i);
		loadimage(e->super.imgArrEnemy[i+1], imgPuth);
		loadimage(e->super.imgArrEnemyMask[i+1], imgPuthMask);
	}
}

void enemy1Destroy(struct enemy1* e) {
	for (int i = 0; i < 5; i++) {
		delete e->super.imgArrEnemy[i];
		delete e->super.imgArrEnemyMask[i];
	}
	free(e->super.imgArrEnemy);
	free(e->super.imgArrEnemyMask);
}

//µÐ»ú3
void enemy2Init(struct enemy2* e) {
	enemyInit((struct enemy*)e);
	e->super.destroy = (void(*)(struct enemy*))enemy2Destroy;

	e->super.super.width = 109;
	e->super.super.height = 162;
	e->super.enemyType = enemyType2;
	e->super.life = 5;
	e->super.lastStatusBeforeDestroy = enemy_down5;

	e->super.imgArrEnemy = (IMAGE**)malloc(sizeof(IMAGE*) * 7);
	e->super.imgArrEnemyMask = (IMAGE**)malloc(sizeof(IMAGE*) * 7);

	for (int i = 0; i < 7; i++) {
		e->super.imgArrEnemy[i] = new IMAGE;
		e->super.imgArrEnemyMask[i] = new IMAGE;
	}
	loadimage(e->super.imgArrEnemy[0], "asset/img/enemy2/enemy2.png");
	loadimage(e->super.imgArrEnemyMask[0], "asset/img/enemy2/enemy2_mask.png");


	char imgPuth[50];
	char imgPuthMask[50];
	for (int i = 0; i < 6; i++) {
		sprintf(imgPuth, "asset/img/enemy2/enemy2_down%d.png", i);
		sprintf(imgPuthMask, "asset/img/enemy2/enemy2_down%d_mask.png", i);
		loadimage(e->super.imgArrEnemy[i + 1], imgPuth);
		loadimage(e->super.imgArrEnemyMask[i + 1], imgPuthMask);
	}
}

void enemy2Destroy(struct enemy2* e) {
	for (int i = 0; i < 7; i++) {
		delete e->super.imgArrEnemy[i];
		delete e->super.imgArrEnemyMask[i];
	}
	free(e->super.imgArrEnemy);
	free(e->super.imgArrEnemyMask);
}