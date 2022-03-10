//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_VENTANA_H
#define PROYECTO_FINAL_VENTANA_H


#include "figura.h"
#include <iostream>

using namespace std;

class Ventana:public Pos{
    char n;
public:
    Ventana():Pos(){
        n=NULL;
    }
    Ventana(char nN):Pos(){
        n=nN;
    }
    char getN(){
        return n;
    }
    void setN(char a){
        n=a;
    }
    virtual string getTipo()=0;
    virtual void mostrarVentana()=0;
};

#endif //PROYECTO_FINAL_VENTANA_H
