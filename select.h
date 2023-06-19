#include <iostream>
#include <string>
#include ".\Poke.h"
using namespace std;
int select(Pokemon* x,int AllPokenumber){
    int select;
    cout <<"Choose your Pokemon"<<endl;
    for(int i=0;i<AllPokenumber;i++){
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
    if(YN()){
        cout <<"You choose "<<x.getPokeName()<<endl;
        tmp = x;
        *still = false;
    }
    return tmp;
}