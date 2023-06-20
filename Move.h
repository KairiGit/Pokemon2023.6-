#pragma once
#include ".\exType.h"
#include ".\getYesNoAnswer.h"
class Move{
    private:
        std::string MoveName;
        Type MoveType;
        Cat cat;
        int Pow;
        int Acc;
    protected:
    public:
        Move(const std::string n,Type t,Cat c,int p);
        Move(){}
        void setMove(const std::string n,Type t,Cat c,int p){
            MoveName = n;
            MoveType = t;
            cat = c;
            Pow = p;
        }
        std::string getMoveName(){return MoveName;}
        Type getMoveType(){return MoveType;}
        Cat getCat(){return cat;}
        int getPow(){return Pow;}
        int getAcc(){return Acc;}
};
Move::Move(const std::string n,Type t,Cat c,int p){
    MoveName = n;
    MoveType = t;
    cat = c;
    Pow = p;
}