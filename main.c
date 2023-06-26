#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"
#include "usual.h"
#include "include/struct.h"
#include "struct.h"
#include "external/rgr/inc/libGameRGR2.h"
#include "game.h"



void init(void* pUserData, Screen* pScreen){
    Data* d = pUserData;
    d->screen = pScreen;

    //init colors
    init_pair(8, COLOR_RED, COLOR_BLACK);
    init_pair(9, COLOR_YELLOW, COLOR_BLACK);


    //init players :
    //player 1
    d->p1.id = 1;
    d->p1.pv = 10;
    d->p1.x=20;
    d->p1.init_parade_time = 1;
    d->p1.parade_time = d->p1.init_parade_time;

    //player 2
    d->p2.id=2;
    d->p2.pv=10;
    d->p2.x=40;

    //init cursor
    d->cursor.x=10;
    d->cursor.y=10;





    setColorPair(9, COLOR_CYAN, COLOR_MAGENTA);
}

void event(void* pUserData, Screen* pScreen, Event* pEvt){
    Data* d = pUserData;
    switch(pEvt->code){
        // player one
        case 'q':
            if (d->p1.x > 10) {
                d->p1.x--;
            }
            break;
        case 'd':
            if (d->p2.x-d->p1.x >2) {
                d->p1.x++;
            }
            break;
        case 's':
            if (d->p1.posture == BASE) {
            d->p1.posture = PARADE;
            }
            break;

    }


}

int update(void* pUserData, Screen* pScreen, unsigned long deltaTime){
    Data* d = pUserData;
    //player 1
    if (d->p1.posture == PARADE){
        d->p1.parade_time -= ((double)deltaTime)/1000000,0;
    }
    if (d->p1.parade_time <=0){
        d->p1.posture = BASE;
        d->p1.parade_time = d->p1.init_parade_time;
    }

    return 0;
}


void draw(void* pUserData, Screen* pScreen){
    Data* d = pUserData;
    clear();
    switch (d->p1.posture) {
        case BASE:
            draw_sprite(d->screen,d->p1.x, 10, " o \n/|\\\n/ \\\n",8);
            break;
        case PARADE:
            draw_sprite(d->screen,d->p1.x, 10, " o \n/|\\|\n/ \\\n",8);
            break;
        case ATTACK_F1:
            break;
        case ATTACK_F2:
            break;
    }

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
