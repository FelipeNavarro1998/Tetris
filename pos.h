//
// Created by lfnv1 on 9/03/2022.
//

#ifndef PROYECTO_FINAL_POS_H
#define PROYECTO_FINAL_POS_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Pos{
private:
    HANDLE h;
    COORD c;
    CONSOLE_CURSOR_INFO cci;
    SMALL_RECT windowSize;
    CONSOLE_FONT_INFOEX fuente;
public:
    Pos(){
        fuente.cbSize=20;
        fuente.FontWeight=30;
        fuente.dwFontSize={50,30};
        windowSize={0, 0, 40, 50};
        h= GetStdHandle(STD_OUTPUT_HANDLE);
        cci.dwSize=2;
        cci.bVisible=FALSE;
        c.X=0;
        c.Y=0;
    }
    HANDLE getH(){
        return h;
    }
    COORD getC(){
        return c;
    }
    CONSOLE_CURSOR_INFO getCci(){
        return cci;
    }
    void setH(HANDLE n){
        h=n;
    }
    void setC(COORD n){
        c=n;
    }
    void setCci(CONSOLE_CURSOR_INFO n){
        cci=n;
    }
    void pos(int x,int y){
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(h,c);
    }
    void oCursor(){
        SetConsoleCursorInfo(h,&cci);
    }
    void sizeConsola(){
        SetConsoleWindowInfo(h, 1, &windowSize);
    }
    void sizeMenu(){
        SetCurrentConsoleFontEx(h,1,&fuente);
    }
};

#endif //PROYECTO_FINAL_POS_H
