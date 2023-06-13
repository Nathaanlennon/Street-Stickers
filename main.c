#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"
#include "usual.h"
#include "struct.h"
#include "external/rgr/inc/libGameRGR2.h"
#include "game.h"

//change de scène quand appelé
void scene_changer(Data *data, Scene scene){
    data->scene_type = scene;
}

void init(void* pUserData, Screen* pScreen){
    Data* d = pUserData;
    d->screen = pScreen;


    setColorPair(9, COLOR_CYAN, COLOR_MAGENTA);
}

void event(void* pUserData, Screen* pScreen, Event* pEvt){
    Data* d = pUserData;


}

int update(void* pUserData, Screen* pScreen, unsigned long deltaTime){

    return 0;
}


void draw(void* pUserData, Screen* pScreen){
    Data* d = pUserData;
}

void finish(void* pUserData){
}



int main() {
    Data d;
    Callbacks cb;
    cb.cbDraw = &draw;
    cb.cbEvent = &event;
    cb.cbUpdate = &update;
    cb.cbInit = &init;
    cb.cbFinish = &finish;

    GameData *game = createGame(50,50, &d, &cb, 0);
    gameLoop(game);
    return 0;
}
