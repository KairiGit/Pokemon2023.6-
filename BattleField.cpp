#include ".\baseInclude.h"

void BattleField::BattleStart(){
    std::cout<<B->getTrainerName();
    std::cout<<" wants to fight!"<<std::endl;
        std::cout<<'v';//enterキーの要求
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
        flag = getchar();
    std::cout<<B->getTrainerName()<<" sent out ";
    std::cout<<B->getPokemon(1).getPokeName();
    std::cout<<'!'<<std::endl;
        std::cout<<'v';//enterキーの要求
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
        flag = getchar();
    std::cout<<"Go! ";
    std::cout<<A->getPokemon(1).getPokeName();
    std::cout<<'!'<<std::endl;
        std::cout<<'v';//enterキーの要求
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
        flag = getchar();  
}
void BattleField :: selectAction(){

}
void BattleField :: checkPokemon(bool which){
    if(which){
        for(int i=0;i<3;i++){
            std::cout << i+1 << A->getPokemon(i).getPokeName() << std::endl;
        }
    }
    else{
        for(int i=0;i<3;i++){
            std::cout << i+1 << B->getPokemon(i).getPokeName() << std::endl;
        }
    }
}

void BattleField :: Battle(){
    BattleStart();
    while(true){
        selectAction();
        break;
    }
    
}
BattleField::BattleField(Trainer* a,Trainer* b){
    A->setTrainer(a->getTrainerName(),a->getpPokemon());
    B->setTrainer(b->getTrainerName(),b->getpPokemon());
    Battle();
}