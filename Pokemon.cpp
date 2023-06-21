#include <iostream>
#include <string>
#include <cmath>
enum Type{NOT,NOM,HON,MIZ,DEN,KUS,KOO,KAK,DOK,JIM,HIK,ESU,MUS,IWA,GOS,DRA,AKU,HAG,FEA};//18タイプ
enum Ailment{NOA,PAR,FRZ,PSN,BPSN,BRN};//状態異常
enum Cat{Physical,Spesial,Status};//技の分類
//"\x1b[38;2;" "\x1b[m"

//タイプ型の入力に対し、色を付けてタイプの名前を出力する関数
void exType(Type t){
    switch(t){
        case 0: std::cout <<"ONRY";break;
        case 1: std::cout <<"\x1b[38;2;255;255;205m"<<"nomaru"<< "\x1b[m";break;
        case 2: std::cout <<"\x1b[38;2;255;69;0m"<<"hono"<< "\x1b[m";break;
        case 3: std::cout <<"\x1b[38;2;0;191;255m"<<"mizu"<< "\x1b[m";break;
        case 4: std::cout <<"\x1b[38;2;255;255;55m"<<"denki"<< "\x1b[m";break;
        case 5: std::cout <<"\x1b[38;2;127;255;0m"<<"kusa"<< "\x1b[m";break;
        case 6: std::cout <<"\x1b[38;2;180;206;255m"<<"kori"<< "\x1b[m";break;
        case 7: std::cout <<"\x1b[38;2;165;42;42m"<<"kakuto"<< "\x1b[m";break;
        case 8: std::cout <<"\x1b[38;2;116;83;171m"<<"doku"<< "\x1b[m";break;
        case 9: std::cout <<"\x1b[38;2;184;134;11m"<<"jimen"<< "\x1b[m";break;
        case 10:std::cout <<"\x1b[38;2;220;220;255m"<<"hikou"<< "\x1b[m";break;
        case 11:std::cout <<"\x1b[38;2;255;20;147m"<<"esupa"<< "\x1b[m";break;
        case 12:std::cout <<"\x1b[38;2;145;141;64m"<<"musi"<< "\x1b[m";break;
        case 13:std::cout <<"\x1b[38;2;240;230;140m"<<"iwa"<< "\x1b[m";break;
        case 14:std::cout <<"\x1b[38;2;72;61;139m"<<"gosuto"<< "\x1b[m";break;
        case 15:std::cout <<"\x1b[38;2;0;30;155m"<<"doragon"<< "\x1b[m";break;
        case 16:std::cout <<"\x1b[38;2;70;70;70m"<<"aku"<< "\x1b[m";break;
        case 17:std::cout <<"\x1b[38;2;205;205;205m"<<"hagane"<< "\x1b[m";break;
        case 18:std::cout <<"\x1b[38;2;255;180;195"<<"feari"<< "\x1b[m";break;
    }
}

//ポケモンの技を管理するクラス
class Move{
    private:
        std::string MoveName;
        Type MoveType;
        Cat cat;
        int Pow;
        int Acc;
    protected:
    public:
        Move(std::string n,Type t,Cat c,int p){
            MoveName = n;
            MoveType = t;
            cat = c;
            Pow = p;
        }
        Move(){}
        void setMove(std::string n,Type t,Cat c,int p){
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
    /*class MoveATK : public Move{
        private:
            int Pow;
            int Contact;
    };
    class MoveStats : public Move{};*/

//ポケモンを管理するクラス
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
    //残りHPの割合に応じて色を付けてHPを出力する関数
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


// Yes/Noの質問に対する回答を取得する関数
bool isYESorNO() {
    int answer;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    std::cin >> answer;
    if (answer == 1) {return true;}
    else {return false;}
}


class Trainer {
private://メンバ変数
    std::string trainerName;
    Pokemon myPoke[3];
private://ヘルパー
    int selectPokemon(Pokemon* pokemons, int numPokemons);// ポケモンの選択肢を表示し、ユーザーの選択を取得するヘルパー関数
    Pokemon checkPokemon(Pokemon pokemon, bool* isConfirmed);// ポケモンのステータスを表示し、確認後の処理を行うヘルパー関数
public:
    Trainer(std::string name, Pokemon pokemon1, Pokemon pokemon2, Pokemon pokemon3);
    Trainer() {}
    std::string getTrainerName();
    Pokemon* getMyPokemon(int index);
    void showMyPokemon();
    void setTrainer(Pokemon* allPokemons, int numPokemons);
};
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

    Trainer::Trainer(std::string name, Pokemon pokemon1, Pokemon pokemon2, Pokemon pokemon3) {
        trainerName = name;
        myPoke[0] = pokemon1;
        myPoke[1] = pokemon2;
        myPoke[2] = pokemon3;
    }

    std::string Trainer::getTrainerName() {
        return trainerName;
    }
    //ポインタにしないとNowhpの管理ができない
    Pokemon* Trainer::getMyPokemon(int index) {
        return &myPoke[index - 1];
    }

    void Trainer::showMyPokemon() {
        for (int i = 0; i < 3; i++) {
            std::cout << i << myPoke[i].getPokeName() << std::endl;
        }
    }

    void Trainer::setTrainer(Pokemon* allPokemons, int numPokemons) {
    std::cout << "What is your name?" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "Your name is " << name <<'!'<<std::endl;
    for(int i=0;i<3;i++){
        bool still=true;
        while(still){
            myPoke[i] = checkPokemon( allPokemons[selectPokemon(allPokemons,numPokemons)] , &still);
        }
    }
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


class BattleField{
    private:
        Trainer* A;
        Trainer* B;
    public:
        BattleField(Trainer* A,Trainer* B);
        void showPokemon(bool which);
        
};
    BattleField::BattleField(Trainer* a,Trainer* b){
        for(int i=0;i<3;i++){
            this->A->getMyPokemon(i)->setPokemon(a->getMyPokemon(i));
            this->B->getMyPokemon(i)->setPokemon(b->getMyPokemon(i));
        }
    }
    void BattleField :: showPokemon(bool which){
        if(which){
            for(int i=0;i<3;i++){
                std::cout << i+1 << A->getMyPokemon(i) << std::endl;
            }
        }
        else{
            for(int i=0;i<3;i++){
                std::cout << i+1 << B->getMyPokemon(i) << std::endl;
            }
        }
    }


//一人プレイ
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

    int numPokemons=7;
    Pokemon all[7];
    all[0] = a;
    all[1] = b;
    all[2] = c;
    all[3] = d;
    all[4] = e;
    all[5] = f;
    all[6] = g;

    Trainer Me;
    Me.setTrainer(all,numPokemons);

    Trainer Hamada("Tan-Pan Kozo HaMaDa",f,c,g);
   
    
    //EnePoke uno("Pikachu",DEN,NOT,110,75,60,70,70,110,Thunderbolt);
    bool n =true;
    while(n){
        std::cout <<Hamada.getTrainerName()<<"`s"<<Hamada.getMyPokemon(1)->getPokeName()<<" used "<<Hamada.getMyPokemon(1)->getMove(1).getMoveName()<<std::endl;
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
