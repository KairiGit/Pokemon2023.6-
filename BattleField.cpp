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
                std::cout << i+1 << A->getMyPokemon(i)->getPokeName() << std::endl;
            }
        }
        else{
            for(int i=0;i<3;i++){
                std::cout << i+1 << B->getMyPokemon(i)->getPokeName() << std::endl;
            }
        }
    }
    void BattleField :: Battle(){
        std::cout<<B->getTrainerName()<<" sent out ";
        std::cout<<B->getMyPokemon(1)->getPokeName();
        std::cout<<'!'<<std::endl;

        std::cout<<"Go! ";
        std::cout<<A->getMyPokemon(1)->getPokeName()
        std::cout<<'!'<<std::endl;

    }
