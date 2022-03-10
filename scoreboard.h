//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_SCOREBOARD_H
#define PROYECTO_FINAL_SCOREBOARD_H

#include "jugador.h"
#include "ventana.h"
#include "vector"

using namespace  std;

class ScoreBoard:public Ventana{
private:
    char op;
    vector<Jugador> j;
public:
    ScoreBoard():Ventana(){
        j={};
    }
    ScoreBoard(char n):Ventana(n){
        j={};
    }
    ScoreBoard(vector<Jugador> nJ):Ventana(){
        j=nJ;
    }
    vector <Jugador> getJ(){
        return j;
    }
    void setJ(vector<Jugador> n){
        j=n;
    }
    void mostrarVentana()override{
        pos(2,2);
        SetConsoleTextAttribute(getH(),10);
        printf("-Jugador-");
        pos(17,2);
        printf("-Puntuacion-");
        SetConsoleTextAttribute(getH(),7);
        for(int i=3;i<j.size();i++){
            j[i].mostrarJugador(2,i+1);
        }
        getch();
        setN('0');
        system("cls");
    }

    string getTipo()override{
        return "ScoreBoard";
    }
};


#endif //PROYECTO_FINAL_SCOREBOARD_H
