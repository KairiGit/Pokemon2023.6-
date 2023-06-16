#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#include <enum.h>
#include <Move.h>
#include <something.h>
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
        Move m[4];
        
        void die(){isAlive = false;}
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
        Move getMove1(){return m[0];}
        Move getMove2(){return m[1];}
        Move getMove3(){return m[2];}
        Move getMove4(){return m[3];}
        bool getisAlive(){return isAlive;}


        //void setPokemon(string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed);
        void setPokeMove(Move one,Move two,Move three,Move four);

        void Attacked(Pokemon atk,Move w);
        void spAttacked(Pokemon atk,Move w);
        void Moved(Pokemon atk,Move w);
        //"\x1b[38;2;" "\x1b[m"
        void showNowhp();
        void showPokeType();
        void showStats();
        void showMove();
        void showAllST();
};