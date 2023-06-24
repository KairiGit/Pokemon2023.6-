#pragma once
#include ".\enum.h"
//タイプに色を付けて出力する関数
void exType(Type t){//"\x1b[38;2;赤;緑;青m"<<"文字"<<"\x1b[m"
    switch(t){
        case 0:     std::cout <<"ONRY";                                         break;
        case 1:     std::cout <<"\x1b[38;2;255;215;0m"  <<"nomaru"  << "\x1b[m";break;
        case 2:     std::cout <<"\x1b[38;2;255;69;0m"   <<"hono"    << "\x1b[m";break;
        case 3:     std::cout <<"\x1b[38;2;0;191;255m"  <<"mizu"    << "\x1b[m";break;
        case 4:     std::cout <<"\x1b[38;2;255;165;0m"  <<"denki"   << "\x1b[m";break;
        case 5:     std::cout <<"\x1b[38;2;127;255;0m"  <<"kusa"    << "\x1b[m";break;
        case 6:     std::cout <<"\x1b[38;2;224;255;255m"<<"kori"    << "\x1b[m";break;
        case 7:     std::cout <<"\x1b[38;2;165;42;42m"  <<"kakuto"  << "\x1b[m";break;
        case 8:     std::cout <<"\x1b[38;2;106;76;156m" <<"doku"    << "\x1b[m";break;
        case 9:     std::cout <<"\x1b[38;2;184;134;11m" <<"jimen"   << "\x1b[m";break;
        case 10:    std::cout <<"\x1b[38;2;230;230;250m"<<"hikou"   << "\x1b[m";break;
        case 11:    std::cout <<"\x1b[38;2;255;20;147m" <<"esupa"   << "\x1b[m";break;
        case 12:    std::cout <<"\x1b[38;2;145;141;64m" <<"musi"    << "\x1b[m";break;
        case 13:    std::cout <<"\x1b[38;2;240;230;140m"<<"iwa"     << "\x1b[m";break;
        case 14:    std::cout <<"\x1b[38;2;72;61;139m"  <<"gosuto"  << "\x1b[m";break;
        case 15:    std::cout <<"\x1b[38;2;0;0;128m"    <<"doragon" << "\x1b[m";break;
        case 16:    std::cout <<"\x1b[38;2;70;70;70m"   <<"aku"     << "\x1b[m";break;
        case 17:    std::cout <<"\x1b[38;2;192;192;192m"<<"hagane"  << "\x1b[m";break;
        case 18:    std::cout <<"\x1b[38;2;255;192;203m"<<"feari"   << "\x1b[m";break;
    }
}