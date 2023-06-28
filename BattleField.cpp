#include ".\baseInclude.h"

void BattleField::BattleStart(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
    std::cout<<B.getTrainerName();
    std::cout<<" would like to battele!"<<std::endl;
        std::cout<<'v'<<std::flush;//enterキーの要求
        flag = getchar();
    std::cout<<B.getTrainerName()<<" sent out ";
    std::cout<<B.getPokemon(1).getPokeName();
    std::cout<<'!'<<std::endl;
        std::cout<<'v'<<std::flush;//enterキーの要求
        flag = getchar();
    std::cout<<"Go! ";
    std::cout<<A.getPokemon(1).getPokeName();
    std::cout<<'!'<<std::endl;
        std::cout<<'v'<<std::flush;//enterキーの要求
        flag = getchar();
}
void BattleField :: selectAction(){
    std::cout<<""<<std::endl;
    selected = false;
    while(!selected){
        int select;
        std::cout<<A.getTrainerName()<<std::endl;
        std::cout<<"1.Battle"<<std::endl;
        std::cout<<"2.Pokemon"<<std::endl;
        std::cout<<"3.Check Status"<<std::endl;
        std::cout<<"4.Run"<<std::endl;
        std::cin>>select;
        std::cout<<std::endl;
        switch(select){
            case 1:BattleMove();break;
            case 2:PokeChenge();break;
            case 3:Check();break;
            case 4:Run();break;
        }
    }
}
    void BattleField::BattleMove(){
        nowBattleA->showMove();
        std::cout<<std::endl<<"5.Move Info"<<std::endl;
        int select;
        std::cin>>select;
        std::cout<<std::endl;
        if(select<=4&&select>=1){
            tmpMoveA.setMove(nowBattleA->getMove(select));
            selected = true;
        }
        else if(select==5){
            bool still = true;
            while(still){
                std::cout<<"Which Move Info do you wanna see?"<<std::endl;
                nowBattleA->showMove();
                std::cin>>select;
                std::cout<<std::endl;
                if(select<=4&&select>=1){
                    nowBattleA->getMove(select).showMoveInfo();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
                    std::cout<<'v'<<std::flush;//enterキーの要求
                    flag = getchar();
                }
                else{
                    still = false;
                }
            }

        }
    }
    void BattleField::PokeChenge(){
        std::cout<<"error:nothing"<<std::endl;
    }
    void BattleField::Check(){
        std::cout<<"error:nothing"<<std::endl;
    }
        void BattleField :: checkPokemon(bool which){
            if(which){
                for(int i=0;i<3;i++){
                    std::cout << i+1 << A.getPokemon(i).getPokeName() << std::endl;
                }
            }
            else{
                for(int i=0;i<3;i++){
                    std::cout << i+1 << B.getPokemon(i).getPokeName() << std::endl;
                }
            }
        }
        void BattleField::checkField(){
            std::cout<<"error:nothing"<<std::endl;
        }
void BattleField::Run(){
    std::cout<<"Do you rearry Run?"<<std::endl;
    if(isYESorNO()){
        std::cout<<A.getTrainerName()<<" blacked out."<<std::endl;
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
        if(nowBattleA->getSpeed() > nowBattleB->getSpeed()){

            std::cout<<nowBattleA->getPokeName()<<" used "<<tmpMoveA.getMoveName()<<std::endl;
            std::cout<<'v'<<std::flush;//enterキーの要求
            flag = getchar();
            std::cout<<"The "<<nowBattleB->getPokeName()<<std::endl;
            nowBattleB->showNowhp();
            std::cout<<"->"<<std::flush;
            nowBattleB->Moved(*nowBattleA,tmpMoveA);
            nowBattleB->showNowhp();

            std::cout<<"The "<<nowBattleB->getPokeName()<<" used "<<tmpMoveB.getMoveName()<<std::endl;
            std::cout<<'v'<<std::flush;//enterキーの要求
            flag = getchar();
            std::cout<<nowBattleA->getPokeName()<<std::endl;
            nowBattleA->showNowhp();
            std::cout<<"->"<<std::flush;                        
            nowBattleA->Moved(*nowBattleB,tmpMoveB);
            nowBattleA->showNowhp();
        }else{
            std::cout<<"The "<<nowBattleB->getPokeName()<<" used "<<tmpMoveB.getMoveName()<<std::endl;
            std::cout<<'v'<<std::flush;//enterキーの要求
            flag = getchar();
            std::cout<<nowBattleA->getPokeName()<<std::endl;
            nowBattleA->showNowhp();
            std::cout<<"->"<<std::flush;                        
            nowBattleA->Moved(*nowBattleB,tmpMoveB);
            nowBattleA->showNowhp();

            std::cout<<nowBattleA->getPokeName()<<" used "<<tmpMoveA.getMoveName()<<std::endl;
            std::cout<<'v'<<std::flush;//enterキーの要求
            flag = getchar();
            std::cout<<"The "<<nowBattleB->getPokeName()<<std::endl;
            nowBattleB->showNowhp();
            std::cout<<"->"<<std::flush;
            nowBattleB->Moved(*nowBattleA,tmpMoveA);
            nowBattleB->showNowhp();
        }
    }
    
}
BattleField::BattleField(Trainer a,Trainer b){
    A.setTrainer(a.getTrainerName(),a.getpPokemon());
    B.setTrainer(b.getTrainerName(),b.getpPokemon());
    
    nowBattleA = a.getpPokemon(1);
    nowBattleB = b.getpPokemon(1);
    Anum = 1;
    Bnum = 1;
    inBattle = true;
    Battle();
}