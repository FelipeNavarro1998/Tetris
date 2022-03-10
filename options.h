//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_OPTIONS_H
#define PROYECTO_FINAL_OPTIONS_H

#include "ventana.h"

using namespace std;

class Options:public Ventana{
private:
    char op;
    int dificultad;
public:
    Options():Ventana(){
        dificultad=0;
        op=NULL;
    }
    Options(char n):Ventana(n){
        dificultad=0;
        op=NULL;
    }
    string getTipo()override{
        return "Options";
    }
    void mostrarVentana()override{
        do {
            pos(2, 2);
            printf("Dificultad Actual: %i \n", dificultad);
            pos(2, 3);
            printf("presiona +/- para modificar la dificultad");
            pos(2, 7);
            printf("<- Para volver al menu anterior presiona 4...");
            op = getch();
            if(op=='+' && dificultad<20){
                dificultad++;
            }
            else{
                if(op=='-' && dificultad>0){
                    dificultad--;
                }
            }
            system("cls");
        }
        while(op!='4');
        setN('0');
    }
};
#endif //PROYECTO_FINAL_OPTIONS_H
