#include <iostream>
#include <string>
#include <cmath>
using namespace std;
enum Type{NOT,NOM,HON,MIZ,DEN,KUS,KOO,KAK,DOK,JIM,HIK,ESU,MUS,IWA,GOS,DRA,AKU,HAG,FEA};//18タイプ
enum Ailment{NOA,PAR,FRZ,PSN,BPSN,BRN};//状態異常
enum Cat{Physical,Spesial,Status};//技の分類
//"\x1b[38;2;" "\x1b[m"
void exType(Type t){
    switch(t){
        case 0: cout <<"ONRY";break;
        case 1: cout <<"\x1b[38;2;255;255;205m"<<"nomaru"<< "\x1b[m";break;
        case 2: cout <<"\x1b[38;2;255;69;0m"<<"hono"<< "\x1b[m";break;
        case 3: cout <<"\x1b[38;2;0;191;255m"<<"mizu"<< "\x1b[m";break;
        case 4: cout <<"\x1b[38;2;255;255;55m"<<"denki"<< "\x1b[m";break;
        case 5: cout <<"\x1b[38;2;127;255;0m"<<"kusa"<< "\x1b[m";break;
        case 6: cout <<"\x1b[38;2;180;206;255m"<<"kori"<< "\x1b[m";break;
        case 7: cout <<"\x1b[38;2;165;42;42m"<<"kakuto"<< "\x1b[m";break;
        case 8: cout <<"\x1b[38;2;116;83;171m"<<"doku"<< "\x1b[m";break;
        case 9: cout <<"\x1b[38;2;184;134;11m"<<"jimen"<< "\x1b[m";break;
        case 10:cout <<"\x1b[38;2;220;220;255m"<<"hikou"<< "\x1b[m";break;
        case 11:cout <<"\x1b[38;2;255;20;147m"<<"esupa"<< "\x1b[m";break;
        case 12:cout <<"\x1b[38;2;145;141;64m"<<"musi"<< "\x1b[m";break;
        case 13:cout <<"\x1b[38;2;240;230;140m"<<"iwa"<< "\x1b[m";break;
        case 14:cout <<"\x1b[38;2;72;61;139m"<<"gosuto"<< "\x1b[m";break;
        case 15:cout <<"\x1b[38;2;0;30;155m"<<"doragon"<< "\x1b[m";break;
        case 16:cout <<"\x1b[38;2;70;70;70m"<<"aku"<< "\x1b[m";break;
        case 17:cout <<"\x1b[38;2;205;205;205m"<<"hagane"<< "\x1b[m";break;
        case 18:cout <<"\x1b[38;2;255;180;195"<<"feari"<< "\x1b[m";break;
    }
}

class Move{
    private:
        string MoveName;
        Type MoveType;
        Cat cat;
        int Pow;
        int Acc;
    protected:
    public:
        Move(string n,Type t,Cat c,int p){
            MoveName = n;
            MoveType = t;
            cat = c;
            Pow = p;
        }
        Move(){}
        void setMove(string n,Type t,Cat c,int p){
            MoveName = n;
            MoveType = t;
            cat = c;
            Pow = p;
        }
        string getMoveName(){return MoveName;}
        Type getMoveType(){return MoveType;}
        Cat getCat(){return cat;}
        int getPow(){return Pow;}
        int getAcc(){return Acc;}
};
    /*class MoveATK : public Move{
        private:
            int Pow;
            int Contact;
    };
    class MoveStats : public Move{};*/


class Pokemon{
    private:
        string PokeName;
        Type fPokeType;
        Type sPokeType;
        //int H,A,B,C,D,S;
        //string Ability;
        int Nowhp;
        //int h,a,b,c,d,s;
        int HP,Atk,Def,Sp_Atk,Sp_Def,Speed;
        //Ailment Ail;
        bool isAlive;

        Move m[4];
        
