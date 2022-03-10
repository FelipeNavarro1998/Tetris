//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_JUGADOR_H
#define PROYECTO_FINAL_JUGADOR_H

#include "persona.h"

class Jugador:public Persona{
private:
    long int puntuacion;
public:
    Jugador():Persona(){
        puntuacion=0;
    }
    Jugador(long int nPuntuacion,string nNombre):Persona(nNombre){
        puntuacion=nPuntuacion;
    }
    long int getPuntuacion(){
        return puntuacion;
    }
    void setPuntuacion(long int n){
        puntuacion=n;
    }
    void mostrarJugador(int x,int y)override{
        pos(x,y);
        string n=getNombre();
        printf("%s",&n);
        pos(x+15,y);
        printf("%i ",&puntuacion);
    }
};


#endif //PROYECTO_FINAL_JUGADOR_H
