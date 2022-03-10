//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_JUEGO_H
#define PROYECTO_FINAL_JUEGO_H

#include "ventana.h"
#include "campo.h"
#include "menu.h"
#include "scoreboard.h"
#include "options.h"
#include "pos.h"

using namespace std;

class Juego:public Pos{
private:
    Ventana* v;
public:
    Juego():Pos(){
        v=new Menu() ;
    }
    void setV(Ventana* nV){
        v=nV;
    }
    Ventana* getV(){
        return v;
    }
    void cambiarVentana(){
        v->mostrarVentana();
        switch(v->getN()){
            case '0':
                v=new Menu();
                break;
            case '1':
                v=new Campo(v->getN());
                break;
            case '2':
                v=new ScoreBoard(v->getN());
                break;
            case '3':
                v=new Options(v->getN());
                break;
        }
    }
    void mostrarJuego(){
        do{
            system("cls");
            cambiarVentana();
        }
        while(v->getN()!='4' || v->getN()!='1');
        if(v->getN()=='1'){
            v->mostrarVentana();
        }
    }
};

#endif //PROYECTO_FINAL_JUEGO_H
