#include ".\baseInclude.h"

Trainer::Trainer(std::string name,Pokemon a,Pokemon b,Pokemon c){
    TrainerName = name;
    myPoke[0] = a;
    myPoke[1] = b;
    myPoke[2] = c;
}
std::string Trainer::getTrainerName(){
    return TrainerName;
}
Pokemon* Trainer::getpPokemon(int num){
    return &myPoke[num-1];
}
Pokemon Trainer::getPokemon(int num){
    return myPoke[num-1];
}
Pokemon* Trainer::getpPokemon(){
    return myPoke;
}
Move Trainer::getPokeMove(int p,int m){
    return getPokemon(p).getMove(m);
}
void Trainer::showmyPoke(){
    for(int i=0;i<3;i++){
        std::cout <<i<<myPoke[i].getPokeName()<<std::endl;
    }
}

void Trainer::setTrainer(std::string name,Pokemon* poke3){
    TrainerName = name;
    for(int i=0;i<3;i++){
        myPoke[i].setPokemon(poke3[i]);
    }
}
void Trainer::setMe(Pokemon* all,int numPokemons){
    std::cout << "What your name?"<<std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Your name is "<<name<<'!'<<std::endl;

    std::cout<<'v'<<std::flush;//enterキーの要求
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
    flag = getchar();
    std::cout<<"You have to choose 3 Pokemon!"<<std::endl;
        std::cout<<'v'<<std::flush;//enterキーの要求
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
            flag = getchar();//二週目からはバッファをクリアする
        std::cout << "Choose your Pokemon" << std::endl;
            std::cout<<'v'<<std::flush;//enterキーの要求
            flag = getchar();
        for (int i = 0; i < numPokemons; i++) {
            std::cout << i + 1 << ". " << pokemons[i].getPokeName() << std::endl;
        }
        std::cin >> selection;
        return selection - 1;
    }
    Pokemon Trainer::checkPokemon(Pokemon pokemon, bool* isConfirmed) {
        Pokemon tmp;
        std::cout << "Show the status of " << pokemon.getPokeName() << std::endl;

        std::cout<<'v'<<std::flush;//enterキーの要求
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
        flag = getchar();

        pokemon.showAllST();
            std::cout<<'v'<<std::flush;//enterキーの要求
            flag = getchar();
        std::cout << "OK?" << std::endl;
        if (isYESorNO()) {
            std::cout << "You choose " << pokemon.getPokeName() << std::endl;
                std::cout<<'v'<<std::flush;//enterキーの要求
                flag = getchar();
            tmp = pokemon;
            *isConfirmed = false;
        }
        return tmp;
    }
