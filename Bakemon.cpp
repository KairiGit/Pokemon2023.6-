#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <limits>
using namespace std;
//enum.hpp
enum Type{NOT,NOM,HON,MIZ,DEN,KUS,KOO,KAK,DOK,JIM,HIK,ESU,MUS,IWA,GOS,DRA,AKU,HAG,FEA};//18タイプ
enum Ailment{NOA,PAR,FRZ,PSN,BPSN,BRN};//状態異常
enum Cat{Physical,Spesial,Status};//技の分類
int flag;
void enter(){
    std::cout<<'v'<<std::flush;//enterキーの要求
    flag = getchar();
}
//exType.hpp
//タイプに色を付けて出力する関数
void exType(Type t){//"\x1b[38;2;赤;緑;青m"<<"文字"<<"\x1b[m"
    switch(t){
        case 0:     std::cout <<"ONRY"                                        <<std::flush;break;                                         
        case 1:     std::cout <<"\x1b[38;2;255;215;0m"  <<"nomaru"  << "\x1b[m"<<std::flush;break;
        case 2:     std::cout <<"\x1b[38;2;255;69;0m"   <<"hono"    << "\x1b[m"<<std::flush;break;
        case 3:     std::cout <<"\x1b[38;2;0;191;255m"  <<"mizu"    << "\x1b[m"<<std::flush;break;
        case 4:     std::cout <<"\x1b[38;2;255;165;0m"  <<"denki"   << "\x1b[m"<<std::flush;break;
        case 5:     std::cout <<"\x1b[38;2;127;255;0m"  <<"kusa"    << "\x1b[m"<<std::flush;break;
        case 6:     std::cout <<"\x1b[38;2;224;255;255m"<<"kori"    << "\x1b[m"<<std::flush;break;
        case 7:     std::cout <<"\x1b[38;2;165;42;42m"  <<"kakuto"  << "\x1b[m"<<std::flush;break;
        case 8:     std::cout <<"\x1b[38;2;106;76;156m" <<"doku"    << "\x1b[m"<<std::flush;break;
        case 9:     std::cout <<"\x1b[38;2;184;134;11m" <<"jimen"   << "\x1b[m"<<std::flush;break;
        case 10:    std::cout <<"\x1b[38;2;230;230;250m"<<"hikou"   << "\x1b[m"<<std::flush;break;
        case 11:    std::cout <<"\x1b[38;2;255;20;147m" <<"esupa"   << "\x1b[m"<<std::flush;break;
        case 12:    std::cout <<"\x1b[38;2;145;141;64m" <<"musi"    << "\x1b[m"<<std::flush;break;
        case 13:    std::cout <<"\x1b[38;2;240;230;140m"<<"iwa"     << "\x1b[m"<<std::flush;break;
        case 14:    std::cout <<"\x1b[38;2;72;61;139m"  <<"gosuto"  << "\x1b[m"<<std::flush;break;
        case 15:    std::cout <<"\x1b[38;2;0;0;128m"    <<"doragon" << "\x1b[m"<<std::flush;break;
        case 16:    std::cout <<"\x1b[38;2;70;70;70m"   <<"aku"     << "\x1b[m"<<std::flush;break;
        case 17:    std::cout <<"\x1b[38;2;192;192;192m"<<"hagane"  << "\x1b[m"<<std::flush;break;
        case 18:    std::cout <<"\x1b[38;2;255;192;203m"<<"feari"   << "\x1b[m"<<std::flush;break;
    }
}
//isYESorNO.hpp
bool isYESorNO(){
    int answer;
    std::cout <<1<<'.'<<"YES"<<std::endl;
    std::cout <<2<<'.'<<"NO"<<std::endl;
    std::cin >> answer;
    std::cout<<std::endl;
    if(answer==1){return true;}
    else{return false;}
}
//Move.hpp
class Move{
    private:
        std::string MoveName;
        Type MoveType;
        Cat cat;
        int Pow;
        int Acc;
    protected:
    public:
        Move(const std::string n,Type t,Cat c,int p,int a);
        Move(){}
        void setMove(const std::string n,Type t,Cat c,int p,int a){
            MoveName = n;
            MoveType = t;
            cat = c;
            Pow = p;
            Acc = a;
        }
        void setMove(Move x){
            MoveName = x.getMoveName();
            MoveType = x.getMoveType();
            cat = x.getCat();
            Pow = x.getPow();     
            Acc = x.getAcc();       
        }
        std::string getMoveName(){return MoveName;}
        Type getMoveType(){return MoveType;}
        Cat getCat(){return cat;}
        int getPow(){return Pow;}
        int getAcc(){return Acc;}
        void showMoveInfo(){
            std::cout<<getMoveName()<<std::endl;
            std::cout<<"Type: "<<std::flush; exType(getMoveType());std::cout<<std::endl;
            std::cout<<"Category: "<<getCat()<<std::endl;
            std::cout<<"Power: "<<getPow()<<std::endl;
            std::cout<<"Actually: "<<getAcc()<<std::endl;
        }
};
Move::Move(std::string n,Type t,Cat c,int p,int a){
    MoveName = n;
    MoveType = t;
    cat = c;
    Pow = p;
    Acc = a;
}
//setAllMove.hpp
void setAllMove(Move allMove[][4]){
    allMove[0][0].setMove("Tackle",NOM,Physical,40,100);

    allMove[1][0].setMove("Ember",HON,Spesial,40,100);

    allMove[2][0].setMove("Water Gun",MIZ,Spesial,40,100);
    
    allMove[3][0].setMove("Thunderbolt",DEN,Spesial,90,100);
    
    allMove[4][0].setMove("Leafage",KUS,Physical,40,100);
    
    allMove[5][0].setMove("Aura_Sphere",KAK,Spesial,80,100);
    
    allMove[6][0].setMove("ThunderShock",DEN,Spesial,40,100);

}
//Poke.hpp
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
        void Attacked(Pokemon atk,Move w);
        void spAttacked(Pokemon atk,Move w);
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
        void setPokemon(Pokemon x);
        void setPokeMove(Move* x);

        void Moved(Pokemon atk,Move w);
        
        void showCanBattle();
        void showNowhp();
        void showPokeType();
        void showStats();
        void showMove();
        void showAllST();
        void dieMessage();
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
        canBattle = true;
    }
    void Pokemon :: setPokemon(Pokemon x){
        PokeName = x.getPokeName();
        fPokeType = x.getfPokeType();
        sPokeType = x.getsPokeType();
        Nowhp = x.getHP();
        HP = x.getHP();
        Atk = x.getAtk();
        Def = x.getDef();
        Sp_Atk = x.getSp_Atk();
        Sp_Def = x.getSp_Def();
        Speed = x.getSpeed();
        m[0] = x.getMove(1);
        canBattle = true;    
    }
    void Pokemon :: setPokeMove(Move* x){
        for(int i=0;i<4;i++){
            m[i].setMove(x[i].getMoveName(),x[i].getMoveType(),x[i].getCat(),x[i].getPow(),x[1].getAcc());
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
            canBattle = false;
        }
    }
    void Pokemon :: showCanBattle(){
        if(isCanBattle()){
            std::cout<<"Can Battle"<<std::endl;
        }
        else{
            std::cout<<"Fainting"<<std::endl;
        }
    }
    void Pokemon :: showNowhp(){
        if(Nowhp>HP/2){std::cout <<"HP: "<<"\x1b[38;2;0;255;0m"<<Nowhp<<"\x1b[m"<<"/"<<HP<<std::endl;}
        else if(Nowhp>HP/4){std::cout <<"HP: "<<"\x1b[38;2;255;255;0m"<<Nowhp<<"\x1b[m"<<"/"<<HP<<std::endl;}
        else{std::cout <<"HP: "<<"\x1b[38;2;255;0;0m"<<Nowhp<<"\x1b[m"<<"/"<<HP<<std::endl;}
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
    void Pokemon :: dieMessage(){
        std::cout<<PokeName<<" is fainted!"<<std::endl;
    }
//setAllPokemon.hpp
void setAllPokemon(Pokemon* allPokemon,Move allMove[][4]){
    allPokemon[0].setPokemon("Eievui",NOM,NOT,130,75,70,65,85,75,allMove[0][0]);
    allPokemon[1].setPokemon("Lizardon",HON,HIK,153,104,98,129,105,120,allMove[1][0]);
    allPokemon[2].setPokemon("Gekkouga",MIZ,AKU,147,115,87,123,91,142,allMove[2][0]);
    allPokemon[3].setPokemon("Pikachu",DEN,NOT,110,75,60,70,70,110,allMove[3][0]);
    allPokemon[4].setPokemon("Morobareru",KUS,DOK,189,105,90,105,100,50,allMove[4][0]);
    allPokemon[5].setPokemon("Lucario",KAK,HAG,70,110,70,115,70,90,allMove[5][0]);
    allPokemon[6].setPokemon("Malurumine",DEN,NOT,135,70,90,100,100,170,allMove[6][0]);
}
//Trainer.hpp
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
        Pokemon getPokemon(int num);
        Pokemon* getpPokemon(int num);
        Pokemon* getpPokemon();
        Move getPokeMove(int p,int m);
        void showmyPoke();
        void setTrainer(std::string name,Pokemon* poke3);
        void setMe(Pokemon* all,int numPokemons);
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
    Pokemon* Trainer::getpPokemon(int num){
        return &myPoke[num-1];
    }
    Pokemon Trainer::getPokemon(int num){
        return myPoke[num-1];
    }
    Pokemon* Trainer::getpPokemon(){
        return myPoke;
    }
    Move Trainer::getPokeMove(int p,int m){
        return getPokemon(p).getMove(m);
    }
    void Trainer::showmyPoke(){
        for(int i=0;i<3;i++){
            std::cout <<i<<myPoke[i].getPokeName()<<std::endl;
        }
    }
    void Trainer::setTrainer(std::string name,Pokemon* poke3){
        TrainerName = name;
        for(int i=0;i<3;i++){
            myPoke[i].setPokemon(poke3[i]);
        }
    }
    void Trainer::setMe(Pokemon* all,int numPokemons){
        std::cout << "What your name?"<<std::endl;
        std::string name;
        std::cin >> name;
        std::cout<<std::endl;
        std::cout << "Your name is "<<name<<'!'<<std::endl;

        enter();//enterキーの要求
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
        
        std::cout<<"You have to choose 3 Pokemon!"<<std::endl;
            enter();//enterキーの要求
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
            //二週目からはバッファをクリアする
        std::cout << "Choose your Pokemon" << std::endl;
            enter();//enterキーの要求
            
        for (int i = 0; i < numPokemons; i++) {
            std::cout << i + 1 << ". " << pokemons[i].getPokeName() << std::endl;
        }
        std::cin >> selection;
        std::cout<<std::endl;
        return selection - 1;
    }
    Pokemon Trainer::checkPokemon(Pokemon pokemon, bool* isConfirmed) {
        Pokemon tmp;
        std::cout << "Show the status of " << pokemon.getPokeName() << std::endl;

        enter();//enterキーの要求
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
        

        pokemon.showAllST();
            enter();//enterキーの要求
            
        std::cout << "OK?" << std::endl;
        if (isYESorNO()) {
            std::cout << "You choose " << pokemon.getPokeName() <<"!"<< std::endl;
                enter();//enterキーの要求
                
            tmp = pokemon;
            *isConfirmed = false;
        }
        return tmp;
    }
//BattleField.hpp
class BattleField{
    private:
        Trainer A;
        Trainer B;
        Pokemon* nowBattleA;
        Pokemon* nowBattleB;
        int Anum;
        int Bnum;
        Move tmpMoveA;
        Move tmpMoveB;
        
        bool inBattle;
        bool selected;
        bool AwillMove;
        bool BwillMove;
    private://コンストラクタで呼び出されるヘルパー
        void checkPokemon(bool which);
        void BattleStart();
        void selectAction();
        void BattleMove();
        void PokeChenge();
        void Check();
        void checkField();
        void Run();
        void AChenge();
        void AMove();
        void BMove();
        void Battle();
    public:
        BattleField(Trainer A,Trainer B);      
};
    void BattleField::BattleStart(){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
        std::cout<<B.getTrainerName();
        std::cout<<" would like to battele!"<<std::endl;
            enter();//enterキーの要求
            
        std::cout<<B.getTrainerName()<<" sent out ";
        std::cout<<B.getPokemon(1).getPokeName();
        std::cout<<'!'<<std::endl;
            enter();//enterキーの要求
            
        std::cout<<"[Go! ";
        std::cout<<A.getPokemon(1).getPokeName();
        std::cout<<"!]"<<std::endl;
            enter();//enterキーの要求
            
    }
    void BattleField :: selectAction(){
        std::cout<<""<<std::endl;
        selected = false;
        while(!selected){
            int select;
            std::cout<<A.getTrainerName()<<std::endl;
            std::cout<<"1.Battle"<<std::endl;
            std::cout<<"2.Pokemon"<<std::endl;
            std::cout<<"3.Check Status"<<std::endl;
            std::cout<<"4.Run"<<std::endl;
            std::cin>>select;
            std::cout<<std::endl;
            switch(select){
                case 1:BattleMove();break;
                case 2:PokeChenge();break;
                case 3:Check();break;
                case 4:Run();break;
            }
        }
    }
    void BattleField::BattleMove(){
        nowBattleA->showMove();
        std::cout<<std::endl<<"5.Move Info"<<std::endl;
        int select;
        std::cin>>select;
        std::cout<<std::endl;
        if(select<=4&&select>=1){
            tmpMoveA.setMove(nowBattleA->getMove(select));
            selected = true;
            AwillMove = true;
            tmpMoveB.setMove(nowBattleB->getMove(select));
        }
        else if(select==5){
            bool still = true;
            while(still){
                std::cout<<"Which Move Info do you wanna see?"<<std::endl;
                nowBattleA->showMove();
                std::cin>>select;
                std::cout<<std::endl;
                if(select<=4&&select>=1){
                    nowBattleA->getMove(select).showMoveInfo();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
                    enter();//enterキーの要求
                    
                }
                else{
                    still = false;
                }
            }

        }
    }
        void BattleField::PokeChenge(){
            std::cout<<"Which Pokemon do you wanna replace with?"<<std::endl;
            enter();//enterキーの要求
            
            for(int i=0;i<3;i++){
                std::cout << i+1 << A.getPokemon(i+1).getPokeName() << std::endl;
            }
            int tmp = Anum;
            std::cin>>Anum;
            if(tmp == Anum){
                std::cout<<"Alredy in Battle"<<std::endl;
                enter();
            }else if(A.getPokemon(Anum).isCanBattle()){
                selected = true;
                tmpMoveB.setMove(nowBattleB->getMove(1));
            }else{
                std::cout<<"Alredy fainted!"<<std::endl;
                enter();
            }
            enter();//enterキーの要求
            
        }
        void BattleField::Check(){
            std::cout<<"error:nothing"<<std::endl;
        }
            void BattleField :: checkPokemon(bool which){
                if(which){
                    for(int i=0;i<3;i++){
                        std::cout << i+1 << A.getPokemon(i).getPokeName() << std::endl;
                    }
                }
                else{
                    for(int i=0;i<3;i++){
                        std::cout << i+1 << B.getPokemon(i).getPokeName() << std::endl;
                    }
                }
            }
    void BattleField::checkField(){
        std::cout<<"error:nothing"<<std::endl;
    }
    void BattleField::Run(){
        std::cout<<"Do you rearry Run?"<<std::endl;
        if(isYESorNO()){
            std::cout<<A.getTrainerName()<<" blacked out."<<std::endl;
            enter();//enterキーの要求
            
            selected = true;
            inBattle = false;
        }
    }
    void BattleField :: AChenge(){
        if(nowBattleB->getNowhp()>nowBattleB->getHP()/2){
            std::cout<<"["<<nowBattleA->getPokeName()<<"enough! come back!]"<<std::endl;
            enter();
            nowBattleA->setPokemon(A.getPokemon(Anum));
            std::cout <<"[Go! "<<nowBattleA->getPokeName()<<"!]"<<std::endl;
            enter();
        }else if(nowBattleB->getNowhp()>nowBattleB->getHP()/4){
            std::cout<<"["<<nowBattleA->getPokeName()<<"OK! come back!]"<<std::endl;
            enter();
            nowBattleA->setPokemon(A.getPokemon(Anum));
            std::cout <<"[Do it! "<<nowBattleA->getPokeName()<<"!]"<<std::endl;
            enter();
        }else{
            std::cout<<"["<<nowBattleA->getPokeName()<<"good! come back!]"<<std::endl;
            enter();
            nowBattleA->setPokemon(A.getPokemon(Anum));
            std::cout <<"[The enemy`s weak! Get`m "<<nowBattleA->getPokeName()<<"!]"<<std::endl;
            enter();
        }
    }
    void BattleField :: AMove(){
        std::cout<<nowBattleA->getPokeName()<<" used "<<tmpMoveA.getMoveName()<<std::endl;
        enter();//enterキーの要求
        
        std::cout<<"The "<<nowBattleB->getPokeName()<<std::endl;
        nowBattleB->showNowhp();
        std::cout<<"->"<<std::flush;
        nowBattleB->Moved(*nowBattleA,tmpMoveA);
        AwillMove = false;
        nowBattleB->showNowhp();
    }
    void BattleField :: BMove(){
        std::cout<<"The "<<nowBattleB->getPokeName()<<" used "<<tmpMoveB.getMoveName()<<std::endl;
        enter();//enterキーの要求
        
        std::cout<<nowBattleA->getPokeName()<<std::endl;
        nowBattleA->showNowhp();
        std::cout<<"->"<<std::flush;                        
        nowBattleA->Moved(*nowBattleB,tmpMoveB);
        nowBattleA->showNowhp();
    }
    void BattleField :: Battle(){
        BattleStart();

        while(inBattle){
            selectAction();
            if(!inBattle){
                break;
            }
            if(nowBattleA->getSpeed() > nowBattleB->getSpeed()){
                if(AwillMove){
                    AMove();
                }else{
                    AChenge();
                }
                if(nowBattleB->isCanBattle()){
                    if(BwillMove){
                        BMove();
                    }
                }else{
                    nowBattleB->dieMessage();
                }
                enter();//enterキーの要求
                if( ! nowBattleA->isCanBattle()){
                    nowBattleA->dieMessage();
                    enter();
                }
            }else{
                if(BwillMove){
                    BMove();
                }
                if(nowBattleA->isCanBattle()){
                    if(AwillMove){
                        AMove();
                    }
                }else{
                    nowBattleA->dieMessage();
                }
                enter();//enterキーの要求
                if( ! nowBattleB->isCanBattle()){
                    nowBattleB->dieMessage();
                    enter();
                }
                
            }
        }
        
    }
    BattleField::BattleField(Trainer a,Trainer b){
        A.setTrainer(a.getTrainerName(),a.getpPokemon());
        B.setTrainer(b.getTrainerName(),b.getpPokemon());
        
        nowBattleA = a.getpPokemon(1);
        nowBattleB = b.getpPokemon(1);
        Anum = 1;
        Bnum = 1;
        inBattle = true;
        AwillMove = false;
        BwillMove = true;
        Battle();
    }
//Master.hpp
void Master(){
    
    int numMoves=7;
    Move allMove[7][4];
    setAllMove(allMove);
    int numPokemons=7;
    Pokemon allPokemon[7];
    setAllPokemon(allPokemon,allMove);
    Trainer Hamada("Tan-Pan Kozo HaMaDa",allPokemon[5],allPokemon[2],allPokemon[6]);
    
    Trainer Masuya("Student Massu~",allPokemon[1],allPokemon[0],allPokemon[3]);
    BattleField tmp(Masuya,Hamada);
    
    Trainer Me;
    Me.setMe(allPokemon,numPokemons);
    

    BattleField vsHamada(Me,Hamada);
}
//main.cpp
int main(void){
    std::cout<<"Game Stert"<<std::endl;
    std::cout<<"When `v` is displayed, press the enter key."<<std::endl;
    enter();//enterキーの要求
    
    std::cout<<"Prease answer with a number when the choices are displayed."<<std::endl;
    std::cout<<"1.Yes, I understand."<<std::endl;
    
    enter();//enterキーの要求
    
    Master();
    return 0;
}


