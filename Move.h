#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#include <enum.h>
class Move{
    private:
        string MoveName;
        Type MoveType;
        Cat cat;
        int Pow;
        int Acc;
    protected:
    public:
        Move(string n,Type t,Cat c,int p){
            MoveName = n;
            MoveType = t;
            cat = c;
            Pow = p;
        }
        Move(){}
        void setMove(string n,Type t,Cat c,int p){
            MoveName = n;
            MoveType = t;
            cat = c;
            Pow = p;
        }
        string getMoveName(){return MoveName;}
        Type getMoveType(){return MoveType;}
        Cat getCat(){return cat;}
        int getPow(){return Pow;}
        int getAcc(){return Acc;}
};