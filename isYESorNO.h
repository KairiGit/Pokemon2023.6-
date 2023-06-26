#pragma once
#include <iostream>

bool isYESorNO(){
    int answer;
    std::cout <<1<<'.'<<"YES"<<std::endl;
    std::cout <<2<<'.'<<"NO"<<std::endl;
    std::cin >> answer;
    std::cout<<std::endl;
    if(answer==1){return true;}
    else{return false;}
}