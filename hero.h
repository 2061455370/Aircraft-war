#pragma once

#include "sprite.h"

enum heroStatus {
	hero_nomal0,
	hero_nomal1,
	hero_down0,
	hero_down1,
	hero_down2,
	hero_down3,
	hero_destroy
};


struct hero {
	struct sprite super;
	IMAGE* imgArrHero[6];
	IMAGE* imgArrHeroMask[6];
	enum heroStatus status;
	int life;
	int heroUpDateCnt;
};

void heroInit(struct hero* h);
void heroDraw(struct hero* h);
void heroUpDate(struct hero* h);
void heroDestroy(struct hero* h);