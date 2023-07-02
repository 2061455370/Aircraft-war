#pragma once


;
struct background {
	struct sprite super;
	int yA;
	int yB;
	IMAGE* imgBackground;
};

void backgrounDraw(struct background* b);
void backgroundUpdate(struct background* b);
void backgroundInit(struct background* b);
void backgroundDestroy(struct background* b);