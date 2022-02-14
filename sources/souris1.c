//
//  souris1.c
//  gare_aux_chats
//
//  Created by Pierrick Delrieu on 22/03/2020.
//  Copyright © 2020 Pierrick Delrieu. All rights reserved.
//

#include "../headers/main.h"

//position initiale : [WIDHT/2, HEIGHT/2]

int souris1(int **monde) {
    int position[2];
    position_souris(monde, SOURIS1, position);


    //Détection des chats autours
    if((monde[position[1]][position[0]-1] == CHAT) && (cases_valides_souris(position[1], position[0]+1, monde) == 1)) {
        return RIGHT;
    }
    else if((monde[position[1]][position[0]+1] == CHAT) && (cases_valides_souris(position[1], position[0]-1, monde) == 1)) {
        return LEFT;
    }
    else if((monde[position[1]+1][position[0]] == CHAT) && (cases_valides_souris(position[1]-1, position[0], monde) == 1)) {
        return UP;
    }
    else if((monde[position[1]-1][position[0]] == CHAT) && (cases_valides_souris(position[1]+1, position[0], monde) == 1)) {
        return DOWN;
    }
    else {
        return SPOT;
    }
}
