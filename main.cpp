#include ".\Master.h"

int main(void){
    std::cout<<"Game Stert"<<std::endl;
    std::cout<<"When `v` is displayed, press the enter key."<<std::endl;
    enter();//enterキーの要求
    
    std::cout<<"Prease answer with a number when the choices are displayed."<<std::endl;
    std::cout<<"1.Yes, I understand."<<std::endl;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
    enter();//enterキーの要求
    
    Master();
    return 0;
}