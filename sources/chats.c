//
//  chats.c
//  gare_aux_chats
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "../headers/main.h"

int ajout_chat_possible(int **monde) {
    if (((monde[0][0] != CHAT) && (monde[0][0] != NX_CHAT)) ||
        ((monde[0][WIDTH-1] != CHAT) && (monde[0][WIDTH-1] != NX_CHAT)) ||
        ((monde[HEIGHT-1][0] != CHAT) && (monde[HEIGHT-1][0] != NX_CHAT)) ||
        ((monde[HEIGHT-1][WIDTH-1] != CHAT) && (monde[HEIGHT-1][WIDTH-1] != NX_CHAT))){
        return TRUE;
    } else {
        return FALSE;
    }
}

void random_ajout_chat(int ***monde) {
    int x, y;

    if (ajout_chat_possible(*monde) == TRUE) {
        do {
            x = 0 + (rand() % 2);
            y = 0 + (rand() % 2);
        } while ((*(*(*monde + x)+y) == CHAT) || (*(*(*monde + x)+y) == NX_CHAT));

        *(*(*monde + (x*(HEIGHT-1))) + (y*(WIDTH-1))) = CHAT;
    }
}

int* cases_valides_chat(int x, int y, int **monde) { // 0 14 j i
    int* tab = (int*) calloc(5, sizeof(int)); // intialisation a 0 a FALSE

    tab[SPOT-1] = TRUE;

    // Gauche
    if (x-1 >= 0) {
        if ((monde[y][x-1] != CHAT) && (monde[y][x-1] != NX_CHAT)) {
            tab[LEFT-1] = TRUE;
        }
    }


    // Droite
    if (x+1 <= WIDTH-1) {
        if ((monde[y][x+1] != CHAT) && (monde[y][x+1] != NX_CHAT)){
            tab[RIGHT-1] = TRUE;
        }
    }

    // Haut
    if (y-1 >= 0) {
        if ((monde[y-1][x] != CHAT) && (monde[y-1][x] != NX_CHAT)) {
            tab[UP-1] = TRUE;
        }
    }

    // Bas
    if (y+1 <= HEIGHT-1) {
        if ((monde[y+1][x] != CHAT) && (monde[y+1][x] != NX_CHAT)) {
            tab[DOWN-1] = TRUE;
        }
    }

    return tab;
}


void deplacement_chats(int ***monde) {
    int* tab;
    int position;

    for(int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if(*(*(*monde + i)+j) == CHAT) {

                // Recuperation de la case aleatoire
                tab = cases_valides_chat(j, i, *monde);


                do {
                    position = 1 + (rand() % 5);
                } while (tab[position-1] == FALSE);

                free(tab);



                // Changement de la case
                if(position == RIGHT) {
                    *(*(*monde + i)+j) = CASE_VIDE;
                    *(*(*monde + i)+(j+1)) = NX_CHAT;
                } else if(position == LEFT){
                    *(*(*monde + i)+j) = CASE_VIDE;
                    *(*(*monde + i)+(j-1)) = NX_CHAT;
                } else if(position == UP) {
                    *(*(*monde + i)+j) = CASE_VIDE;
                    *(*(*monde + (i-1))+j) = NX_CHAT;
                } else if(position == DOWN) {
                    *(*(*monde + i)+j) = CASE_VIDE;
                    *(*(*monde + (i+1))+j) = NX_CHAT;
                }

            }
        }
    }
}


void reabilitation_valeur_chat(int ***monde) {
    int i,j;
    
    for(i=0; i<WIDTH; i++) {
        for(j=0; j<HEIGHT; j++) {
            if(*(*(*monde + i)+j) == NX_CHAT) {
                *(*(*monde + i)+j) = CHAT;
            }
        }
    }
}
