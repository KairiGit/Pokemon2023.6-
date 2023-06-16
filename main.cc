#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#include <enum.h>
#include <Move.h>
#include <something.h>
#include <Poke.h>
#include <Master.h>


void Master(){
    Move Tackle("Tackle",NOM,Physical,40);
    Move Ember("Ember",HON,Spesial,40);
    Move Water_Gun("Water Gun",MIZ,Spesial,40);
    Move Thunderbolt("Thunderbolt",DEN,Spesial,90);
    Move Leafage("Leafage",KUS,Physical,40);

    
    Pokemon a("Eevee",NOM,NOT,130,75,70,65,85,75,Tackle);
    Pokemon b("Charizard",HON,HIK,153,104,98,129,105,120,Ember);
    Pokemon c("Greninja",MIZ,AKU,147,115,87,123,91,142,Water_Gun);
    Pokemon d("Pikachu",DEN,NOT,110,75,60,70,70,110,Thunderbolt);
    Pokemon e("Amoonguss",KUS,DOK,189,105,90,105,100,50,Leafage);
    Pokemon all[5];
    all[0] = a;
    all[1] = b;
    all[2] = c;
    all[3] = d;
    all[4] = e;
    Pokemon my[3];
    Pokemon enemy[3];
    Pokemon tmp; 
    bool still=true;
    //自分のポケモンを選ぶ
    while(still){
        tmp = check(all[select(all)-1],&still);
    }
    my[0] = tmp;
    enemy[0] = b;
    
    bool n =true;
    while(n){
        cout <<"Enemy's "<<enemy[0].getPokeName()<<" used "<<enemy[0].getMove1().getMoveName()<<endl;
        my[0].showNowhp();
        my[0].Moved(enemy[0],enemy[0].getMove1());
        cout << "->";
        my[0].showNowhp();
        if(my[0].getisAlive()){
            n = YN();
        }else{
            cout << my[0].getPokeName() <<" fainted!"<<endl;
            n = false;
        }
    }
}
int main(void){
    Master();
    return 0;
}