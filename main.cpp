#include ".\Master.h"

int main(void){
    std::cout<<"When `v` is displayed, press the enter key."<<std::endl;
    std::cout<<'v';//enterキーの要求
    std::cout<<"Prease answer with a number when the choices are displayed."<<std::endl;
    std::cout<<"1.Yes, I understand."<<std::endl;
    flag = getchar();
    Master();
    return 0;
}