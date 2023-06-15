#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
using namespace std;
enum Type{NOT,NOM,HON,MIZ,DEN,KUS,KOO,KAK,DOK,JIM,HIK,ESU,MUS,IWA,GOS,DRA,AKU,HAG,FEA};//18タイプ
enum Ailment{NOA,PAR,FRZ,PSN,BPSN,BRN};//状態異常
enum Cat{Physical,Spesial,Status};//技の分類

string exType(Type t){
    switch(t){
        case 0:return "nasi";break;
        case 1:return "nomaru";break;
        case 2:return "hono";break;
        case 3:return "mizu";break;
        case 4:return "denki";break;
        case 5:return "kusa";break;
        case 6:return "kori";break;
        case 7:return "kakuto";break;
        case 8:return "doku";break;
        case 9:return "jimen";break;
        case 10:return "hikou";break;
        case 11:return "esupa";break;
        case 12:return "musi";break;
        case 13:return "iwa";break;
        case 14:return "gosuto";break;
        case 15:return "doragon";break;
        case 16:return "aku";break;
        case 17:return "hagane";break;
        case 18:return "feari";break;
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
        }

        void showPokeType(){
            string f =exType(fPokeType);
            string s =exType(sPokeType);
            cout <<f<<'/'<<s<<endl;
        }
        void showNowhp(){
            cout << getNowhp()<<endl;
        }
        void showStats(){
            cout <<getHP()<<' '<<getAtk()<<' '<<getDef()<<' '<<getSp_Atk()<<' '<<getSp_Def()<<' '<<getSpeed()<<endl;
        }
        void showMove(){
            cout <<1<< move1.getMoveName() <<endl;
            cout <<2<< move2.getMoveName() <<endl;
            cout <<3<< move3.getMoveName() <<endl;
            cout <<4<< move4.getMoveName() <<endl;
        }

};
        /*void Pokemon :: setPokemon(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed){
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
            isAlive = true;
        }*/
        void Pokemon :: setPokeMove(Move one,Move two,Move three,Move four){
            move1.setMove(one.getMoveName(),one.getMoveType(),one.getCat(),one.getPow());
            move2.setMove(two.getMoveName(),two.getMoveType(),two.getCat(),two.getPow());
            move3.setMove(three.getMoveName(),three.getMoveType(),three.getCat(),three.getPow());
            move4.setMove(four.getMoveName(),four.getMoveType(),four.getCat(),four.getPow());
        }
        
    class MyPoke : public Pokemon{
        public:
            MyPoke(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed,Move move) : Pokemon(name,f,s,hp,atk,def,sp_atk,sp_def,speed,move){}
            MyPoke(){}
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
            }
    };
    class EnePoke : public Pokemon{
        public:
            EnePoke(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed,Move move) : Pokemon(name,f,s,hp,atk,def,sp_atk,sp_def,speed,move){}

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
            }
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

int main(void){
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
    

    int select;
    cout <<"Which Pokemon would you choose?"<<endl;
    cout <<1<<a.getPokeName()<<endl;
    cout <<2<<b.getPokeName()<<endl;
    cin >> select;

    Pokemon tmp;
    switch(select){
        case 1:
            cout <<"You choose "<<a.getPokeName()<<endl;
            tmp = a;
            //MyPoke one(a.getPokeName(),a.getfPokeType(),a.getsPokeType(),a.getHP(),a.getAtk(),a.getDef(),a.getSp_Atk(),a.getSp_Def(),a.getSpeed(),a.getMove1());
            break;
        case 2:
            cout <<"You choose "<<b.getPokeName()<<endl;
            tmp = b;
            //MyPoke one(b.getPokeName(),b.getfPokeType(),b.getsPokeType(),b.getHP(),b.getAtk(),b.getDef(),b.getSp_Atk(),b.getSp_Def(),b.getSpeed(),a.getMove1());
            break;
    }
    MyPoke one(tmp.getPokeName(),tmp.getfPokeType(),tmp.getsPokeType(),tmp.getHP(),tmp.getAtk(),tmp.getDef(),tmp.getSp_Atk(),tmp.getSp_Def(),tmp.getSpeed(),tmp.getMove1());
    


    //MyPoke one(a.getPokeName(),a.getfPokeType(),a.getsPokeType(),a.getHP(),a.getAtk(),a.getDef(),a.getSp_Atk(),a.getSp_Def(),a.getSpeed());
        //one.setPokemon("Eevee",NOM,NOT,130,75,70,65,85,75);
    EnePoke uno("Pikachu",DEN,NOT,110,75,60,70,70,110,Thunderbolt);
        //uno.setPokemon("Pikachu",DEN,NOT,110,75,60,70,70,110);
    one.showMove();
    uno.showMove();
    one.showNowhp();
    one.Moved(uno,uno.getMove1());
    one.showNowhp();
    
    return 0;
}
