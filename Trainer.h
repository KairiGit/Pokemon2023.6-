#include <iostream>
#include <string>
#include ".\Poke.h"
using namespace std;
class Trainer{
    private:
        string TrainerName;
        Pokemon myPoke[3];
//ヘルパー
        int selectPokemon(Pokemon* pokemons, int numPokemons);// ポケモンの選択肢を表示し、ユーザーの選択を取得する関数
        Pokemon checkPokemon(Pokemon pokemon, bool* isConfirmed);// ポケモンのステータスを表示し、確認後の処理を行う関数
    public:
        Trainer(string name,Pokemon a,Pokemon b,Pokemon c);
        Trainer(){}
        string getTrainerName();
        Pokemon* getmyPoke(int num);
        void showmyPoke();

        void setTrainer(Pokemon* all,int numPokemons);
};

Trainer::Trainer(string name,Pokemon a,Pokemon b,Pokemon c){
    TrainerName = name;
    myPoke[0] = a;
    myPoke[1] = b;
    myPoke[2] = c;
}
string Trainer::getTrainerName(){
    return TrainerName;
}
Pokemon* Trainer::getmyPoke(int num){
    return &myPoke[num-1];
}
void Trainer::showmyPoke(){
    for(int i=0;i<3;i++){
        cout <<i<<myPoke[i].getPokeName()<<endl;
    }
}

void Trainer::setTrainer(Pokemon* all,int numPokemons){
    cout << "What your name?"<<endl;
    string name;
    cin >> name;
    cout << "Your name is "<<name<<'!'<<endl;
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
    cout << "Choose your Pokemon" << endl;
    for (int i = 0; i < numPokemons; i++) {
        cout << i + 1 << ". " << pokemons[i].getPokeName() << endl;
    }
    cin >> selection;
    return selection - 1;
}
Pokemon Trainer::checkPokemon(Pokemon pokemon, bool* isConfirmed) {
    Pokemon tmp;
    cout << "Show the status of " << pokemon.getPokeName() << endl;
    pokemon.showAllST();
    cout << "OK?" << endl;
    if (getYesNoAnswer()) {
        cout << "You choose " << pokemon.getPokeName() << endl;
        tmp = pokemon;
        *isConfirmed = false;
    }
    return tmp;
}
