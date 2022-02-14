//
//  monde.c
//  gare_aux_chats
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "../headers/main.h"


int ** creation_monde_vide(int hauteur, int largeur)
{
    int **monde = NULL;
    int i;
    
    //Allocation espace dynamique
    monde = (int **) malloc(hauteur * sizeof(int *));
    
    for(i=0; i<hauteur; i++)
    {
        monde[i] = (int *) calloc(largeur, sizeof(int));
    }

    return(monde);
}

void affichage_monde(int **monde) {
    int i,j;

    for(i=0; i<WIDTH; i++) {
        for(j=0; j<HEIGHT; j++) {
            if(monde[i][j] == CHAT) {
                printf(" C ");
            }
            else if(monde[i][j] == CASE_VIDE) {
                printf(" _ ");
            }
            else {
                printf(" %d ",monde[i][j]);
            }
        }
        printf("\n");
    }
}

void supr_console(void)
{
    system(strcmp(SYSTEME_EXPLOITATION, "win") == 0 ? "cls" : "clear");
}

int condition_arret_partie(int **monde)
{
    int i,j;

    for(i=0; i<WIDTH; i++)
    {
        for(j=0; j<HEIGHT; j++)
        {
            if((monde[i][j] == SOURIS1) || (monde[i][j] == SOURIS2))
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}

int nombre_chats(int **monde) {
    int sum = 0; //0 si arret de partie et 1 sinon

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if((monde[i][j] == CHAT) || (monde[i][j] == NX_CHAT)){
                sum ++;
            }
        }
    }

    return sum;
}




void desalocation_monde(int **monde)
{
    int i;
    for(i=0; i<HEIGHT; i++)
    {
        free(monde[i]);
    }

    free(monde);
}