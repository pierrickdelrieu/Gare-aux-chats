//
//  souris1.c
//  gare_aux_chats
//
//  Created by Pierrick Delrieu on 22/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"

//position initiale : [WIDHT/2, HEIGHT/2]

int souris1(int **monde)
{
    int i, j;
    int position[2];
    
    //Recupération de la position de la souris
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            if(monde[i][j] == SOURIS1)
            {
                position[0] = i;
                position[1] = j;
            }
        }
    }
    
    //Détection des chats autours
    if((monde[position[0]][position[1]-1] == CHAT) && (case_valide_souris(position[0], position[1]-1, monde) == 1))
    {
        return RIGHT;
    }
    else if((monde[position[0]][position[1]+1] == CHAT) && (case_valide_souris(position[0], position[1]+1, monde) == 1))
    {
        return LEFT;
    }
    else if((monde[position[0]+1][position[1]] == CHAT) && (case_valide_souris(position[0]+1, position[1], monde) == 1))
    {
        return UP;
    }
    else if((monde[position[0]-1][position[1]] == CHAT) && (case_valide_souris(position[0]-1, position[1], monde) == 1))
    {
        return DOWN;
    }
    else
    {
        return SPOT;
    }
}
