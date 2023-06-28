#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <poll.h>
#include <unistd.h>
#include <stdarg.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include "include/macro.h"
#include "include/struct.h"
#include "include/usual.h"

// efface tout le terminal visible
void clear_all() {
    printf("\033[0;0H\033[J");
}

//efface une partie du terminal
void clear_part(int line, int column) {
    printf("\033[%d;%dH\033[J", line, column); // code ANSI pour déplacer le curseur puis efface
}

//déplace le curseur dans la direction et la valeur indiquée
// A: up, B: down, C: forward, D: backward
void cursor_move(char direction, int num) {
    printf("\033[%d%c", num, direction);
}

/* 0: success -1: error */
int setBlockingFD(int fileDescriptor, int blocking) {
    int r = fcntl(fileDescriptor, F_GETFL);
    if (r == -1) {
        perror("fcntl(F_GETFL)");
        return -1;
    }
    int flags = (blocking ? r & ~O_NONBLOCK : r | O_NONBLOCK);
    r = fcntl(fileDescriptor, F_SETFL, flags);
    if (r == -1) {
        perror("fcntl(F_SETFL)");
        return -1;
    }
    return 0;
}

void discardInput(void) {
    setBlockingFD(STDIN_FILENO, 0);
    for (;;) {
        int c = fgetc(stdin);
        if (c == EOF) {
            if (errno == EAGAIN) {
                //vide
            }
            break;
        } else {
            //pas vide
        }
    }
    setBlockingFD(STDIN_FILENO, 1);
}

// retourne un simple int d'un seul caractère, utile pour les cas de choix pour par exemple de 1 à 5, moins
// d'utilisations de ressources qu'un scanf
int getint() {
    return (getchar() - '0'); // ascii du chiffre transformé en le chiffre lui meme en lui enlevant le code de 0
}

// permet d'écrire un "commentaire" d'une couleur differente et de remettre à la bonne couleur pour la suite
// exemple : appuyez sur entrée pour continuer
void commentary(char tab[]) { // tab est la chaine de caractère désiré en commentaire
    printf("%s%s%s\n", "\033[90m", tab, C_WHT); // le premier %s met la couleur en gris et le 3e la remet en blanc
}

// permet de faire un "entrer pour continuer", "presser une touche pour continuer"
void waiting() {
    commentary("(Appuyez sur Entrée pour continuer..)");
    getchar();
    discardInput();
}

//crée un background noir pour éviter les problemes de terminal pas noir car on utiliser des couleurs spécifiques
void background(int i, int j) {
    for (int k = 0; k < i; k++) {
        for (int l = 0; l < j; l++) {
            printf("%s ", B_BLK);
        }
        printf("\n");
    }
    cursor_move('A', 10);
    clear_all();
}


//Vérifie si l'index spécifié est valide pour être recherché dans un tableau. Renvoie 1 si hors du tableau, 0 sinon.
int CheckIndexOutOfArray(int i, int arraySize) {
    return (i < 0 || i >= arraySize);
}

//récupère le temps depuis le 1er janvier 1970 à 00:00:00 UTC
long get_time() {
    return time(NULL);
}

//compare le temps entre t1 et t2 pour retourner combien de temps est passé entre les deux
int compare_time(long t1, long t2) {
    return (int) (t2 - t1);
}

//transforme le nombre de secondes en heure minute seconde et le print
void format_time(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int remaining_seconds = (seconds % 3600) % 60;

    printf("%d heures, %d minutes et %d secondes\n", hours, minutes, remaining_seconds);
}

void draw_sprite(Screen *screen, int x, int y, char *sprite,int color_pair) { //coordinates of the center of the sprite (the body)
    char *part = malloc(6);
    int part_x = x - 2;
    int part_y = y - 1;
    int j = 0;
    //int size = strlen(sprite);
    for (int i = 0; i < 21; i++) {
        if (sprite[i] == ' ') {
            drawText(screen, part_x, part_y, part, color_pair);
            part_x += j+1;
            if (j > 0) {
                for (int k = 0; k < j; k++) {
                    part[k] = 0;
                }
                j = 0;
            }
        } else if (sprite[i] == '\n') {
            drawText(screen, part_x, part_y, part, color_pair);
            part_x = x - 2;
            part_y++;
            if (j > 0) {
                for (int k = 0; k < j; k++) {
                    part[k] = 0;
                }
                j = 0;
            }
        } else {
            part[j] = sprite[i];
            j++;
        }
    }

}


