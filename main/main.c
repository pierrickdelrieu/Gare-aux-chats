//
//  main.c
//  zombies
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <time.h>
#include <unistd.h>

int main()
{
    int **plateau = NULL;
    int jeu = 0;
    srand((unsigned)time(NULL)); //initialisation du temps
    
    plateau = creation_plateau_vide(HEIGHT, WIDHT);
    
    while(jeu<400)
    {
        random_ajout_zombie(&plateau);
        affichage_plateau(plateau);
        deplacement_zombies(&plateau);
        reabilitation_valeur_zombies(&plateau);
        jeu ++;
//        sleep(1); //met le programme en pause
        supr_console();
    }
    

    return 0;
}
