#include "Library.h"

//记录从正常到消灭的顺序
enum heroStatus heroStatusSquence[7] = {
	hero_nomal0,
	hero_nomal1,
	hero_down0,
	hero_down1,
	hero_down2,
	hero_down3,
	hero_destroy
};

//初始化英雄
void heroInit(struct hero* h) {
	h->super.draw = (void(*)(struct sprite*))heroDraw;
	h->super.undate = (void(*)(struct sprite*))heroUpDate;
	h->heroUpDateCnt = 0;
	h->status = hero_nomal0;
	h->life = LIFE;
	h->super.x = HEROINITX;
	h->super.y = HEROINITY;

	for (int i = 0; i < 6; i++) {
		h->imgArrHero[i] = new IMAGE;
		h->imgArrHeroMask[i] = new IMAGE;
	}

	char imgPath[50];
	char imgMaskPath[50];
	for (int i = 0; i < 2; i++) {
		sprintf(imgPath, "asset/img/hero/hero%d.png", i);
		sprintf(imgMaskPath, "asset/img/hero/hero%d_mask.png", i);
		loadimage(h->imgArrHero[i], imgPath);
		loadimage(h->imgArrHeroMask[i], imgMaskPath);
	}
	for (int i = 0; i < 4; i++) {
		sprintf(imgPath, "asset/img/hero/hero_down%d.png", i);
		sprintf(imgMaskPath, "asset/img/hero/hero_down%d_mask.png", i);
		loadimage(h->imgArrHero[i+2], imgPath);
		loadimage(h->imgArrHeroMask[i+2], imgMaskPath);
	}
}

//绘制飞机
void heroDraw(struct hero* h) {
	putTransparetImage(h->super.x, h->super.y, h->imgArrHeroMask[h->status], h->imgArrHero[h->status]);
}

//更新飞机数据
void heroUpDate(struct hero* h) {
	h->heroUpDateCnt++;
	if (h->heroUpDateCnt >= 15) {
		h->heroUpDateCnt = 0;
		if (h->life != 0) {
			if (h->status == hero_nomal0)
				h->status = hero_nomal1;
			else if (h->status == hero_nomal1)
				h->status = hero_nomal0;
		}
		else {
			if (h->status < hero_destroy)
				h->status = heroStatusSquence[h->status + 1];
		}
	}
}

//销毁飞机
void heroDestroy(struct hero* h) {
	for (int i = 0; i < 6; i++) {
		delete h->imgArrHero[i];
		delete h->imgArrHeroMask[i];
	}
}