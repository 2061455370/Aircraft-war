#include "Library.h"

void putTransparetImage(int x, int y, const IMAGE* mask, const IMAGE* img) {
	putimage(x, y, mask, SRCAND);
	putimage(x, y, img, SRCPAINT);
}
