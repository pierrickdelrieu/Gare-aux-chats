//
//  joueur.c
//  zombies
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//


#include "fonctions.h"


int case_valide_joueur(int i, int j, int **plateau)
{
    // 1 si plateau[i][j] valide et 0 sinon

    int valide = 0;

    if((i<HEIGHT) && (j<WIDHT) && (i>0) && (j>0))
    {
        valide = 1;
    }

    if((valide == 1) && (plateau[i][j] == CASE_VIDE))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void position_joueur(int **monde, int joueur, int position[2])
{
    int i, j;
    
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDHT; j++)
        {
            if(monde[i][j] == joueur)
            {
                position[0] = i;
                position[1] = j;
            }
        }
    }
}

void deplacement_joueur(int ***monde, int joueur, int position [2], int mouvement)
{
    if((case_valide_joueur(position[0], position[1] + 1, *monde) == 1) && (mouvement == RIGHT))
    {
        *(*(*monde + position[0])+position[1]) = CASE_VIDE;
        *(*(*monde + position[0])+(position[1] + 1)) = joueur;
    }
    else if((case_valide_joueur(position[0], position[1] - 1, *monde) == 1) && (mouvement == LEFT))
    {
        *(*(*monde + position[0])+position[1]) = CASE_VIDE;
        *(*(*monde + position[0])+(position[1] - 1)) = joueur;
    }
    else if((case_valide_joueur(position[0] - 1, position[1], *monde) == 1) && (mouvement == UP))
    {
        *(*(*monde + position[0])+position[1]) = CASE_VIDE;
        *(*(*monde + (position[0] - 1))+position[1]) = joueur;
    }
    else if((case_valide_joueur(position[0] + 1, position[1], *monde) == 1) && (mouvement == DOWN))
    {
        *(*(*monde + position[0])+position[1]) = CASE_VIDE;
        *(*(*monde + (position[0] + 1))+position[1]) = joueur;
    }
}


int condition_vie_joueur(int ***monde, int joueur, int position_joueur[2])
{
//    1 si le joueur doit continuer et 0 sinon
    if(*(*(*monde + position_joueur[0])+position_joueur[1]) != joueur)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
