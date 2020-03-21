//
//  fonctions.h
//  zombies
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#ifndef fonctions_h
#define fonctions_h

//PLAYER
int joueur1(int **monde);






#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Plateau
#define HEIGHT 15 //hauteur (ligne)
#define WIDHT 15 //largeur (colonne)

#define CASE_VIDE 0
#define ZOMBIE 6
int ** creation_plateau_vide(int hauteur, int largeur);
void affichage_plateau(int **plateau);
void supr_console(void);


//Zombies
#define NX_ZOMBIE 7
void random_ajout_zombie(int ***monde);
int case_valide_zombie(int i, int j, int **plateau);
void deplacement_zombies(int ***plateau);
void reabilitation_valeur_zombies(int ***plateau);


//Joueur
#define NOMBRE_DE_JOUEUR 0
#define JOUEUR1 1
#define JOUEUR2 2
#define JOUEUR3 3
#define JOUEUR4 4
#define JOUEUR5 5

int case_valide_joueur(int i, int j, int **plateau);
void position_initial_joueur(int ***monde);
void position_joueur(int **monde, int joueur, int position[2]);
void deplacement_joueur(int ***monde, int joueur, int position [2], int mouvement);


//Deplacement
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
#define SPOT 5






#endif /* fonctions_h */
