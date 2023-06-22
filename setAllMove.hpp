#pragma once
#include ".\Move.h"

void setAllMove(Move allMove[][4]){
    allMove[0][0].setMove("Tackle",NOM,Physical,40);

    allMove[1][0].setMove("Ember",HON,Spesial,40);

    allMove[2][0].setMove("Water Gun",MIZ,Spesial,40);
    
    allMove[3][0].setMove("Thunderbolt",DEN,Spesial,90);
    
    allMove[4][0].setMove("Leafage",KUS,Physical,40);
    
    allMove[5][0].setMove("Aura_Sphere",KAK,Spesial,80);
    
    allMove[6][0].setMove("ThunderShock",DEN,Spesial,40);

}
