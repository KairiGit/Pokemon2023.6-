#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
using namespace std;
enum Type{NOT,NOM,HON,MIZ,DEN,KUS,KOO,KAK,DOK,JIM,HIK,ESU,MUS,IWA,GOS,DRA,AKU,HAG,FEA};//18タイプ
enum Ailment{NOA,PAR,FRZ,PSN,BPSN,BRN};//状態異常
enum classification{Physical,Spesial,Status};//技の分類


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
        classification cat;
        int Pow;
        int Acc;
    protected:
    public:
        void setMove(Type t,classification c,int p){
            MoveType = t;
            cat = c;
            Pow = p;
        }
        string getMoveName(){return MoveName;}
        Type getMoveType(){return MoveType;}
        classification getCat(){return cat;}
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
        void setPokemon(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed);
        void setPokeMove(Move one,Move two,Move three,Move four){};
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
        void Pokemon :: setPokemon(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed){
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
        }
        void Pokemon :: setPokeMove(Move one,Move two,Move three,Move four){
            move1.setMove(one.getMoveType(),one.getCat(),int one.getPow);
            move2.setMove(two.getMoveType(),two.getCat(),int two.getPow);
            move3.setMove(three.getMoveType(),three.getCat(),int three.getPow);
            move4.setMove(four.getMoveType(),four.getCat(),int four.getPow);
        }
        
    class MyPoke : public Pokemon{
        public:
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
    class EnePoke : public Pokemon{};


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
    Move Tackle;
        Tackle.setMove(NOM,Physical,40);
    Pokemon Eevee;
        Eevee.setPokemon("Eevee",NOM,NOT,130,75,70,65,85,75);
    Pokemon Charizard;
        Charizard.setPokemon("Charizard",HON,HIK,153,104,98,129,105,120);
    Pokemon Greninja;
        Greninja.setPokemon("Greninja",MIZ,AKU,147,115,87,123,91,142);
    Pokemon Pikachu;
        Pikachu.setPokemon("pika",DEN,NOT,110,75,60,70,70,110);
    Pokemon Amoonguss;
        Amoonguss.setPokemon("Amoonguss",KUS,DOK,189,105,90,105,100,50);
    
    MyPoke one;
        one.setPokemon("Eevee",NOM,NOT,130,75,70,65,85,75);
    EnePoke uno;
        uno.setPokemon("pika",DEN,NOT,110,75,60,70,70,110);
    one.showNowhp();
    one.Moved(uno,Tackle);
    one.showNowhp();
    
    return 0;
}
