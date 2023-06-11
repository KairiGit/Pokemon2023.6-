#include <iostream>
#include <cstring>
#include <typeinfo>
#include <cmath>
using namespace std;
enum Type{NOM,HON,MIZ,DEN,KUS,KOO,KAK,DOK,JIM,HIK,ESU,MUS,IWA,GOS,DRA,AKU,HAG,FEA};//18タイプ
enum Ailment{NOT,PAR,FRZ,PSN,BPSN,BRN};//状態異常
enum classification{Physical,Spesial,Status};//技の分類

class Pokemon{
    private:
        string PokeName;
        Type fPokeType;
        Type sPokeType;
        int H,A,B,C,D,S;
        string Ability;
        int hp;
        int h,a,b,c,d,s;
        int HP,Atk,Def,Sp_Atk,Sp_Def,Speed;
        Ailment Ail;
    protected:
    public:
        string getPokeName();
        Type getPokeType();
        string getAbility();
        int gethp();
        int getHP();
        int getAtk();
        int getDef();
        int getSp_Atk();
        int getSp_Def();
        int getSpeed();
        int getAil();

        void showhp(){
            cout << gethp();
        }
        void showStats(){
            cout <<getHP()<<' '<<getAtk()<<' '<<getDef()<<' '<<getSp_Atk()<<' '<<getSp_Def()<<' '<<getSpeed();
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
class Move{
    private:
        string MoveName;
        Type MoveType;
        classification cat;
        int Acc;
    protected:
    public:
        string getMoveName();
        Type getMoveType();
        classification getCat();
};
    class MoveATK : public Move{
        private:
            int Pow;
            int Contact;
    };
    class MoveStats : public Move{};


void battle(){}
    int main(void){
        battle();
        return 0;
    }
