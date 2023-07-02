#pragma once
#include "vector.h"

struct soundManager {
	void (*play)(struct soundManager*);
	void (*close)(struct soundManager* e,int interval);
	vector vecSoundAlias;
	char soundPath[100];
};

void soundManagerInit(struct soundManager* e, const char* soundPath);
void soundManagerDestroy(struct soundManager* e);