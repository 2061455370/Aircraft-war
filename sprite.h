#pragma once

struct sprite{
	void (*draw)(sprite*);
	void (*undate)(sprite*);
	int x;
	int y;
	int width;
	int height;
};