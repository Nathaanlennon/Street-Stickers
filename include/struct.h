//
// Created by cacac on 12/05/2023.
//

#ifndef STREET_STICKERS_H
#define STREET_STICKERS_H

#include <stdio.h>
#include "../external/rgr/inc/libGameRGR2.h"


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
typedef struct Data {
    Screen *screen;

} Data;
#endif //STREET_STICKERS_H


