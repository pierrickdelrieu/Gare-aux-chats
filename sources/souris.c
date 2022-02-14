//
//  souris.c
//  gare_aux_chats
//
//  Created by Pierrick Delrieu on 21/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "../headers/main.h"

/*Les fonctions des joueurs peuvent etre consitué de :
 - int case_valide_souris(int i, int j, int **monde);
 - RIGHT, LEFT, UP, DOWN, SPOT
 - CHAT
 - CASE_VIDE
 - SOURIS1, SOURIS2, SOURIS3, SOURIS4, SOURIS5
 - HEIGHT, WIDHT (les tailles du monde)
 
Si dans la fonction le joueur modifie le monde, la souris est automatiquement disqualifié.
*/

void position_initial_souris(int ***monde, int position_joueur1[2], int position_joueur2[2])
{
    position_joueur1[1] = WIDTH/2;
    position_joueur1[0] = HEIGHT/2;
    
    position_joueur2[1] = 2;
    position_joueur2[0] = 3;

    
    *(*(*monde + position_joueur1[1])+position_joueur1[0]) = SOURIS1;
    *(*(*monde + position_joueur2[1])+position_joueur2[0]) = SOURIS2;
}


int cases_valides_souris(int x, int y, int **monde) {

    if ((x >= 0) && (x <= WIDTH-1) &&
            (y >= 0) && (y <= HEIGHT-1)) {
        if (monde[y][x] == CASE_VIDE) {
            return TRUE;
        }
    }

    return FALSE;
}


void position_souris(int **monde, int souris, int position[2])
{
    int i, j;

    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            if(monde[i][j] == souris)
            {
                position[1] = i;
                position[0] = j;
            }
        }
    }
}

void deplacement_souris(int ***monde, int souris, int position[2], int mouvement) {
    if((cases_valides_souris(position[1], position[0] + 1, *monde) == TRUE) && (mouvement == RIGHT)) {
        *(*(*monde + position[1])+position[0]) = CASE_VIDE;
        *(*(*monde + position[1])+(position[0] + 1)) = souris;
    }
    else if((cases_valides_souris(position[1], position[0] - 1, *monde) == TRUE) && (mouvement == LEFT)) {
        *(*(*monde + position[1])+position[0]) = CASE_VIDE;
        *(*(*monde + position[1])+(position[0] - 1)) = souris;
    }
    else if((cases_valides_souris(position[1] - 1, position[0], *monde) == TRUE) && (mouvement == UP)) {
        *(*(*monde + position[1])+position[0]) = CASE_VIDE;
        *(*(*monde + (position[1] - 1))+position[0]) = souris;
    }
    else if((cases_valides_souris(position[1] + 1, position[0], *monde) == TRUE) && (mouvement == DOWN)) {
        *(*(*monde + position[1])+position[0]) = CASE_VIDE;
        *(*(*monde + (position[1] + 1))+position[0]) = souris;
    }
}


int condition_vie_souris(int ***monde, int souris, int position_joueur[2]) {
//    1 si le joueur doit continuer et 0 sinon
    if(*(*(*monde + position_joueur[1]) + position_joueur[0]) != souris) {
        return FALSE;
    } else {
        return TRUE;
    }
}
