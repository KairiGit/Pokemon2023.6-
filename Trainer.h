#include <iostream>
#include <string>
#include ".\select.h"
using namespace std;
class Trainer{
    private:
        string TraiName;
        Pokemon myPoke[3];
    public:
        Trainer(string name,Pokemon a,Pokemon b,Pokemon c);
        string getTraiName();
        Pokemon getmyPoke(int num);
        void showmyPoke();

        void setTrainer(Pokemon* all,int AllPokenumber);
};

Trainer::Trainer(string name,Pokemon a,Pokemon b,Pokemon c){
    TraiName = name;
    myPoke[0] = a;
    myPoke[1] = b;
    myPoke[2] = c;
}
string Trainer::getTraiName(){
    return TraiName;
}
Pokemon Trainer::getmyPoke(int num){
    return myPoke[num-1];
}
void Trainer::showmyPoke(){
    for(int i=0;i<3;i++){
        cout <<i<<myPoke[i].getPokeName()<<endl;
    }
}

void Trainer::setTrainer(Pokemon* all,int AllPokenumber){
    cout << "What your name?"<<endl;
    string name;
    cin >> name;
    cout << "Your name is "<<name<<'!'<<endl;
    for(int i=0;i<3;i++){
        bool still=true;
        while(still){
            myPoke[i] = check( all[select(all,AllPokenumber)] , &still);
        }
    }
}