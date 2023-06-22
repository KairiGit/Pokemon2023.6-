#include ".\Trainer.h"
class BattleField{
    private:
        Trainer* A;
        Trainer* B;
    public:
        BattleField(Trainer* A,Trainer* B);
        void showPokemon(bool which);
        
        void Battle();
};