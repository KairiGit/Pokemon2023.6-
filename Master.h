
#include ".\Trainer.h"
using namespace std;

void Master(){

    
    Move Tackle("Tackle",NOM,Physical,40);
    Move Ember("Ember",HON,Spesial,40);
    Move Water_Gun("Water Gun",MIZ,Spesial,40);
    Move Thunderbolt("Thunderbolt",DEN,Spesial,90);
    Move Leafage("Leafage",KUS,Physical,40);
    Move Aura_Sphere("Aura_Sphere",KAK,Spesial,80);
    Move ThunderShock("ThunderShock",DEN,Spesial,40);
    
    Pokemon a("Eievui",NOM,NOT,130,75,70,65,85,75,Tackle);
    Pokemon b("Lizardon",HON,HIK,153,104,98,129,105,120,Ember);
    Pokemon c("Gekkouga",MIZ,AKU,147,115,87,123,91,142,Water_Gun);
    Pokemon d("Pikachu",DEN,NOT,110,75,60,70,70,110,Thunderbolt);
    Pokemon e("Morobareru",KUS,DOK,189,105,90,105,100,50,Leafage);
    Pokemon f("Lucario",KAK,HAG,70,110,70,115,70,90,Aura_Sphere);
    Pokemon g("Malurumine",DEN,NOT,135,70,90,100,100,170,ThunderShock);

    int numPokemons=7;
    Pokemon all[7];
    all[0] = a;
    all[1] = b;
    all[2] = c;
    all[3] = d;
    all[4] = e;
    all[5] = f;
    all[6] = g;
    Trainer Me;
    Me.setTrainer(all,numPokemons);

    Trainer Hamada("Tan-Pan Kozo HaMaDa",f,c,g);
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
