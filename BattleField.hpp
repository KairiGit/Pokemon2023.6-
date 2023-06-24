#include ".\Trainer.h"
class BattleField{
    private:
        Trainer* A;
        Trainer* B;
        
    private://コンストラクタで呼び出されるヘルパー
        void checkPokemon(bool which);
        void BattleStart();
        void selectAction();
        
        void Battle();
    public:
        BattleField(Trainer* A,Trainer* B);      
};