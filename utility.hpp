#pragma once

#include <iostream>

void enter(){
    int flag;
    std::cout<<"\x1b[38;2;255;220;40m"<<'v'<<"\x1b[m"<<std::flush;//enterキーの要求
    flag = getchar();
}