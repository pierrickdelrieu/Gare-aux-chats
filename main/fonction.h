//
//  fonction.h
//  zombies
//
//  Created by Pierrick Delrieu on 18/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#ifndef fonction_h
#define fonction_h

#define HEIGHT 15 //hauteur (ligne)
#define WIDHT 15 //largeur (colonne)

#define ZOMBIE 6
#define NX_ZOMBIE 7
#define CASE_VIDE 0

//Position

//Player






//Plateau
int ** creation_plateau_vide(int hauteur, int largeur);
void affichage_plateau(int **plateau);
void supr_console(void);


//Zombies
void random_ajout_zombie(int ***monde);
int case_valide_zombie(int i, int j, int **plateau);
void deplacement_zombies(int ***plateau);
void reabilitation_valeur_zombies(int ***plateau);


//Perso
//int case_valide_perso(int i, int j, int **plateau);



#endif /* fonction_h */
