//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_MENU_H
#define PROYECTO_FINAL_MENU_H

#include "ventana.h"

using namespace  std;

class Menu:public Ventana{
private:
    char op;
public:
    Menu():Ventana(){
        op=NULL;
    }
    Menu(char n):Ventana(){
        op=n;
    }
    char getOp(){
        return op;
    }
    void setOp(char n){
        op=n;
    }
    void mostrarVentana()override{
        pos(10,2);
        sizeMenu();
        SetConsoleTextAttribute(getH(),2);
        printf("T");
        pos(11,2);
        SetConsoleTextAttribute(getH(),3);
        printf("E");
        pos(12,2);
        SetConsoleTextAttribute(getH(),4);
        printf("T");
        pos(13,2);
        SetConsoleTextAttribute(getH(),5);
        printf("R");
        pos(14,2);
        SetConsoleTextAttribute(getH(),6);
        printf("I");
        pos(15,2);
        SetConsoleTextAttribute(getH(),3);
        printf("S");
        SetConsoleTextAttribute(getH(),7);
        pos(2,4);
        printf("1.) Nuevo Juego");
        pos(2,5);
        printf("2.) Tabla de Puntuaciones");
        pos(2,6);
        printf("3.) Opciones");
        pos(2,7);
        printf("4.) Salir");
        op=getch();
        system("cls");
        setN(op);
    };

    string getTipo()override{
        return "Menu";
    }
};

#endif //PROYECTO_FINAL_MENU_H
