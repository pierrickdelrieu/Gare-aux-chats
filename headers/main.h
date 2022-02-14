//
//  fonctions.h
//  gare_aux_chats
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> //pour le sleep


#define FALSE 0
#define TRUE 1




//MONDE
#define HEIGHT 15 //hauteur (ligne)
#define WIDTH 15 //largeur (colonne)

#define CASE_VIDE 0
#define CHAT 6
int ** creation_monde_vide(int hauteur, int largeur);
void affichage_monde(int **monde);
int condition_arret_partie(int **monde);
void desalocation_monde(int **monde);
int nombre_chats(int **monde);




#define SOURIS1 1
#define SOURIS2 2
void position_initial_souris(int ***monde, int position_joueur1[2], int position_joueur2[2]);
void supr_console();




int cases_valides_souris(int x, int y, int **monde);
void position_souris(int **monde, int souris, int position[2]);
void deplacement_souris(int ***monde, int souris, int position [2], int mouvement);
int condition_vie_souris(int ***monde, int souris, int position_joueur[2]);


//Deplacement
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
#define SPOT 5

int souris1(int **monde);
int souris2(int **monde);







//CHATS
#define NX_CHAT 7
void random_ajout_chat(int ***monde);
int case_valide_chat(int i, int j, int **monde);
void deplacement_chats(int ***monde);
void reabilitation_valeur_chat(int ***monde);







//...................SYSTEME D'EXLOITATION....................
#ifdef _WIN32
#define SYSTEME_EXPLOITATION "win" //windows
#elif __linux__
#define SYSTEME_EXPLOITATION "linux"
#elif __APPLE__
#define SYSTEME_EXPLOITATION "mac"
#else
#define SYSTEME_EXPLOITATION "unk" //systéme inconnu
#endif

void supr_console();




#endif /* main_h */
