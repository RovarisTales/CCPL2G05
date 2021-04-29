#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

void variaveis(char *token, Tipoval *alfabeto){

    
    if (strncmp(token,":",1) == 0) {

        int a = token[1];

        a = a-65;
        Tipoval x = POP();

        alfabeto[a] = x;

        PUSH(x);
    }
    if (strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZ",token) != NULL){
        int a = token[0];

        a=a-65;
        Tipoval x = alfabeto[a];
        PUSH(x);
    }
        

    

}
