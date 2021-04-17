#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

void variaveis(char *token){

    struct StackT{
    double valor;
    char tipo ;

    };
    struct StackT alfabeto[26] = {
        {10,'i'},
        {11,'i'},
        {12,'i'},
        {13,'i'},
        {14,'i'},
        {15,'i'},
        {0,'i'},
        {0,'i'},
        {0,'i'},
        {0,'i'},
        {0,'i'},
        {0,'i'},
        {0,'i'},
        {0,'c'},
        {0,'i'},
        {0,'i'},
        {0,'i'},
        {0,'i'},
        {0,'i'},
        {32,'c'},
        {0,'i'},
        {0,'i'},
        {0,'i'},
        {0,'i'},
        {1,'i'},
        {0,'i'},
            };
    
    if (strncmp(token,":",1) == 0) {

        int a = token[1];

        a = a-65;
        char A = POPT();
        double x = POP();

        alfabeto[a].tipo = A;
        alfabeto[a].valor = x;

        PUSH(x,A);
    }
    if (strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZ",token) != NULL){
        int a = token[0];

        a=a-65;

        char b = alfabeto[a].tipo;
        double x = alfabeto[a].valor;

        PUSH(x,b);

    }

}
