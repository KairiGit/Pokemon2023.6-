#pragma once
#include ".\exType.h"
#include ".\isYESorNO.h"
class Move{
    private:
        std::string MoveName;
        Type MoveType;
        Cat cat;
        int Pow;
        int Acc;
    protected:
    public:
        Move(const std::string n,Type t,Cat c,int p,int a);
        Move(){}
        void setMove(const std::string n,Type t,Cat c,int p,int a){
            MoveName = n;
            MoveType = t;
            cat = c;
            Pow = p;
            Acc = a;
        }
        void setMove(Move x){
            MoveName = x.getMoveName();
            MoveType = x.getMoveType();
            cat = x.getCat();
            Pow = x.getPow();     
            Acc = x.getAcc();       
        }
        std::string getMoveName(){return MoveName;}
        Type getMoveType(){return MoveType;}
        Cat getCat(){return cat;}
        int getPow(){return Pow;}
        int getAcc(){return Acc;}
        void showMoveInfo(){
            std::cout<<getMoveName()<<std::endl;
            std::cout<<"Type: "<<std::flush; exType(getMoveType());std::cout<<std::endl;
            std::cout<<"Category: "<<getCat()<<std::endl;
            std::cout<<"Power: "<<getPow()<<std::endl;
            std::cout<<"Actually: "<<getAcc()<<std::endl;
        }
};