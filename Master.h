#include ".\baseInclude.h"

void Master(){
    int numMoves=7;
    Move allMove[7][4];
    setAllMove(allMove);
    int numPokemons=7;
    Pokemon allPokemon[7];
    setAllPokemon(allPokemon,allMove);
    Trainer Hamada("Tan-Pan Kozo HaMaDa",allPokemon[5],allPokemon[2],allPokemon[6]);
    
    Trainer Masuya("Student Massu~",allPokemon[1],allPokemon[0],allPokemon[3]);
    BattleField tmp(Masuya,Hamada);
    
    Trainer Me;
    Me.setMe(allPokemon,numPokemons);
    

    BattleField vsHamada(Me,Hamada);
}
