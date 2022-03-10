//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_CUADRO_H
#define PROYECTO_FINAL_CUADRO_H

#include <stdio.h>
#include "pos.h"
#include <conio.h>

using namespace std;

class Cuadro:public Pos{
    int c[2][2];
public:
    Cuadro():Pos(){
        c[0][0]=201;
        c[1][0]=187;
        c[0][1]=200;
        c[1][1]=188;
    }
    Cuadro(bool n):Pos(){
        if(n){
            c[0][0]=201;
            c[1][0]=187;
            c[0][1]=200;
            c[1][1]=188;
        }
        else{
            c[0][0]=0;
            c[1][0]=0;
            c[0][1]=0;
            c[1][1]=0;
        }
    }
    void print(int x,int y){
        pos(x,y);
        printf("%c",c[0][0]);
        pos(x+1,y);
        printf("%c",c[1][0]);
        pos(x,y+1);
        printf("%c",c[0][1]);
        pos(x+1,y+1);
        printf("%c",c[1][1]);
    }
};


#endif //PROYECTO_FINAL_CUADRO_H
