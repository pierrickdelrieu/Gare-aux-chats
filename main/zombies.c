//
//  zombies.c
//  zombies
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include <stdio.h>
#include "fonction.h"
#include <stdlib.h>
#include <time.h>


void random_ajout_zombie(int ***monde)
{
    int haut_droite;
    int bas_droite;
    int haut_gauche;
    int bas_gauche;
    
    haut_droite = 1 + (rand() % 4);
    bas_droite = 1 + (rand() % 4);
    haut_gauche = 1 + (rand() % 4);
    bas_gauche = 1 + (rand() % 4);
    
    if(haut_droite == 1)
    {
        *(*(*monde) + (WIDHT-1)) = ZOMBIE;
    }
    
    if(bas_droite == 1)
    {
        *(*(*monde + (HEIGHT-1)) + (WIDHT-1)) = ZOMBIE;
    }
    
    if(haut_gauche == 1)
    {
        *(*(*monde)) = ZOMBIE;
    }
    
    if(bas_gauche == 1)
    {
        *(*(*monde + (HEIGHT-1))) = ZOMBIE;
    }
}

int case_valide_zombie(int i, int j, int **plateau)
{
    // 1 si plateau[i][j] valide et 0 sinon

    int valide = 0;

    if((i<HEIGHT) && (j<WIDHT) && (i>0) && (j>0))
    {
        valide = 1;
    }

    if((valide == 1) && (plateau[i][j] != ZOMBIE))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void deplacement_zombies(int ***plateau)
{
    //1-droite; 2-gauche; 3-haut; 4-bas; 5-bouge pas
    
    int i,j;
    int position;
    
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDHT; j++)
        {
            if(i == 0)
            {
                do{
                    position = 1 + (rand() % 5);
                }while(position == 2);
            }
            if(i == HEIGHT-1)
            {
                do{
                    position = 1 + (rand() % 5);
                }while(position == 3);
            }
            if(j == 0)
            {
                do{
                    position = 1 + (rand() % 5);
                }while(position == 1);
            }
            if(j == WIDHT-1)
            {
                do{
                    position = 1 + (rand() % 5);
                }while(position == 4);
            }
            if((i == 0) && (j == 0))
            {
                while((position == 2) || (position == 3))
                {
                    position = 1 + (rand() % 5);
                }
            }
            if((i == 0) && (j == WIDHT-1))
            {
                while((position == 1) || (position == 3))
                {
                    position = 1 + (rand() % 5);
                }
            }
            if((i == HEIGHT-1) && (j == 0))
            {
                while((position == 2) || (position == 4))
                {
                    position = 1 + (rand() % 5);
                }
            }
            if((i == HEIGHT-1) && (j == WIDHT-1))
            {
                while((position == 1) || (position == 4))
                {
                    position = 1 + (rand() % 5);
                }
            }
            
            if((i != 0) && (i != HEIGHT-1) && (j != 0) && (j != WIDHT-1))
            {
                position = 1 + (rand() % 5);
            }
            
            
            if(*(*(*plateau + i)+j) == ZOMBIE)
            {
                if((case_valide_zombie(i, j+1, *plateau) == 1) && (position == 1)) //droite
                {
                    *(*(*plateau + i)+j) = CASE_VIDE;
                    *(*(*plateau + i)+(j+1)) = NX_ZOMBIE;
                }
                else if((case_valide_zombie(i, j-1, *plateau) == 1) && (position == 2)) //gauche
                {
                    *(*(*plateau + i)+j) = CASE_VIDE;
                    *(*(*plateau + i)+(j-1)) = NX_ZOMBIE;
                }
                else if((case_valide_zombie(i-1, j, *plateau) == 1) && (position == 3)) //haut
                {
                    *(*(*plateau + i)+j) = CASE_VIDE;
                    *(*(*plateau + (i-1))+j) = NX_ZOMBIE;
                }
                else if((case_valide_zombie(i+1, j, *plateau) == 1) && (position == 4)) //bas
                {
                    *(*(*plateau + i)+j) = CASE_VIDE;
                    *(*(*plateau + (i+1))+j) = NX_ZOMBIE;
                }
            }
        }
    }
}

void reabilitation_valeur_zombies(int ***plateau)
{
    int i,j;
    
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDHT; j++)
        {
            if(*(*(*plateau + i)+j) == NX_ZOMBIE)
            {
                *(*(*plateau + i)+j) = ZOMBIE;
            }
        }
    }
}
