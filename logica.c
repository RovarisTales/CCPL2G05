#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"




void logica (char *token){
    if(strncmp(token, "=",1) == 0){
        double X = POP();
        double Y = POP();
        if (X == Y) PUSH (0,'l');
        else PUSH (1,'l');
    }else if (strncmp(token, "e&",2) == 0){
        long a = POP();
        long b = POP();
        PUSH(a&b,'l');
    }else if (strncmp(token, "e|",2) == 0){
        long a = POP();
        long b = POP();
        PUSH(a|b,'l');
    }else if (strncmp(token, "e<",2) == 0){
        char a = POPT();
        double X = POP();
        char b = POPT();
        double Y = POP();
        if (X>Y) PUSH(Y,b);
        else PUSH (X,a);
    }else if (strncmp(token, "e>",2) == 0){
        char a = POPT();
        double X = POP();
        char b = POPT();
        double Y = POP();
        if (X<Y) PUSH(Y,b);
        else PUSH (X,a);
    }else if (strncmp(token, "?",1) == 0){
        char b = POPT();
        double X = POP();
        char a = POPT();
        double Y = POP();
        double Z = POP();

        if (Z) PUSH(Y,a);
        else PUSH (X,b);
    }

}