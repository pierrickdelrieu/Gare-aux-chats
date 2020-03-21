//
//  player.c
//  zombies
//
//  Created by Pierrick Delrieu on 21/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"

/*Les fonctions des joueurs peuvent etre consitué de :
 - int case_valide_joueur(int i, int j, int **plateau);
 - RIGHT, LEFT, UP, DOWN, SPOT
 - ZOMBIE
 - CASE_VIDE
 - JOUEUR1, JOUEUR2, JOUEUR3, JOUEUR4, JOUEUR5
 - HEIGHT, WIDHT (les tailles de la map)
 
Si dans la fonction le joueur modifie la map, le joueur est disqualifié.
*/

void position_initial_joueur(int ***monde, int position_joueur1[2], int position_joueur2[2],int position_joueur3[2],int position_joueur4[2],int position_joueur5[2])
{
    position_joueur1[0] = 14;
    position_joueur1[1] = 2;
    
    position_joueur2[0] = 2;
    position_joueur2[1] = 3;
    
    position_joueur3[0] = 6;
    position_joueur3[1] = 3;
    
    position_joueur4[0] = 9;
    position_joueur4[1] = 7;
    
    position_joueur5[0] = 11;
    position_joueur5[1] = 2;
 
    
    
    *(*(*monde + position_joueur1[0])+position_joueur1[1]) = JOUEUR1;
    *(*(*monde + position_joueur2[0])+position_joueur2[1]) = JOUEUR2;
    *(*(*monde + position_joueur3[0])+position_joueur3[1]) = JOUEUR3;
    *(*(*monde + position_joueur4[0])+position_joueur4[1]) = JOUEUR4;
    *(*(*monde + position_joueur5[0])+position_joueur5[1]) = JOUEUR5;
}


int joueur1(int **monde)
{
    int mouvement = 1 + (rand() % 4);
    
    if(mouvement == 1)
    {
        return RIGHT;
    }
    else if(mouvement == 2)
    {
        return LEFT;
    }
    else if(mouvement == 3)
    {
        return UP;
    }
    else if(mouvement == 4)
    {
        return DOWN;
    }
    else
    {
        return SPOT;
    }
}

int joueur2(int **monde)
{
    int mouvement = 1 + (rand() % 4);
    
    if(mouvement == 1)
    {
        return RIGHT;
    }
    else if(mouvement == 2)
    {
        return LEFT;
    }
    else if(mouvement == 3)
    {
        return UP;
    }
    else if(mouvement == 4)
    {
        return DOWN;
    }
    else
    {
        return SPOT;
    }
}

int joueur3(int **monde)
{
    int mouvement = 1 + (rand() % 4);
    
    if(mouvement == 1)
    {
        return RIGHT;
    }
    else if(mouvement == 2)
    {
        return LEFT;
    }
    else if(mouvement == 3)
    {
        return UP;
    }
    else if(mouvement == 4)
    {
        return DOWN;
    }
    else
    {
        return SPOT;
    }
}

int joueur4(int **monde)
{
    int mouvement = 1 + (rand() % 4);
    
    if(mouvement == 1)
    {
        return RIGHT;
    }
    else if(mouvement == 2)
    {
        return LEFT;
    }
    else if(mouvement == 3)
    {
        return UP;
    }
    else if(mouvement == 4)
    {
        return DOWN;
    }
    else
    {
        return SPOT;
    }
}


int joueur5(int **monde)
{
    int mouvement = 1 + (rand() % 4);
    
    if(mouvement == 1)
    {
        return RIGHT;
    }
    else if(mouvement == 2)
    {
        return LEFT;
    }
    else if(mouvement == 3)
    {
        return UP;
    }
    else if(mouvement == 4)
    {
        return DOWN;
    }
    else
    {
        return SPOT;
    }
}
