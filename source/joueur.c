//
//  joueur.c
//  zombies
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//


#include "fonctions.h"

void position_initial_joueur(int ***monde)
{
    int position_joueur1[2] = {8,8};
    int position_joueur2[2] = {2,6};
    int position_joueur3[2] = {6,3};
    int position_joueur4[2] = {9,7};
    int position_joueur5[2] = {11,2};
    
    
    *(*(*monde + position_joueur1[0])+position_joueur1[1]) = JOUEUR1;
    *(*(*monde + position_joueur2[0])+position_joueur2[1]) = JOUEUR2;
    *(*(*monde + position_joueur3[0])+position_joueur3[1]) = JOUEUR3;
    *(*(*monde + position_joueur4[0])+position_joueur4[1]) = JOUEUR4;
    *(*(*monde + position_joueur5[0])+position_joueur5[1]) = JOUEUR5;
}

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
