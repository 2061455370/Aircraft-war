#include"Library.h"

//»æÖÆ±³¾°
void backgrounDraw(struct background* b) {
	putimage(0, b->yA, b->imgBackground);
	putimage(0, b->yB, b->imgBackground);
}

//ÒÆ¶¯±³¾°
void backgroundUpdate(struct background* b) {
	b->yA = b->yA + 1;
	b->yB = b->yB + 1;
	if (b->yA >= 0) {
		b->yA = -750;
		b->yB = 0;
	}
}

void backgroundInit(struct background* b) {
	b->super.draw = (void(*)(struct sprite*))backgrounDraw;
	b->super.undate= (void(*)(struct sprite*))backgroundUpdate;
	b->yA = -750;
	b->yB = 0;
	b->imgBackground = new IMAGE;
	loadimage(b->imgBackground, "asset/img/bg.png");
}



void backgroundDestroy(struct background* b) {
	delete b->imgBackground;
}