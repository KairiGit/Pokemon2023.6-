#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
using namespace std;
enum Type{NOT,NOM,HON,MIZ,DEN,KUS,KOO,KAK,DOK,JIM,HIK,ESU,MUS,IWA,GOS,DRA,AKU,HAG,FEA};//18タイプ
enum Ailment{NOA,PAR,FRZ,PSN,BPSN,BRN};//状態異常
enum Cat{Physical,Spesial,Status};//技の分類
//"\x1b[38;2;" "\x1b[m"
void exType(Type t){
    switch(t){
        case 0: cout <<"ONRY";break;
        case 1: cout <<"\x1b[38;2;255;215;0m"<<"nomaru"<< "\x1b[m";break;
        case 2: cout <<"\x1b[38;2;255;69;0m"<<"hono"<< "\x1b[m";break;
        case 3: cout <<"\x1b[38;2;0;191;255m"<<"mizu"<< "\x1b[m";break;
        case 4: cout <<"\x1b[38;2;255;165;0m"<<"denki"<< "\x1b[m";break;
        case 5: cout <<"\x1b[38;2;127;255;0m"<<"kusa"<< "\x1b[m";break;
        case 6: cout <<"\x1b[38;2;224;255;255m"<<"kori"<< "\x1b[m";break;
        case 7: cout <<"\x1b[38;2;165;42;42m"<<"kakuto"<< "\x1b[m";break;
        case 8: cout <<"\x1b[38;2;106;76;156m"<<"doku"<< "\x1b[m";break;
        case 9: cout <<"\x1b[38;2;184;134;11m"<<"jimen"<< "\x1b[m";break;
        case 10:cout <<"\x1b[38;2;230;230;250m"<<"hikou"<< "\x1b[m";break;
        case 11:cout <<"\x1b[38;2;255;20;147m"<<"esupa"<< "\x1b[m";break;
        case 12:cout <<"\x1b[38;2;145;141;64m"<<"musi"<< "\x1b[m";break;
        case 13:cout <<"\x1b[38;2;240;230;140m"<<"iwa"<< "\x1b[m";break;
        case 14:cout <<"\x1b[38;2;72;61;139m"<<"gosuto"<< "\x1b[m";break;
        case 15:cout <<"\x1b[38;2;0;0;128m"<<"doragon"<< "\x1b[m";break;
        case 16:cout <<"\x1b[38;2;70;70;70m"<<"aku"<< "\x1b[m";break;
        case 17:cout <<"\x1b[38;2;192;192;192m"<<"hagane"<< "\x1b[m";break;
        case 18:cout <<"\x1b[38;2;255;192;203m"<<"feari"<< "\x1b[m";break;
    }
}
bool isYESorNO(){
    int answer;
    std::cout <<1<<'.'<<"YES"<<std::endl;
    std::cout <<2<<'.'<<"NO"<<std::endl;
    std::cin >> answer;
    if(answer==1){return true;}
    else{return false;}
}

class Move{
    private:
        std::string MoveName;
        Type MoveType;
        Cat cat;
        int Pow;
        int Acc;
    protected:
    public:
        Move(const std::string n,Type t,Cat c,int p);
        Move(){}
        void setMove(const std::string n,Type t,Cat c,int p){
            MoveName = n;
            MoveType = t;
            cat = c;
            Pow = p;
        }
        std::string getMoveName(){return MoveName;}
        Type getMoveType(){return MoveType;}
        Cat getCat(){return cat;}
        int getPow(){return Pow;}
        int getAcc(){return Acc;}
};
Move::Move(std::string n,Type t,Cat c,int p){
    MoveName = n;
    MoveType = t;
    cat = c;
    Pow = p;
}
void setAllMove(Move allMove[][4]){
    allMove[0][0].setMove("Tackle",NOM,Physical,40);

    allMove[1][0].setMove("Ember",HON,Spesial,40);

    allMove[2][0].setMove("Water Gun",MIZ,Spesial,40);
    
    allMove[3][0].setMove("Thunderbolt",DEN,Spesial,90);
    
    allMove[4][0].setMove("Leafage",KUS,Physical,40);
    
    allMove[5][0].setMove("Aura_Sphere",KAK,Spesial,80);
    
    allMove[6][0].setMove("ThunderShock",DEN,Spesial,40);

}
class Pokemon{
    private:
    protected:
        std::string PokeName;
        Type fPokeType;
        Type sPokeType;
        //int H,A,B,C,D,S;
        //std::string Ability;
        int Nowhp;
        //int h,a,b,c,d,s;
        int HP,Atk,Def,Sp_Atk,Sp_Def,Speed;
        //Ailment Ail;
        bool isAlive;
        Move m[4];
        
