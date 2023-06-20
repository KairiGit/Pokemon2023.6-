#include ".\Trainer.h"

Trainer::Trainer(string name,Pokemon a,Pokemon b,Pokemon c){
    TrainerName = name;
    myPoke[0] = a;
    myPoke[1] = b;
    myPoke[2] = c;
}
string Trainer::getTrainerName(){
    return TrainerName;
}
Pokemon* Trainer::getMyPokemon(int num){
    return &myPoke[num-1];
}
void Trainer::showmyPoke(){
    for(int i=0;i<3;i++){
        std::cout <<i<<myPoke[i].getPokeName()<<endl;
    }
}

void Trainer::setTrainer(Pokemon* all,int numPokemons){
    std::cout << "What your name?"<<endl;
    string name;
    cin >> name;
    std::cout << "Your name is "<<name<<'!'<<endl;
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
    std::cout << "Choose your Pokemon" << endl;
    for (int i = 0; i < numPokemons; i++) {
        std::cout << i + 1 << ". " << pokemons[i].getPokeName() << endl;
    }
    cin >> selection;
    return selection - 1;
}
Pokemon Trainer::checkPokemon(Pokemon pokemon, bool* isConfirmed) {
    Pokemon tmp;
    std::cout << "Show the status of " << pokemon.getPokeName() << endl;
    pokemon.showAllST();
    std::cout << "OK?" << endl;
    if (getYesNoAnswer()) {
        std::cout << "You choose " << pokemon.getPokeName() << endl;
        tmp = pokemon;
        *isConfirmed = false;
    }
    return tmp;
}
