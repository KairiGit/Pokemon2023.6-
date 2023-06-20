#include <iostream>
#include <string>
#include ".\select.h"
#include ".\Trainer.h"
using namespace std;

void Master(){

    const string tackle = "Tackle";
    const string ember = "Ember";
    const string water_gun = "Water Gun";
    const string thunderbolt = "Thunderbolt";
    const string leafage = "Leafage";
    const string aura_sphere = "Aura_Sphere";

    
    Move Tackle(tackle,NOM,Physical,40);
    Move Ember(ember,HON,Spesial,40);
    Move Water_Gun("Water Gun",MIZ,Spesial,40);
    Move Thunderbolt("Thunderbolt",DEN,Spesial,90);
    Move Leafage("Leafage",KUS,Physical,40);
    Move Aura_Sphere("Aura_Sphere",KAK,Spesial,80);
    
    Pokemon a("Eevee",NOM,NOT,130,75,70,65,85,75,Tackle);
    Pokemon b("Charizard",HON,HIK,153,104,98,129,105,120,Ember);
    Pokemon c("Greninja",MIZ,AKU,147,115,87,123,91,142,Water_Gun);
    Pokemon d("Pikachu",DEN,NOT,110,75,60,70,70,110,Thunderbolt);
    Pokemon e("Amoonguss",KUS,DOK,189,105,90,105,100,50,Leafage);
    Pokemon f("Lucario",KAK,HAG,70,110,70,115,70,90,Aura_Sphere);

    int AllPokenumber=6;
    Pokemon all[6];
    all[0] = a;
    all[1] = b;
    all[2] = c;
    all[3] = d;
    all[4] = e;
    all[5] = f;
    Pokemon my[3];
    Pokemon enemy[3];
    Pokemon tmp; 
    
    //自分のポケモンを三匹選ぶ
    for(int i=0;i<3;i++){
        bool still=true;
        while(still){
            tmp = check( all[select(all,AllPokenumber)] , &still);
        }
        my[i] = tmp;
        enemy[i] = b;
    } 
    bool n =true;
    while(n){
        //敵の攻撃
        cout <<"Enemy's "<<enemy[0].getPokeName()<<" used "<<enemy[0].getMove(1).getMoveName()<<'!'<<endl;
        my[0].showNowhp();
        my[0].Moved(enemy[0],enemy[0].getMove(1));
        cout << "->";
        my[0].showNowhp();
        if(my[0].getisAlive()){
            n = getYesNoAnswer();
        }else{
            cout << my[0].getPokeName() <<" fainted!"<<endl;
            n = false;
        }
    }
}
