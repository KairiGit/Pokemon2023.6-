#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <limits>

enum Type{NOT,NOM,HON,MIZ,DEN,KUS,KOO,KAK,DOK,JIM,HIK,ESU,MUS,IWA,GOS,DRA,AKU,HAG,FEA};//18タイプ
enum Ailment{NOA,PAR,FRZ,PSN,BPSN,BRN};//状態異常
enum Cat{Physical,Spesial,Status};//技の分類
int flag;
void enter(){
    std::cout<<"\x1b[38;2;255;220;40m"<<'v'<<"\x1b[m"<<std::flush;//enterキーの要求
    flag = getchar();
}