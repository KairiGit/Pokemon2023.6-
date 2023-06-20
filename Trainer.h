#pragma once
#include ".\Poke.h"
class Trainer{
    private:
        std::string TrainerName;
        Pokemon myPoke[3];
//ヘルパー
        int selectPokemon(Pokemon* pokemons, int numPokemons);// ポケモンの選択肢を表示し、ユーザーの選択を取得する関数
        Pokemon checkPokemon(Pokemon pokemon, bool* isConfirmed);// ポケモンのステータスを表示し、確認後の処理を行う関数
    public:
        Trainer(std::string name,Pokemon a,Pokemon b,Pokemon c);
        Trainer(){}
        std::string getTrainerName();
        Pokemon* getMyPokemon(int num);
        void showmyPoke();

        void setTrainer(Pokemon* all,int numPokemons);
};
