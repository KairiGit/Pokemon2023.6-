#include ".\baseInclude.h"


BattleField::BattleField(Trainer* a,Trainer* b){
        for(int i=0;i<3;i++){
            this->A->getMyPokemon(i)->setPokemon(a->getMyPokemon(i));
            this->B->getMyPokemon(i)->setPokemon(b->getMyPokemon(i));
        }
    }
    void BattleField :: showPokemon(bool which){
        if(which){
            for(int i=0;i<3;i++){
                std::cout << i+1 << A->getMyPokemon(i) << std::endl;
            }
        }
        else{
            for(int i=0;i<3;i++){
                std::cout << i+1 << B->getMyPokemon(i) << std::endl;
            }
        }
    }
