//
// Created by cacac on 12/05/2023.
//

#ifndef STREET_STICKERS_USUAL_H
#define STREET_STICKERS_USUAL_H
#include <stdio.h>
#include "struct.h"
void clear_all();
void clear_part(int line, int column);
void cursor_move(char direction, int num);
int setBlockingFD(int fileDescriptor, int blocking);
void discardInput(void);
int getint();
void commentary(char tab[]);
void waiting();
void background(int i, int j);
int CheckIndexOutOfArray(int i, int arraySize);
long get_time();
int compare_time(long t1, long t2);
void format_time(int seconds);
void draw_sprite(Screen* screen, int x, int y, char* sprite, int color_pair);
#endif //STREET_STICKERS_USUAL_H
