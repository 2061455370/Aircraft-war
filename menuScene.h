#pragma once
#include "scene.h"

struct menuScene {
    struct scene super;
    IMAGE* bk;
    RECT rectStarGame, rectEndGame;
    bool isStartGameHover, isEndGameHover;
    bool isQuit;
};

void menuSceneInit(struct menuScene* s);
void menuSceneDestroy(struct menuScene* s);
