#include ".\Trainer.h"
class BattleField{
    private:
        Trainer A;
        Trainer B;
        Pokemon nowBattleA;
        Pokemon nowBattleB;
        
        bool inBattle;
        bool selected;
    private://コンストラクタで呼び出されるヘルパー
        void checkPokemon(bool which);
        void BattleStart();
        void selectAction();
        void Fight();
        void Check();
        void checkPokemon(bool which);
        void checkField();
        void Surrender();
        void Battle();
    public:
        BattleField(Trainer A,Trainer B);      
};