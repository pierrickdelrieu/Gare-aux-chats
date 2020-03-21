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
