//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_PERSONA_H
#define PROYECTO_FINAL_PERSONA_H

#include <string>
#include "pos.h"

using namespace std;

class Persona:public Pos{
private:
    string nombre;
public:
    Persona():Pos(){
        nombre="";
    }
    Persona(string nNombre):Pos(){
        nombre=nNombre;
    }
    void setNombre(string n){
        nombre=n;
    }
    string getNombre(){
        return nombre;
    }
    virtual void mostrarJugador(int x, int y)=0;
};

#endif //PROYECTO_FINAL_PERSONA_H
