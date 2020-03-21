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
    int position_joueur2[2];
    int position_joueur3[2];
    int position_joueur4[2];
    int position_joueur5[2];
    
    position_initial_joueur(&plateau,position_joueur1,position_joueur2,position_joueur3,position_joueur4,position_joueur5);
    
    
    //BOUCLE DE JEU
    while(condition_arret_partie(plateau) == 1)
    {
    
        //verifier que le joueur n'est pas mort
        
        
        //JOUEUR1
        if(condition_vie_joueur(&plateau, JOUEUR1, position_joueur1) == 1)
        {
            position_joueur(plateau, JOUEUR1, position_joueur1);
            deplacement_joueur(&plateau, JOUEUR1, position_joueur1, joueur1(plateau));
            position_joueur(plateau, JOUEUR1, position_joueur1);
        }
                  
        //JOUEUR2
        if(condition_vie_joueur(&plateau, JOUEUR2, position_joueur2) == 1)
        {
            position_joueur(plateau, JOUEUR2, position_joueur2);
            deplacement_joueur(&plateau, JOUEUR2, position_joueur2, joueur2(plateau));
            position_joueur(plateau, JOUEUR2, position_joueur2);
        }
        
        //JOUEUR3
        if(condition_vie_joueur(&plateau, JOUEUR3, position_joueur3) == 1)
        {
            position_joueur(plateau, JOUEUR3, position_joueur3);
            deplacement_joueur(&plateau, JOUEUR3, position_joueur3, joueur3(plateau));
            position_joueur(plateau, JOUEUR3, position_joueur3);
        }
        
        //JOUEUR4
        if(condition_vie_joueur(&plateau, JOUEUR4, position_joueur4) == 1)
        {
            position_joueur(plateau, JOUEUR4, position_joueur4);
            deplacement_joueur(&plateau, JOUEUR4, position_joueur4, joueur4(plateau));
            position_joueur(plateau, JOUEUR4, position_joueur4);
        }
        
        //JOUEUR5
        if(condition_vie_joueur(&plateau, JOUEUR5, position_joueur5) == 1)
        {
            position_joueur(plateau, JOUEUR5, position_joueur5);
            deplacement_joueur(&plateau, JOUEUR5, position_joueur5, joueur5(plateau));
            position_joueur(plateau, JOUEUR5, position_joueur5);
        }
        
        //ZOMBIES
        deplacement_zombies(&plateau);
        random_ajout_zombie(&plateau);
        reabilitation_valeur_zombies(&plateau);
        
        affichage_plateau(plateau);
        tour ++;
        sleep(1); //met le programme en pause pendant 1 sec
        supr_console();
    }
    
    desalocation_plateau(plateau);
    return 0;
}

