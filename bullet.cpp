#include "bullet.h"
#include "img.h"

void bulletDraw(struct bullet* b) {
	putTransparetImage(b->super.x, b->super.y, b->imgBulletMask, b->imgBullet);
}

void bulletUpdate(struct bullet* b) {
	b->super.y -= 8;
}

void bulletInit(struct bullet* b) {
	b->super.draw = (void(*)(struct sprite*))bulletDraw;
	b->super.undate = (void(*)(struct sprite*))bulletUpdate;

	b->imgBullet = new IMAGE;
	b->imgBulletMask = new IMAGE;
	loadimage(b->imgBullet, "asset/img/bullet/bullet.png");
	loadimage(b->imgBulletMask, "asset/img/bullet/bullet_mask.png");
}

void bulletDestroy(struct bullet* b) {
	delete b->imgBullet;
	delete b->imgBulletMask;
}