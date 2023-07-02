#include "Library.h"
#include"menuScene.h"

int main() {
	initgraph(LEIGHT, HEIGHT);
	setbkcolor(WHITE);
	cleardevice();

	while (1) {
		menuScene menuScene;
		menuSceneInit(&menuScene);
		gameLoop((scene*)&menuScene, 60);
		menuSceneDestroy(&menuScene);


		mainScene ms;
		mainSceneInit(&ms);
		gameLoop((struct scene*)&ms, FPS);
		mainSceneDestroy(&ms);

		settextcolor(WHITE);
		settextstyle(60, 0, "΢���ź�");

		const char* pStr = "��Ϸ����";
		RECT r = { 0,200,422,300 };
		drawtext(pStr, &r, DT_CENTER);

		char buff[10];
		sprintf(buff, "�÷֣�%d", ms.mark);
		r = { 0,300,422,400 };
		drawtext(buff, &r, DT_CENTER);

		Sleep(3000);
	}

	closegraph();
	return 0;
}