        void die(){isAlive = false;}
        
        int dmg(int atk,int def,int pow){
            int dmg;
            int tmp = 50*2/5 +2;
            tmp = tmp*pow*atk/def;
            tmp = tmp/50 +2;
            dmg =tmp;
            return dmg;
        }
    public:
        Pokemon(std::string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed,Move move){
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
        
        std::string getPokeName(){return PokeName;}
        Type getfPokeType(){return fPokeType;}
        Type getsPokeType(){return sPokeType;}
        //std::string getAbility();
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


        void setPokemon(std::string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed,Move move);
        void setPokemon(Pokemon* x);
        void setPokeMove(Move* x);

        void Attacked(Pokemon atk,Move w);
        void spAttacked(Pokemon atk,Move w);
        void Moved(Pokemon atk,Move w);

        void showNowhp();
        void showPokeType();
        void showStats();
        void showMove();
        void showAllST();
};
void Pokemon :: setPokemon(std::string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed,Move move){
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
void Pokemon :: setPokemon(Pokemon* x){
    PokeName = x->getPokeName();
    fPokeType = x->getfPokeType();
    sPokeType = x->getsPokeType();
    Nowhp = x->getHP();
    HP = x->getHP();
    Atk = x->getAtk();
    Def = x->getDef();
    Sp_Atk = x->getSp_Atk();
    Sp_Def = x->getSp_Def();
    Speed = x->getSpeed();
    m[0] = x->getMove(1);
    isAlive = true;    
}

void Pokemon :: setPokeMove(Move* x){
    for(int i=0;i<4;i++){
        m[i].setMove(x[i].getMoveName(),x[i].getMoveType(),x[i].getCat(),x[i].getPow());
    }
}

void Pokemon :: Attacked(Pokemon atk,Move w){
    Nowhp = Nowhp - dmg(atk.getAtk(),Def,w.getPow());
}
void Pokemon :: spAttacked(Pokemon atk,Move w){
    Nowhp = Nowhp - dmg(atk.getSp_Atk(),Sp_Def,w.getPow());
}
void Pokemon :: Moved(Pokemon atk,Move w){
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
void Pokemon :: showNowhp(){
    if(Nowhp>HP/2){std::cout <<"\x1b[38;2;0;255;0m"<<Nowhp<<"\x1b[m"<<std::endl;}
    else if(Nowhp>HP/4){std::cout <<"\x1b[38;2;255;255;0m"<<Nowhp<<"\x1b[m"<<std::endl;}
    else{std::cout <<"\x1b[38;2;255;0;0m"<<Nowhp<<"\x1b[m"<<std::endl;}
}
void Pokemon :: showPokeType(){
    exType(fPokeType);
    std::cout <<'/';
    exType(sPokeType);
    std::cout <<std::endl;
}
void Pokemon :: showStats(){
    std::cout <<'H'<<getHP()<<' '<<'A'<<getAtk()<<' '<<'B'<<getDef()<<' '<<'C'<<getSp_Atk()<<' '<<'D'<<getSp_Def()<<' '<<'S'<<getSpeed()<<std::endl;
}

void Pokemon :: showMove(){
    for(int i=0;i<4;i++){
        std::cout <<i+1<< m[i].getMoveName() <<std::endl;
    }
}
void Pokemon :: showAllST(){
    std::cout <<std::endl;
    std::cout <<"Type is ";
    exType(fPokeType);
    std::cout <<'/';
    exType(sPokeType);
    std::cout <<std::endl;
    std::cout <<"Status is "<<'H'<<getHP()<<' '<<'A'<<getAtk()<<' '<<'B'<<getDef()<<' '<<'C'<<getSp_Atk()<<' '<<'D'<<getSp_Def()<<' '<<'S'<<getSpeed()<<std::endl;
    std::cout <<"Move is"<<std::endl;
    for(int i=0;i<4;i++){
        std::cout <<i+1<<':'<< m[i].getMoveName() <<std::endl;
    }
    std::cout <<std::endl;
}
void setAllPokemon(Pokemon* allPokemon,Move allMove[][4]){
    allPokemon[0].setPokemon("Eievui",NOM,NOT,130,75,70,65,85,75,allMove[0][0]);
    allPokemon[1].setPokemon("Lizardon",HON,HIK,153,104,98,129,105,120,allMove[1][0]);
    allPokemon[2].setPokemon("Gekkouga",MIZ,AKU,147,115,87,123,91,142,allMove[2][0]);
    allPokemon[3].setPokemon("Pikachu",DEN,NOT,110,75,60,70,70,110,allMove[3][0]);
    allPokemon[4].setPokemon("Morobareru",KUS,DOK,189,105,90,105,100,50,allMove[4][0]);
    allPokemon[5].setPokemon("Lucario",KAK,HAG,70,110,70,115,70,90,allMove[5][0]);
    allPokemon[6].setPokemon("Malurumine",DEN,NOT,135,70,90,100,100,170,allMove[6][0]);
}
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
Trainer::Trainer(std::string name,Pokemon a,Pokemon b,Pokemon c){
    TrainerName = name;
    myPoke[0] = a;
    myPoke[1] = b;
    myPoke[2] = c;
}
std::string Trainer::getTrainerName(){
    return TrainerName;
}
Pokemon* Trainer::getMyPokemon(int num){
    return &myPoke[num-1];
}
void Trainer::showmyPoke(){
    for(int i=0;i<3;i++){
        std::cout <<i<<myPoke[i].getPokeName()<<std::endl;
    }
}

void Trainer::setTrainer(Pokemon* all,int numPokemons){
    std::cout << "What your name?"<<std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Your name is "<<name<<'!'<<std::endl;
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
    std::cout << "Choose your Pokemon" << std::endl;
    for (int i = 0; i < numPokemons; i++) {
        std::cout << i + 1 << ". " << pokemons[i].getPokeName() << std::endl;
    }
    std::cin >> selection;
    return selection - 1;
}
Pokemon Trainer::checkPokemon(Pokemon pokemon, bool* isConfirmed) {
    Pokemon tmp;
    std::cout << "Show the status of " << pokemon.getPokeName() << std::endl;
    pokemon.showAllST();
    std::cout << "OK?" << std::endl;
    if (isYESorNO()) {
        std::cout << "You choose " << pokemon.getPokeName() << std::endl;
        tmp = pokemon;
        *isConfirmed = false;
    }
    return tmp;
}
class BattleField{
    private:
        Trainer* A;
        Trainer* B;
    private:
        void checkPokemon(bool which);
        void BattleStart();
        void selectAction();
        
        void Battle();
    public:
        BattleField(Trainer* A,Trainer* B);      
};
void BattleField::BattleStart(){
    std::cout<<B->getTrainerName();
    std::cout<<" wants to fight!"<<std::endl;

    std::cout<<B->getTrainerName()<<" sent out ";
    std::cout<<B->getMyPokemon(1)->getPokeName();
    std::cout<<'!'<<std::endl;

    std::cout<<"Go! ";
    std::cout<<A->getMyPokemon(1)->getPokeName();
    std::cout<<'!'<<std::endl;    
}
void BattleField :: selectAction(){

}
void BattleField :: checkPokemon(bool which){
    if(which){
        for(int i=0;i<3;i++){
            std::cout << i+1 << A->getMyPokemon(i)->getPokeName() << std::endl;
        }
    }
    else{
        for(int i=0;i<3;i++){
            std::cout << i+1 << B->getMyPokemon(i)->getPokeName() << std::endl;
        }
    }
}
void Master(){
    /*
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
    */

    int numMoves=7;
    Move allMove[7][4];
    setAllMove(allMove);
    int numPokemons=7;
    Pokemon allPokemon[7];
    setAllPokemon(allPokemon,allMove);

    Trainer Me;
    Me.setTrainer(allPokemon,numPokemons);

    Trainer Hamada("Tan-Pan Kozo HaMaDa",allPokemon[5],allPokemon[2],allPokemon[6]);

    bool n =true;
    while(n){
        std::cout <<Hamada.getTrainerName()<<"`s "<<Hamada.getMyPokemon(1)->getPokeName()<<" used "<<Hamada.getMyPokemon(1)->getMove(1).getMoveName()<<std::endl;
        Me.getMyPokemon(1)->showNowhp();
        
        Me.getMyPokemon(1)->Moved( *Hamada.getMyPokemon(1) , Hamada.getMyPokemon(1)->getMove(1) );
        std::cout << "->";
        Me.getMyPokemon(1)->showNowhp();
        if(Me.getMyPokemon(1)->getisAlive()){n = isYESorNO();}
        else{
            std::cout << Me.getMyPokemon(1)->getPokeName() <<" fainted!"<<std::endl;
            n = false;
        }
    }
}
int main(void){
    Master();
    return 0;
}

