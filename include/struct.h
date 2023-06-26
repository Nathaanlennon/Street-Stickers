//
// Created by cacac on 12/05/2023.
//

#ifndef STREET_STICKERS_STRUCT_H
#define STREET_STICKERS_STRUCT_H

#include <stdio.h>
#include "../external/rgr/inc/libGameRGR2.h"

enum sprite{
    BASE, PARADE, ATTACK_F1, ATTACK_F2
};

typedef struct {
    short colors_pair[20][2];
    int color_num;
}Colors;

typedef struct {
    int x;
    int y;
    short color;
    short background;
} Cursor;
typedef struct {
    int id;
    int pv;
    enum sprite posture; //(0 base ; 1 parade ; 2 attack f1 ; 3 attack f2)
    int x;
    int init_parade_time;
    double parade_time;
}Player;
typedef struct Data {
    Screen *screen;
    Cursor cursor;
    Player p1;
    Player p2;


} Data;
#endif //STREET_STICKERS_STRUCT_H


