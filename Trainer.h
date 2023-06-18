#include ".\Poke.h"

class Trainer{
    private:
        string TraiName;
        Pokemon enePoke[3];
    public:
        Trainer(string name,Pokemon a,Pokemon b,Pokemon c);
        string getTraiName();
        Pokemon getenePoke(int num);
        void showenePoke();
};

Trainer::Trainer(string name,Pokemon a,Pokemon b,Pokemon c){
    TraiName = name;
    enePoke[0] = a;
    enePoke[1] = b;
    enePoke[2] = c;
}
string Trainer::getTraiName(){
    return TraiName;
}
Pokemon Trainer::getenePoke(int num){
    return enePoke[num-1];
}
void Trainer::showenePoke(){
    for(int i=0;i<3;i++){
        cout <<i<<enePoke[i].getPokeName()<<endl;
    }
}