#include ".\Trainer.h"

Trainer::Trainer(std::string name,Pokemon a,Pokemon b,Pokemon c){
    TrainerName = name;
    myPoke[0] = a;
    myPoke[1] = b;
    myPoke[2] = c;
}
std::string Trainer::getTrainerName(){
    return TrainerName;
}
Pokemon* Trainer::getMyPokemon(int num){
    return &myPoke[num-1];
}
void Trainer::showmyPoke(){
    for(int i=0;i<3;i++){
        std::cout <<i<<myPoke[i].getPokeName()<<std::endl;
    }
}

void Trainer::setTrainer(Pokemon* all,int numPokemons){
    std::cout << "What your name?"<<std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Your name is "<<name<<'!'<<std::endl;
    for(int i=0;i<3;i++){
        bool still=true;
        while(still){
            myPoke[i] = checkPokemon( all[selectPokemon(all,numPokemons)] , &still);
        }
    }
}
//ヘルパー
int Trainer::selectPokemon(Pokemon* pokemons, int numPokemons) {
    int selection;
    std::cout << "Choose your Pokemon" << std::endl;
    for (int i = 0; i < numPokemons; i++) {
        std::cout << i + 1 << ". " << pokemons[i].getPokeName() << std::endl;
    }
    std::cin >> selection;
    return selection - 1;
}
Pokemon Trainer::checkPokemon(Pokemon pokemon, bool* isConfirmed) {
    Pokemon tmp;
    std::cout << "Show the status of " << pokemon.getPokeName() << std::endl;
    pokemon.showAllST();
    std::cout << "OK?" << std::endl;
    if (getYesNoAnswer()) {
        std::cout << "You choose " << pokemon.getPokeName() << std::endl;
        tmp = pokemon;
        *isConfirmed = false;
    }
    return tmp;
}
