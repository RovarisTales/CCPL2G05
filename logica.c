#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"




void logica (char *token){
    if(strncmp(token, "=",1) == 0){
        double X = POP();
        double Y = POP();
        if (X == Y) PUSH (1,'l');
        else PUSH (0,'l');
    }else if (strncmp(token, "e&",2) == 0){
        double a = POP();
        double b = POP();
        if (a!= 0 && b != 0) PUSH(a&b,'f');
        else PUSH(0,'i')
    }else if (strncmp(token, "e|",2) == 0){
        char A = POPT();
        double a = POP();
        char B = POPT();
        double b = POP();
        if (a!= 0 || b != 0) (a|b,'f');
        else PUSH(0,'l');
        
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
    }else if (strncmp(token,"<",1) == 0){
        long X = POP();
        long Y = POP();
        if (Y<X) PUSH(1,'i');
        else PUSH(0,'i');
    }else if (strncmp(token,">",1) == 0){
        long X = POP();
        long Y = POP();
        if (Y<X) PUSH(0,'i');
        else PUSH(1,'i');
    }else if (strncmp(token,"!",1) == 0){
        long X = POP();
        if (X==0) PUSH(1,'i');
        else PUSH(0,'i');
    }

}