        void die(){
            isAlive = false;
        }
        int dmg(int atk,int def,int pow){
            int dmg;
            int tmp = 50*2/5 +2;
            tmp = tmp*pow*atk/def;
            tmp = tmp/50 +2;
            dmg =tmp;
            return dmg;
        }
    public:
        Pokemon(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed,Move move){
            PokeName = name;
            fPokeType = f;
            sPokeType = s;
            Nowhp = hp;
            HP = hp;
            Atk = atk;
            Def = def;
            Sp_Atk = sp_atk;
            Sp_Def = sp_def;
            Speed = speed;
            m[0] = move;
            isAlive = true;
        }
        Pokemon(){}
        //void setPokemon(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed);
        void setPokeMove(Move* x);
        string getPokeName(){return PokeName;}
        Type getfPokeType(){return fPokeType;}
        Type getsPokeType(){return sPokeType;}
        //string getAbility();
        int getNowhp(){return Nowhp;}
        int getHP(){return HP;}
        int getAtk(){return Atk;}
        int getDef(){return Def;}
        int getSp_Atk(){return Sp_Atk;}
        int getSp_Def(){return Sp_Def;}
        int getSpeed(){return Speed;}
        //int getAil();
        Move getMove(int num){return m[num-1];}

        bool getisAlive(){return isAlive;}
        
        void Attacked(Pokemon atk,Move w){
            Nowhp = Nowhp - dmg(atk.getAtk(),Def,w.getPow());
        }
        void spAttacked(Pokemon atk,Move w){
            Nowhp = Nowhp - dmg(atk.getSp_Atk(),Sp_Def,w.getPow());
        }
        void Moved(Pokemon atk,Move w){
            switch(w.getCat()){
                case 0: Attacked(atk,w);break;
                case 1: spAttacked(atk,w);break;
                case 2: break;
            }
            if(Nowhp<=0){
                Nowhp = 0;
                die();
            }
        }
        //"\x1b[38;2;" "\x1b[m"
        void showNowhp(){
            if(Nowhp>HP/2){cout <<"\x1b[38;2;0;255;0m"<<Nowhp<<"\x1b[m"<<endl;}
            else if(Nowhp>HP/4){cout <<"\x1b[38;2;255;255;0m"<<Nowhp<<"\x1b[m"<<endl;}
            else{cout <<"\x1b[38;2;255;0;0m"<<Nowhp<<"\x1b[m"<<endl;}
        }
        void showPokeType(){
            exType(fPokeType);
            cout <<'/';
            exType(sPokeType);
            cout <<endl;
        }
        void showStats(){
            cout <<'H'<<getHP()<<' '<<'A'<<getAtk()<<' '<<'B'<<getDef()<<' '<<'C'<<getSp_Atk()<<' '<<'D'<<getSp_Def()<<' '<<'S'<<getSpeed()<<endl;
        }
        void showMove(){
            cout <<1<<':'<< m[0].getMoveName() <<endl;
            cout <<2<<':'<< m[1].getMoveName() <<endl;
            cout <<3<<':'<< m[2].getMoveName() <<endl;
            cout <<4<<':'<< m[3].getMoveName() <<endl;
        }
        void showAllST(){
            cout <<endl;
            cout <<"Type is ";
            exType(fPokeType);
            cout <<'/';
            exType(sPokeType);
            cout <<endl;
            cout <<"Status is "<<'H'<<getHP()<<' '<<'A'<<getAtk()<<' '<<'B'<<getDef()<<' '<<'C'<<getSp_Atk()<<' '<<'D'<<getSp_Def()<<' '<<'S'<<getSpeed()<<endl;
            cout <<"Move is"<<endl;
            for(int i=0;i<4;i++){
                cout <<i+1<<':'<< m[i].getMoveName() <<endl;
            }
            
            cout <<endl;
        }
};
    
        void Pokemon :: setPokeMove(Move* x){
    for(int i=0;i<4;i++){
        m[i].setMove(x[i].getMoveName(),x[i].getMoveType(),x[i].getCat(),x[i].getPow());
    }
}


// Yes/Noの質問に対する回答を取得する関数
bool getYesNoAnswer() {
    int answer;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> answer;
    if (answer == 1) {return true;}
    else {return false;}
}


class Trainer {
private:
    string trainerName;
    Pokemon myPokemon[3];
    
