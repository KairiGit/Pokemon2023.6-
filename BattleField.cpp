#pragma once
#include ".\BattleField.hpp"
#include ".\utility.hpp"
void BattleField::BattleStart(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
    std::cout<<B.getTrainerName();
    std::cout<<" would like to battele!"<<std::endl;
        enter();//enterキーの要求
        
    std::cout<<B.getTrainerName()<<" sent out ";
    std::cout<<B.getPokemon(1).getPokeName();
    std::cout<<'!'<<std::endl;
        enter();//enterキーの要求
        
    std::cout<<"[Go! ";
    std::cout<<A.getPokemon(1).getPokeName();
    std::cout<<"!]"<<std::endl;
        enter();//enterキーの要求
        
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
        AwillMove = true;
        tmpMoveB.setMove(nowBattleB->getMove(select));
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
                enter();//enterキーの要求
                
            }
            else{
                still = false;
            }
        }

    }
}
    void BattleField::PokeChenge(){
        std::cout<<"Which Pokemon do you wanna replace with?"<<std::endl;
        enter();//enterキーの要求
        
        for(int i=0;i<3;i++){
            std::cout << i+1 << A.getPokemon(i+1).getPokeName() << std::endl;
        }
        int tmp = Anum;
        std::cin>>Anum;
        if(tmp == Anum){
            std::cout<<"Alredy in Battle"<<std::endl;
            enter();
        }else if(A.getPokemon(Anum).isCanBattle()){
            selected = true;
            tmpMoveB.setMove(nowBattleB->getMove(1));
        }else{
            std::cout<<"Alredy fainted!"<<std::endl;
            enter();
        }
        enter();//enterキーの要求
        
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
        enter();//enterキーの要求
        
        selected = true;
        inBattle = false;
    }
}
void BattleField :: AChenge(){
    if(nowBattleB->getNowhp()>nowBattleB->getHP()/2){
        std::cout<<"["<<nowBattleA->getPokeName()<<"enough! come back!]"<<std::endl;
        enter();
        nowBattleA->setPokemon(A.getPokemon(Anum));
        std::cout <<"[Go! "<<nowBattleA->getPokeName()<<"!]"<<std::endl;
        enter();
    }else if(nowBattleB->getNowhp()>nowBattleB->getHP()/4){
        std::cout<<"["<<nowBattleA->getPokeName()<<"OK! come back!]"<<std::endl;
        enter();
        nowBattleA->setPokemon(A.getPokemon(Anum));
        std::cout <<"[Do it! "<<nowBattleA->getPokeName()<<"!]"<<std::endl;
        enter();
    }else{
        std::cout<<"["<<nowBattleA->getPokeName()<<"good! come back!]"<<std::endl;
        enter();
        nowBattleA->setPokemon(A.getPokemon(Anum));
        std::cout <<"[The enemy`s weak! Get`m "<<nowBattleA->getPokeName()<<"!]"<<std::endl;
        enter();
    }
}
void BattleField :: AMove(){
    std::cout<<nowBattleA->getPokeName()<<" used "<<tmpMoveA.getMoveName()<<std::endl;
    enter();//enterキーの要求
    
    std::cout<<"The "<<nowBattleB->getPokeName()<<std::endl;
    nowBattleB->showNowhp();
    std::cout<<"->"<<std::flush;
    nowBattleB->Moved(*nowBattleA,tmpMoveA);
    AwillMove = false;
    nowBattleB->showNowhp();
}
void BattleField :: BMove(){
    std::cout<<"The "<<nowBattleB->getPokeName()<<" used "<<tmpMoveB.getMoveName()<<std::endl;
    enter();//enterキーの要求
    
    std::cout<<nowBattleA->getPokeName()<<std::endl;
    nowBattleA->showNowhp();
    std::cout<<"->"<<std::flush;                        
    nowBattleA->Moved(*nowBattleB,tmpMoveB);
    nowBattleA->showNowhp();
}
void BattleField :: Battle(){
    BattleStart();

    while(inBattle){
        selectAction();
        if(!inBattle){
            break;
        }
        if(nowBattleA->getSpeed() > nowBattleB->getSpeed()){
            if(AwillMove){
                AMove();
            }else{
                AChenge();
            }

            if(nowBattleB->isCanBattle()){
                if(BwillMove){
                    BMove();
                }
            }else{
                nowBattleB->dieMessage();
            }
            enter();//enterキーの要求

            if( ! nowBattleA->isCanBattle()){
                nowBattleA->dieMessage();
                enter();
            }

        }else{
            if(BwillMove){
                BMove();
            }

            if(nowBattleA->isCanBattle()){
                if(AwillMove){
                    AMove();
                }
            }else{
                nowBattleA->dieMessage();
            }
            enter();//enterキーの要求
            if( ! nowBattleB->isCanBattle()){
                nowBattleB->dieMessage();
                enter();
            }
            
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
    AwillMove = false;
    BwillMove = true;
    Battle();
}