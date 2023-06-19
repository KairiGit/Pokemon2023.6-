#include ".\enum.h"

void exType(Type t){
    switch(t){
        case 0: cout <<"ONRY";break;
        case 1: cout <<"\x1b[38;2;255;255;205m"<<"nomaru"<< "\x1b[m";break;
        case 2: cout <<"\x1b[38;2;255;69;0m"<<"hono"<< "\x1b[m";break;
        case 3: cout <<"\x1b[38;2;0;191;255m"<<"mizu"<< "\x1b[m";break;
        case 4: cout <<"\x1b[38;2;255;255;55m"<<"denki"<< "\x1b[m";break;
        case 5: cout <<"\x1b[38;2;127;255;0m"<<"kusa"<< "\x1b[m";break;
        case 6: cout <<"\x1b[38;2;180;206;255m"<<"kori"<< "\x1b[m";break;
        case 7: cout <<"\x1b[38;2;165;42;42m"<<"kakuto"<< "\x1b[m";break;
        case 8: cout <<"\x1b[38;2;116;83;171m"<<"doku"<< "\x1b[m";break;
        case 9: cout <<"\x1b[38;2;184;134;11m"<<"jimen"<< "\x1b[m";break;
        case 10:cout <<"\x1b[38;2;220;220;255m"<<"hikou"<< "\x1b[m";break;
        case 11:cout <<"\x1b[38;2;255;20;147m"<<"esupa"<< "\x1b[m";break;
        case 12:cout <<"\x1b[38;2;145;141;64m"<<"musi"<< "\x1b[m";break;
        case 13:cout <<"\x1b[38;2;240;230;140m"<<"iwa"<< "\x1b[m";break;
        case 14:cout <<"\x1b[38;2;72;61;139m"<<"gosuto"<< "\x1b[m";break;
        case 15:cout <<"\x1b[38;2;0;30;155m"<<"doragon"<< "\x1b[m";break;
        case 16:cout <<"\x1b[38;2;70;70;70m"<<"aku"<< "\x1b[m";break;
        case 17:cout <<"\x1b[38;2;205;205;205m"<<"hagane"<< "\x1b[m";break;
        case 18:cout <<"\x1b[38;2;255;180;195"<<"feari"<< "\x1b[m";break;
    }
}

bool YN(){
    int YN;
    cout <<1<<'.'<<"Yes"<<endl;
    cout <<2<<'.'<<"No"<<endl;
    cin >> YN;
    if(YN==1){return true;}
    else{return false;}
}