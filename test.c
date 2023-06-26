#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"
#include "usual.h"
#include "include/struct.h"
#include "struct.h"
#include "external/rgr/inc/libGameRGR2.h"
#include "game.h"

void test(char* sprite){
    int y = 5;
    int part_y = 4;
    char part[4];
    for (int i=0;i<12;i++){
        if (sprite[i] == '\n'){
            printf("%s", part);
            part_y++;
        }
        else{
            part[i-(part_y-y+1)*3] = sprite[i];
        }
    }
}

int main(){
    test(" o \n/|\\\n/ \\");
}