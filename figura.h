//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_FIGURA_H
#define PROYECTO_FINAL_FIGURA_H

#include "cuadro.h"

using namespace std;

class Figura:public Pos{
private:
    COORD xF;
    Cuadro f[4][4];
    int nF;
    bool lleno;
    char m;
public:
    Figura():Pos(){
        m=NULL;
        nF=NULL;
        lleno=false;
        xF={};
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                f[j][i]=Cuadro(false);
            }
        }
    }
    Figura(int nNF,int nX, int nY):Pos(){
        nF=nNF;
        m=NULL;
        xF.X=nX;
        xF.Y=nY;
        switch(nF){
            case 0:
                cuadrado();
                break;
            case 1:
                barra();
                break;
            case 2:
                L();
                break;
            case 3:
                LInvertido();
                break;
            case 4:
                Z();
                break;
            case 5:
                ZInvertido();
                break;
            case 6:
                T();
                break;
        }
        lleno=true;
    }
    void cuadrado(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if((j==0 && i==0) || (j==0 && i==1) || (j==1 && i==0) || (j==1 && i==1)){
                    f[j][i]=Cuadro(true);
                }
                else{
                    f[j][i]=Cuadro(false);
                }
            }
        }
    }
    void barra(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if((j==0 && i==0) || (j==1 && i==0) || (j==2 && i==0) || (j==3 && i==0)){
                    f[j][i]=Cuadro(true);
                }
                else{
                    f[j][i]=Cuadro(false);
                }
            }
        }
    }
    void L(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++) {
                if ((j == 0 && i == 0) || (j == 0 && i == 1) || (j == 0 && i == 2) || (j == 1 && i == 2)) {
                    f[j][i] = Cuadro(true);
                } else {
                    f[j][i] = Cuadro(false);
                }
            }
        }
    }
    void LInvertido(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if((j==2 && i==0) || (j==2 && i==1) || (j==2 && i==2) || (j==1 && i==2)){
                    f[j][i]=Cuadro(true);
                }
                else{
                    f[j][i]=Cuadro(false);
                }
            }
        }
    }
    void Z(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if((j==0 && i==0) || (j==1 && i==0) || (j==1 && i==1) || (j==2 && i==1)){
                    f[j][i]=Cuadro(true);
                }
                else{
                    f[j][i]=Cuadro(false);
                }
            }
        }
    }
    void ZInvertido(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if((j==0 && i==1) || (j==1 && i==1) || (j==1 && i==0) || (j==2 && i==0)){
                    f[j][i]=Cuadro(true);
                }
                else{
                    f[j][i]=Cuadro(false);
                }
            }
        }
    }
    void T(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if((j==0 && i==0) || (j==1 && i==0) || (j==2 && i==0) || (j==1 && i==1)){
                    f[j][i]=Cuadro(true);
                }
                else{
                    f[j][i]=Cuadro(false);
                }
            }
        }
    }
    void moverFigura(int x, int y){
        mostrarFigura();
        m=getch();
        switch(m){
            case 'a':
                if(xF.X-3>x && xF.X<x+19){
                    xF.X--;
                }
                break;
            case 'd':
                if(xF.X+4<x+19 && xF.X-2>x){
                    xF.X++;
                }
                break;
            case 's':
                if(xF.Y+4<y+41){
                    xF.Y++;
                }
                break;
            case 'w':
                break;
        }
    }
    void mostrarFigura() {
        switch (nF) {
            case 0:
                SetConsoleTextAttribute(getH(),4);
                break;
            case 1:
                SetConsoleTextAttribute(getH(),3);
                break;
            case 2:
                SetConsoleTextAttribute(getH(),10);
                break;
            case 3:
                SetConsoleTextAttribute(getH(),9);
                break;
            case 4:
                SetConsoleTextAttribute(getH(),11);
                break;
            case 5:
                SetConsoleTextAttribute(getH(),6);
                break;
            case 6:
                SetConsoleTextAttribute(getH(),14);
                break;
        }
        f[1][1].print(xF.X,xF.Y);
        f[0][0].print(xF.X-2,xF.Y-2);
        f[1][0].print(xF.X,xF.Y-2);
        f[2][0].print(xF.X+2,xF.Y-2);
        f[3][0].print(xF.X+4,xF.Y-2);
        f[0][1].print(xF.X-2,xF.Y);
        f[0][2].print(xF.X-2,xF.Y+2);
        f[0][3].print(xF.X-2,xF.Y+4);
        f[1][2].print(xF.X,xF.Y+2);
        f[1][3].print(xF.X,xF.Y+4);
        f[2][0].print(xF.X+2,xF.Y-2);
        f[2][1].print(xF.X+2,xF.Y);
        f[2][2].print(xF.X+2,xF.Y+2);
        f[2][3].print(xF.X+2,xF.Y+4);
        f[3][1].print(xF.X+4,xF.Y);
        f[3][2].print(xF.X+4,xF.Y+2);
        f[3][3].print(xF.X+4,xF.Y+4);
    }
    COORD getXF(){
        return xF;
    }
    void setXF(COORD n){
        xF=n;
    }
    Cuadro getF(){
        return f;
    }
    bool getLleno(){
        return lleno;
    }
    void setLleno(bool n){
        lleno=n;
    }
};

#endif //PROYECTO_FINAL_FIGURA_H
