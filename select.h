#include <iostream>
#include <string>
#include ".\Poke.h"
using namespace std;
int select(Pokemon* x,int numPokemons){
    int select;
    cout <<"Choose your Pokemon"<<endl;
    for(int i=0;i<numPokemons;i++){
        cout <<i+1<< x[i].getPokeName() <<endl;
    }
    cin >> select;
    return select-1;
}
Pokemon check(Pokemon x,bool* still){
    Pokemon tmp;
    cout <<"Show the status of "<<x.getPokeName()<<endl;
    x.showAllST();
    cout <<endl<<"OK?"<<endl;
    if(getYesNoAnswer()){
        cout <<"You choose "<<x.getPokeName()<<endl;
        tmp = x;
        *still = false;
    }
    return tmp;
}