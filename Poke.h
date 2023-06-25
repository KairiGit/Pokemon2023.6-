#pragma once
#include ".\Move.h"

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
        bool canBattle;
        Move m[4];
        
        void die(){canBattle = false;}
        
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
            canBattle = true;
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
        
        bool isCanBattle(){return canBattle;}


        void setPokemon(std::string name,Type f,Type s,int hp,int atk,int def,int sp_atk,int sp_def,int speed,Move move);
        void setPokemon(Pokemon* x);
        void setPokeMove(Move* x);

        void Attacked(Pokemon atk,Move w);
        void spAttacked(Pokemon atk,Move w);
        void Moved(Pokemon atk,Move w);
        
        void showCanBattle();
        void showNowhp();
        void showPokeType();
        void showStats();
        void showMove();
        void showAllST();
};