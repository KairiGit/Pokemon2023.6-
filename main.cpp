#include ".\Master.h"

int main(void){
    std::cout<<"Game Stert"<<std::endl;
    std::cout<<"When `v` is displayed, press the enter key."<<std::endl;
    std::cout<<'v'<<std::flush;//enterキーの要求
    flag = getchar();
    std::cout<<"Prease answer with a number when the choices are displayed."<<std::endl;
    std::cout<<"1.Yes, I understand."<<std::endl;
    flag = getchar();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// バッファをクリアする
    std::cout<<'v'<<std::flush;//enterキーの要求
    flag = getchar();
    Master();
    return 0;
}