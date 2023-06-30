#pragma once
#include ".\Pokemon.hpp"

void setAllPokemon(Pokemon* allPokemon,Move allMove[][4]){
    allPokemon[0].setPokemon("Eievui",NOM,NOT,130,75,70,65,85,75,allMove[0][0]);
    allPokemon[1].setPokemon("Lizardon",HON,HIK,153,104,98,129,105,120,allMove[1][0]);
    allPokemon[2].setPokemon("Gekkouga",MIZ,AKU,147,115,87,123,91,142,allMove[2][0]);
    allPokemon[3].setPokemon("Pikachu",DEN,NOT,110,75,60,70,70,110,allMove[3][0]);
    allPokemon[4].setPokemon("Morobareru",KUS,DOK,189,105,90,105,100,50,allMove[4][0]);
    allPokemon[5].setPokemon("Lucario",KAK,HAG,70,110,70,115,70,90,allMove[5][0]);
    allPokemon[6].setPokemon("Malurumine",DEN,NOT,135,70,90,100,100,170,allMove[6][0]);
}