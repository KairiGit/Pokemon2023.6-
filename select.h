#include ".\Poke.h"

int select(Pokemon* x){
    int select;
    cout <<"Which Pokemon would you choose?"<<endl;
    for(int i=0;i<5;i++){
        cout <<i+1<< x[i].getPokeName() <<endl;
    }
    cin >> select;
    return select-1;
}
Pokemon check(Pokemon x,bool* still){
    Pokemon tmp;
    cout <<"Show the status of "<<x.getPokeName()<<endl;
    x.showAllST();
    cout <<"OK?"<<endl;
    if(YN()){
        cout <<"You choose "<<x.getPokeName()<<endl;
        tmp = x;
        *still = false;
    }
    return tmp;
}