#include ".\baseInclude.h"
void Pokemon :: setPokemon(std::string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed,Move move){
    PokeName = name;
    fPokeType = f;
    sPokeType = s;
    Nowhp = hp;
    HP = hp;
    Atk = atk;
    Def = def;
    Sp_Atk = sp_atk;
    Sp_Def = sp_def;
    Speed = speed;
    m[0] = move;
    isAlive = true;
}

void Pokemon :: setPokeMove(Move* x){
    for(int i=0;i<4;i++){
        m[i].setMove(x[i].getMoveName(),x[i].getMoveType(),x[i].getCat(),x[i].getPow());
    }
}

void Pokemon :: Attacked(Pokemon atk,Move w){
    Nowhp = Nowhp - dmg(atk.getAtk(),Def,w.getPow());
}
void Pokemon :: spAttacked(Pokemon atk,Move w){
    Nowhp = Nowhp - dmg(atk.getSp_Atk(),Sp_Def,w.getPow());
}
void Pokemon :: Moved(Pokemon atk,Move w){
    switch(w.getCat()){
        case 0: Attacked(atk,w);break;
        case 1: spAttacked(atk,w);break;
        case 2: break;
    }
    if(Nowhp<=0){
        Nowhp = 0;
        die();
    }
}
void Pokemon :: showNowhp(){
    if(Nowhp>HP/2){std::cout <<"\x1b[38;2;0;255;0m"<<Nowhp<<"\x1b[m"<<std::endl;}
    else if(Nowhp>HP/4){std::cout <<"\x1b[38;2;255;255;0m"<<Nowhp<<"\x1b[m"<<std::endl;}
    else{std::cout <<"\x1b[38;2;255;0;0m"<<Nowhp<<"\x1b[m"<<std::endl;}
}
void Pokemon :: showPokeType(){
    exType(fPokeType);
    std::cout <<'/';
    exType(sPokeType);
    std::cout <<std::endl;
}
void Pokemon :: showStats(){
    std::cout <<'H'<<getHP()<<' '<<'A'<<getAtk()<<' '<<'B'<<getDef()<<' '<<'C'<<getSp_Atk()<<' '<<'D'<<getSp_Def()<<' '<<'S'<<getSpeed()<<std::endl;
}

void Pokemon :: showMove(){
    for(int i=0;i<4;i++){
        std::cout <<i+1<< m[i].getMoveName() <<std::endl;
    }
}
void Pokemon :: showAllST(){
    std::cout <<std::endl;
    std::cout <<"Type is ";
    exType(fPokeType);
    std::cout <<'/';
    exType(sPokeType);
    std::cout <<std::endl;
    std::cout <<"Status is "<<'H'<<getHP()<<' '<<'A'<<getAtk()<<' '<<'B'<<getDef()<<' '<<'C'<<getSp_Atk()<<' '<<'D'<<getSp_Def()<<' '<<'S'<<getSpeed()<<std::endl;
    std::cout <<"Move is"<<std::endl;
    for(int i=0;i<4;i++){
        std::cout <<i+1<<':'<< m[i].getMoveName() <<std::endl;
    }
    std::cout <<std::endl;
}