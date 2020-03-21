//
//  plateau.c
//  zombies
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "fonctions.h"


int ** creation_plateau_vide(int hauteur, int largeur)
{
    int **plateau = NULL;
    int i;
    
    //Allocation espace dynamique
    plateau = (int **) malloc(hauteur * sizeof(int *));
    
    for(i=0; i<hauteur; i++)
    {
        plateau[i] = (int *) calloc(largeur, sizeof(int));
    }

    return(plateau);
}

void affichage_plateau(int **plateau)
{
    int i,j;
    
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDHT; j++)
        {
            if(plateau[i][j] == ZOMBIE)
            {
                printf("Z ");
            }
            else if(plateau[i][j] == CASE_VIDE)
            {
                printf("  ");
            }
            else
            {
                printf("%d ",plateau[i][j]);
            }
        }
        printf("\n");
    }
}


void desalocation_plateau(int **plateau)
{
    int i;
    for(i=0; i<HEIGHT; i++)
    {
        free(plateau[i]);
    }
    
    free(plateau);
}

void supr_console()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int condition_arret_partie(int **monde)
{
    int i,j;
    int retour = 0; //0 si arret de partie et 1 sinon
    
    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDHT; j++)
        {
            if((monde[i][j] == JOUEUR1) || (monde[i][j] == JOUEUR2) || (monde[i][j] == JOUEUR3) || (monde[i][j] == JOUEUR4) || (monde[i][j] == JOUEUR5))
            {
                retour = 1;
            }
        }
    }
    
    return (retour);
}
