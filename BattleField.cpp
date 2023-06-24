#include ".\baseInclude.h"

void BattleField::BattleStart(){
    std::cout<<B->getTrainerName();
    std::cout<<" wants to fight!"<<std::endl;
        std::cout<<'v'<<std::flush;//enterキーの要求
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
        flag = getchar();
    std::cout<<B->getTrainerName()<<" sent out ";
    std::cout<<B->getPokemon(1).getPokeName();
    std::cout<<'!'<<std::endl;
        std::cout<<'v'<<std::flush;//enterキーの要求
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
        flag = getchar();
    std::cout<<"Go! ";
    std::cout<<A->getPokemon(1).getPokeName();
    std::cout<<'!'<<std::endl;
        std::cout<<'v'<<std::flush;//enterキーの要求
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
        flag = getchar();  
}
void BattleField :: selectAction(){
       selected = false;
        while(!selected){
            int select;
            std::cout<<"1.Fight"<<std::endl;
            std::cout<<"2.Check"<<std::endl;
            std::cout<<"3.Surrender"<<std::endl;
            std::cin>>select;
            switch(select){
                case 1:break;
                case 2:break;
                case 3:break;
            }
        }
    }
    void BattleField::Fight(){
        std::cout<<"error:nothing"<<std::endl;
    }
    void BattleField::Check(){
        std::cout<<"error:nothing"<<std::endl;
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
void BattleField::checkField(){
    std::cout<<"error:nothing"<<std::endl;
}
void BattleField::Surrender(){
    std::cout<<"Do you rearry surrender?"<<std::endl;
    if(isYESorNO()){
        std::cout<<A->getTrainerName()<<" blacked out."<<std::endl;
        std::cout<<'v'<<std::flush;//enterキーの要求
        flag = getchar();
        selected = true;
        inBattle = false;
    }
}
void BattleField :: Battle(){
    BattleStart();
    while(inBattle){
        selectAction();
    }
    
}
BattleField::BattleField(Trainer* a,Trainer* b){
    A->setTrainer(a->getTrainerName(),a->getpPokemon());
    B->setTrainer(b->getTrainerName(),b->getpPokemon());
    Battle();
}