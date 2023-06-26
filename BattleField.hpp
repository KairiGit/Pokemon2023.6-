#pragma once
#include ".\Trainer.h"
class BattleField{
    private:
        Trainer A;
        Trainer B;
        Pokemon nowBattleA;
        Pokemon nowBattleB;
        int Anum;
        int Bnum;
        Move tmpMoveA;
        Move tmpMoveB;
        
        bool inBattle;
        bool selected;
    private://コンストラクタで呼び出されるヘルパー
        void checkPokemon(bool which);
        void BattleStart();
        void selectAction();
        void BattleMove();
        void PokeChenge();
        void Check();
        void checkField();
        void Run();
        void Battle();
    public:
        BattleField(Trainer A,Trainer B);      
};