#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
using namespace std;
#include <enum.h>
#include <Move.h>
#include <something.h>
#include <Poke.h>

void Pokemon :: setPokeMove(Move one,Move two,Move three,Move four){
    m[0].setMove(one.getMoveName(),one.getMoveType(),one.getCat(),one.getPow());
    m[1].setMove(two.getMoveName(),two.getMoveType(),two.getCat(),two.getPow());
    m[2].setMove(three.getMoveName(),three.getMoveType(),three.getCat(),three.getPow());
    m[3].setMove(four.getMoveName(),four.getMoveType(),four.getCat(),four.getPow());
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
    if(Nowhp>HP/2){cout <<"\x1b[38;2;0;255;0m"<<Nowhp<<"\x1b[m"<<endl;}
    else if(Nowhp>HP/4){cout <<"\x1b[38;2;255;255;0m"<<Nowhp<<"\x1b[m"<<endl;}
    else{cout <<"\x1b[38;2;255;0;0m"<<Nowhp<<"\x1b[m"<<endl;}
}
void Pokemon :: showPokeType(){
    exType(fPokeType);
    cout <<'/';
    exType(sPokeType);
    cout <<endl;
}
void Pokemon :: showStats(){
    cout <<'H'<<getHP()<<' '<<'A'<<getAtk()<<' '<<'B'<<getDef()<<' '<<'C'<<getSp_Atk()<<' '<<'D'<<getSp_Def()<<' '<<'S'<<getSpeed()<<endl;
}

void Pokemon :: showMove(){
    for(int i=0;i<4;i++){
        cout <<i+1<< m[i].getMoveName() <<endl;
    }
}
void Pokemon :: showAllST(){
    cout <<endl;
    cout <<"Type is ";
    exType(fPokeType);
    cout <<'/';
    exType(sPokeType);
    cout <<endl;
    cout <<"Status is "<<'H'<<getHP()<<' '<<'A'<<getAtk()<<' '<<'B'<<getDef()<<' '<<'C'<<getSp_Atk()<<' '<<'D'<<getSp_Def()<<' '<<'S'<<getSpeed()<<endl;
    cout <<"Move is"<<endl;
    for(int i=0;i<4;i++){
        cout <<i+1<<':'<< m[i].getMoveName() <<endl;
    }
    cout <<endl;
}