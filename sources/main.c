#include <stdio.h>

//
//  main.c
//  gare_aux_chats
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//


#include "../headers/main.h"



int main()
{
    int **monde = NULL;
    int tour = 1;


    monde = creation_monde_vide(HEIGHT, WIDTH);

    int position_souris1[2]; // 0 : x : column
    int position_souris2[2]; // 1 : y : line

    position_initial_souris(&monde,position_souris1,position_souris2);
    random_ajout_chat(&monde);
    supr_console();
    printf("-------------------- Gare aux chats --------------------\n\n");
    printf("Temps : 0 sec\n");
    printf("Joueur en vie : Tous\n");
    printf("Il y a %d chats\n\n", nombre_chats(monde));
    affichage_monde(monde);
    sleep(1); //met le programme en pause pendant 1 sec
    supr_console();



    //BOUCLE DE JEU
    while(condition_arret_partie(monde) == FALSE) {

        printf("-------------------- Gare aux chats --------------------\n\n");
        printf("Temps : %d sec\n", tour);


        printf("Joueur en vie : ");

        //JOUEUR1
        printf("Souris ");
        if(condition_vie_souris(&monde, SOURIS1, position_souris1) == 1) {
            deplacement_souris(&monde, SOURIS1, position_souris1, souris1(monde));
            position_souris(monde, SOURIS1, position_souris1);
            printf("1 - ");
        }

        //JOUEUR2
        if(condition_vie_souris(&monde, SOURIS2, position_souris2) == 1) {
            deplacement_souris(&monde, SOURIS2, position_souris2, souris2(monde));
            position_souris(monde, SOURIS2, position_souris2);
            printf("2");
        }
        printf("\n");



        //CHATS
        deplacement_chats(&monde);
        reabilitation_valeur_chat(&monde);
        random_ajout_chat(&monde);


        printf("Il y a %d chats\n\n", nombre_chats(monde));

        affichage_monde(monde);
        tour ++;
        sleep(1); //met le programme en pause pendant 1 sec
        supr_console();
    }


    printf("-------------------- Gare aux chats --------------------\n\n");
    printf("Temps : %d sec\n", tour);
    printf("Joueur en vie : 0\n");
    printf("Il y a %d chats\n\n", nombre_chats(monde));


    desalocation_monde(monde);
    return 0;
}


