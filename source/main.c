//
//  main.c
//  zombies
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//


#include "fonctions.h"


int main()
{
    int **plateau = NULL;
    int tour = 0;
    srand((unsigned)time(NULL)); //initialisation du temps
    
    plateau = creation_plateau_vide(HEIGHT, WIDHT);
    
    int position_joueur1[2];
//    int position_joueur2[2];
//    int position_joueur3[2];
//    int position_joueur4[2];
//    int position_joueur5[2];
    
    while(tour<400)
    {
        
        //JOUEUR
        if(tour == 0)
        {
            position_initial_joueur(&plateau);
        }
        else
        {
            position_joueur(plateau, JOUEUR1, position_joueur1);
            deplacement_joueur(&plateau, JOUEUR1, position_joueur1, joueur1(plateau));
        }
        
        
        //ZOMBIES
        random_ajout_zombie(&plateau);
        affichage_plateau(plateau);
        deplacement_zombies(&plateau);
        reabilitation_valeur_zombies(&plateau);
        tour ++;
        sleep(1); //met le programme en pause
        supr_console();
    }
    

    return 0;
}

