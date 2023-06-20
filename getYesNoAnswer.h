#pragma once
#include <iostream>

bool getYesNoAnswer(){
    int answer;
    std::cout <<1<<'.'<<"Yes"<<std::endl;
    std::cout <<2<<'.'<<"No"<<std::endl;
    std::cin >> answer;
    if(answer==1){return true;}
    else{return false;}
}