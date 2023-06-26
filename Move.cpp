#include ".\baseInclude.h"

Move::Move(std::string n,Type t,Cat c,int p,int a){
    MoveName = n;
    MoveType = t;
    cat = c;
    Pow = p;
    Acc = a;
}