    //ヘルパー
    int selectPokemon(Pokemon* pokemons, int numPokemons);// ポケモンの選択肢を表示し、ユーザーの選択を取得する関数
    Pokemon checkPokemon(Pokemon pokemon, bool* isConfirmed);// ポケモンのステータスを表示し、確認後の処理を行う関数
public:
    Trainer(string name, Pokemon pokemon1, Pokemon pokemon2, Pokemon pokemon3);
    Trainer() {}
    string getTrainerName();
    Pokemon getMyPokemon(int index);
    void showMyPokemon();
    void setTrainer(Pokemon* allPokemons, int numPokemons);
};

Trainer::Trainer(string name, Pokemon pokemon1, Pokemon pokemon2, Pokemon pokemon3) {
    trainerName = name;
    myPokemon[0] = pokemon1;
    myPokemon[1] = pokemon2;
    myPokemon[2] = pokemon3;
}

string Trainer::getTrainerName() {
    return trainerName;
}

Pokemon Trainer::getMyPokemon(int index) {
    return myPokemon[index - 1];
}

void Trainer::showMyPokemon() {
    for (int i = 0; i < 3; i++) {
        cout << i << myPokemon[i].getPokeName() << endl;
    }
}

void Trainer::setTrainer(Pokemon* allPokemons, int numPokemons) {
    cout << "What is your name?" << endl;
    string name;
    cin >> name;
    cout << "Your name is " << name <<'!'<<endl;
    for(int i=0;i<3;i++){
        bool still=true;
        while(still){
            myPoke[i] = check( all[select(all,AllPokenumber)] , &still);
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

//「はい」か「いいえ」を選ぶ関数


//主な動作をする関数
void Master(){
    Move Tackle("Tackle",NOM,Physical,40);
    Move Ember("Ember",HON,Spesial,40);
    Move Water_Gun("Water Gun",MIZ,Spesial,40);
    Move Thunderbolt("Thunderbolt",DEN,Spesial,90);
    Move Leafage("Leafage",KUS,Physical,40);
    Move Aura_Sphere("Aura_Sphere",KAK,Spesial,80);
    Move ThunderShock("ThunderShock",DEN,Spesial,40);
    
    Pokemon a("Eievui",NOM,NOT,130,75,70,65,85,75,Tackle);
    Pokemon b("Lizardon",HON,HIK,153,104,98,129,105,120,Ember);
    Pokemon c("Gekkouga",MIZ,AKU,147,115,87,123,91,142,Water_Gun);
    Pokemon d("Pikachu",DEN,NOT,110,75,60,70,70,110,Thunderbolt);
    Pokemon e("Morobareru",KUS,DOK,189,105,90,105,100,50,Leafage);
    Pokemon f("Lucario",KAK,HAG,70,110,70,115,70,90,Aura_Sphere);
    Pokemon g("Malurumine",DEN,NOT,135,70,90,100,100,170,ThunderShock);

    int AllPokenumber=7;
    Pokemon all[7];
    all[0] = a;
    all[1] = b;
    all[2] = c;
    all[3] = d;
    all[4] = e;
    all[5] = f;
    all[6] = g;

    Trainer Me;
    Me.setTrainer(all,AllPokenumber);

    Trainer Hamada("Tan-Pan Kozo HaMaDa",f,c,g);
   
    
    //EnePoke uno("Pikachu",DEN,NOT,110,75,60,70,70,110,Thunderbolt);
    bool n =true;
    while(n){
        cout <<Hamada.getTraiName()<<"`s"<<Hamada.getmyPoke(1).getPokeName()<<" used "<<Hamada.getmyPoke(1).getMove(1).getMoveName()<<endl;
        Me.getmyPoke(1).showNowhp();
        //実行時エラー　ダメージを受けてない
        Me.getmyPoke(1).Moved( Hamada.getmyPoke(1) , Hamada.getmyPoke(1).getMove(1) );

        cout << "->";
        Me.getmyPoke(1).showNowhp();
        if(Me.getmyPoke(1).getisAlive()){n = YN();}
        else{
            cout << Me.getmyPoke(1).getPokeName() <<" fainted!"<<endl;
            n = false;
        }
    }
    
}

int main(void){
    Master();
    return 0;
}
