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
int dmg(int atk,int def,int pow){
    int dmg;
    int tmp = 50*2/5 +2;
    tmp = tmp*pow*atk/def;
    tmp = tmp/50 +2;
    dmg =tmp;
    return dmg;
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
    protected:
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

        Move move1;
        Move move2;
        Move move3;
        Move move4;
        void die(){
            isAlive = false;
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
            move1 = move;
            isAlive = true;
        }
        Pokemon(){}
        //void setPokemon(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed);
        void setPokeMove(Move one,Move two,Move three,Move four);
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
        Move getMove1(){return move1;}
        Move getMove2(){return move2;}
        Move getMove3(){return move3;}
        Move getMove4(){return move4;}

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
            cout <<exType(fPokeType)<<'/'<<exType(sPokeType)<<endl;
        }
        void showStats(){
            cout <<'H'<<getHP()<<' '<<'A'<<getAtk()<<' '<<'B'<<getDef()<<' '<<'C'<<getSp_Atk()<<' '<<'D'<<getSp_Def()<<' '<<'S'<<getSpeed()<<endl;
        }
        void showMove(){
            cout <<1<<':'<< move1.getMoveName() <<endl;
            cout <<2<<':'<< move2.getMoveName() <<endl;
            cout <<3<<':'<< move3.getMoveName() <<endl;
            cout <<4<<':'<< move4.getMoveName() <<endl;
        }
        void showAllST(){
            cout <<endl;
            cout <<"Type is ";
            exType(fPokeType);
            cout <<'/';
            exType(sPokeType);
            cout <<endl;
            cout <<"States is "<<'H'<<getHP()<<' '<<'A'<<getAtk()<<' '<<'B'<<getDef()<<' '<<'C'<<getSp_Atk()<<' '<<'D'<<getSp_Def()<<' '<<'S'<<getSpeed()<<endl;
            cout <<"Move is"<<endl;
            cout <<1<<':'<< move1.getMoveName() <<endl;
            cout <<2<<':'<< move2.getMoveName() <<endl;
            cout <<3<<':'<< move3.getMoveName() <<endl;
            cout <<4<<':'<< move4.getMoveName() <<endl;
            cout <<endl;
        }
};
    
        void Pokemon :: setPokeMove(Move one,Move two,Move three,Move four){
            move1.setMove(one.getMoveName(),one.getMoveType(),one.getCat(),one.getPow());
            move2.setMove(two.getMoveName(),two.getMoveType(),two.getCat(),two.getPow());
            move3.setMove(three.getMoveName(),three.getMoveType(),three.getCat(),three.getPow());
            move4.setMove(four.getMoveName(),four.getMoveType(),four.getCat(),four.getPow());
        }
    //自分のポケモン
    class MyPoke : public Pokemon{
        public:
            MyPoke(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed,Move move) : Pokemon(name,f,s,hp,atk,def,sp_atk,sp_def,speed,move){}
            MyPoke(){}
    };
    //相手のポケモン
    class EnePoke : public Pokemon{
        public:
            EnePoke(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed,Move move) : Pokemon(name,f,s,hp,atk,def,sp_atk,sp_def,speed,move){}
            EnePoke(){}
    };


//ポケモン
/*
    class Eevee : public Pokemon{};
    class Charizard : public Pokemon{};
    class Greninja : public Pokemon{};
    class Pikachu : public Pokemon{};
    class Amoonguss : public Pokemon{};
    class Glaceon : public Pokemon{};
    class Lucario : public Pokemon{};
    class Toxapex : public Pokemon{};
    class Hippowdon : public Pokemon{};
    class Togekiss : public Pokemon{};
    class Slowking : public Pokemon{};
    class Volcarona : public Pokemon{};
    class Rhyperior : public Pokemon{};
    class Gengar : public Pokemon{};
    class Kommo_o : public Pokemon{};
    class Hydreigon : public Pokemon{};
    class Metagross : public Pokemon{};
    class Sylveon : public Pokemon{};
*/
//「はい」か「いいえ」を選ぶ関数
bool YN(){
    int YN;
    cout <<1<<'.'<<"Yes"<<endl;
    cout <<2<<'.'<<"No"<<endl;
    cin >> YN;
    if(YN==1){return true;}
    else{return false;}
}

//主な動作をする関数
void Master(){
    Move Tackle("Tackle",NOM,Physical,40);
    Move Ember("Ember",HON,Spesial,40);
    Move Water_Gun("Water Gun",MIZ,Spesial,40);
    Move Thunderbolt("Thunderbolt",DEN,Spesial,90);
    Move Leafage("Leafage",KUS,Physical,40);

    Pokemon a("Eevee",NOM,NOT,130,75,70,65,85,75,Tackle);
    Pokemon b("Charizard",HON,HIK,153,104,98,129,105,120,Ember);
    Pokemon c("Greninja",MIZ,AKU,147,115,87,123,91,142,Water_Gun);
    Pokemon d("Pikachu",DEN,NOT,110,75,60,70,70,110,Thunderbolt);
    Pokemon e("Amoonguss",KUS,DOK,189,105,90,105,100,50,Leafage);
    Pokemon tmp;

    bool still=true;
    //自分のポケモンを選ぶ
    while(still){
        int select;
        cout <<"Which Pokemon would you choose?"<<endl;
        cout <<1<<a.getPokeName()<<endl;
        cout <<2<<b.getPokeName()<<endl;
        cin >> select;
        
        switch(select){
            case 1:
                cout <<"Show the status of "<<a.getPokeName()<<endl;
                a.showAllST();
                cout <<"Is this OK?"<<endl;
                if(YN()){
                    cout <<"You choose "<<a.getPokeName()<<endl;
                    tmp = a;
                    still = false;
                }
                break;
            case 2:
                cout <<endl<<"Show the status of "<<b.getPokeName()<<endl;
                b.showAllST();
                cout <<"Is this OK?"<<endl;
                if(YN()){
                    cout <<"You choose "<<b.getPokeName()<<endl;
                    tmp = b;
                    still = false;
                }
                break;
        }
    }
    MyPoke one(tmp.getPokeName(),tmp.getfPokeType(),tmp.getsPokeType(),tmp.getHP(),tmp.getAtk(),tmp.getDef(),tmp.getSp_Atk(),tmp.getSp_Def(),tmp.getSpeed(),tmp.getMove1());
    
    EnePoke uno("Pikachu",DEN,NOT,110,75,60,70,70,110,Thunderbolt);
    bool n =true;
    while(n){
        cout <<"Enemy's "<<uno.getPokeName()<<" used "<<uno.getMove1().getMoveName()<<endl;
        one.showNowhp();
        one.Moved(uno,uno.getMove1());
        cout << "->";
        one.showNowhp();
        if(one.getisAlive()){n = YN();}
        else{
            cout << one.getPokeName() <<" fainted!"<<endl;
            n = false;
        }
    }
    
}

int main(void){
    Master();
    return 0;
}
