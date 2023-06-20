#include ".\Trainer.h"

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
        std::cout <<Hamada.getTrainerName()<<"`s"<<Hamada.getMyPokemon(1)->getPokeName()<<" used "<<Hamada.getMyPokemon(1)->getMove(1).getMoveName()<<std::endl;
        Me.getMyPokemon(1)->showNowhp();
        
        Me.getMyPokemon(1)->Moved( *Hamada.getMyPokemon(1) , Hamada.getMyPokemon(1)->getMove(1) );
        std::cout << "->";
        Me.getMyPokemon(1)->showNowhp();
        if(Me.getMyPokemon(1)->getisAlive()){n = isYESorNO();}
        else{
            std::cout << Me.getMyPokemon(1)->getPokeName() <<" fainted!"<<std::endl;
            n = false;
        }
    }
}
