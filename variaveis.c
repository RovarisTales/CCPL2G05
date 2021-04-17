#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

void variaveis(char *token, double *alfabeto){

    
    if (strncmp(token,":",1) == 0) {

        int a = token[1];

        a = a-65;
        char A = POPT();
        double x = POP();

        alfabeto[a] = x;

        PUSH(x,A);
    }
    if (strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZ",token) != NULL){
        int a = token[0];

        a=a-65;
        if ((a == 14) || (a == 18)){
        double x = alfabeto[a];
        char b = 'c';
        PUSH(x,b);
        }
        else {
            double x = alfabeto[a];
            char c = 'i';
            PUSH(x,c);
            
        }

    }

}
