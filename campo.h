//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_CAMPO_H
#define PROYECTO_FINAL_CAMPO_H

#include "ventana.h"
#include "figura.h"

using namespace std;

class Campo:public Ventana{
    Cuadro mC[10][20];
    int x;
    int y;
    int Fx;
    int Fy;
    Figura f[2];
    int nF;
    long int puntuacion;
    int nivel;
    char m;
public:
    Campo():Ventana(){
        m=NULL;
        nivel=1;
        x=2;
        y=2;
        Fx=x+10;
        Fy=y+3;
        nF=rand()%4;
        f[0]=Figura();
        f[1]=Figura(nF,x+10,y+1);
        for(int i=0;i<20;i++){
            for(int j=0;j<10;j++){
                mC[j][i]=Cuadro(false);
            }
        }
        puntuacion =0;
    }
    Campo(char n):Ventana(n){
        m=NULL;
        x=2;
        y=2;
        nivel=1;
        nF=rand()%4;
        f[0]=Figura();
        f[1]=Figura();
        for(int i=0;i<20;i++){
            for(int j=0;j<10;j++){
                mC[j][i]=Cuadro(false);
            }
        }
        puntuacion =0;

    }
    void limpiarCampo(){
        for(int i=x+1;i<x+21;i++){
            for(int j=y;j<y+41;j++){
                pos(j,i);
                printf(" ");
            }
        }
    }
    void mostrarCampo(){
        mostrarMarco();
        generarFigura();
        f[0].moverFigura(x,y);
    }
    void generarFigura(){
        if(!f[0].getLleno()){
            f[0]=f[1];
            nF=rand()%4;
            f[1]=Figura(6,x+10,y+3);
        }
    }
    void mostrarMarco(){
        SetConsoleTextAttribute(getH(),13);
        pos(x,y);
        printf("%c",201);
        pos(x+21,y);
        printf("%c",187);
        pos(x,y+41);
        printf("%c",200);
        pos(x+21,y+41);
        printf("%c",188);
        pos(x+23,y);
        printf("%c",201);
        pos(x+23,y+7);
        printf("%c",200);
        pos(x+30,y);
        printf("%c",187);
        pos(x+30,y+7);
        printf("%c",188);
        for(int k=x+24;k<x+30;k++){
            pos(k,y);
            printf("%c",205);
            pos(k,y+7);
            printf("%c",205);
        }
        for(int l=y+1;l<y+7;l++){
            pos(x+23,l);
            printf("%c",186);
            pos(x+30,l);
            printf("%c",186);
        }
        for(int i=y+1;i<y+41;i++){
            pos(x,i);
            printf("%c",186);
            pos(x+21,i);
            printf("%c",186);
        }
        for(int j=x+1;j<x+21;j++){
            pos(j,y);
            printf("%c",205);
            pos(j,y+41);
            printf("%c",205);
        }
        pos(x+26,y+4);
        printf("%i",nF);
        pos(x+23,y+11);
        SetConsoleTextAttribute(getH(),10);
        printf("NIVEL");
        pos(x+23,y+13);
        SetConsoleTextAttribute(getH(),3);
        printf("%i",nivel);
        pos(x+23,y+16);
        SetConsoleTextAttribute(getH(),10);
        printf("PUNTUACION");
        pos(x+23,y+18);
        SetConsoleTextAttribute(getH(),3);
        printf("%li",puntuacion);
    }
    void mostrarVentana()override{
        do{
            mostrarCampo();
        }while(true);
    }

    bool gameOver(){
        return false;
    }

    string getTipo()override{
        return "Campo";
    }
};

#endif //PROYECTO_FINAL_CAMPO_H
