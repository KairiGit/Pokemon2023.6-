#include ".\baseInclude.h"

void Master(){
    /*
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
    */

    int numMoves=7;
    Move allMove[7][4];
    setAllMove(allMove);
    int numPokemons=7;
    Pokemon allPokemon[7];
    setAllPokemon(allPokemon,allMove);

    Trainer Me;
    Me.setMe(allPokemon,numPokemons);

    Trainer Hamada("Tan-Pan Kozo HaMaDa",allPokemon[5],allPokemon[2],allPokemon[6]);

    BattleField vsHamada(&Me,&Hamada);
}
