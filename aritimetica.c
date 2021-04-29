#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "parser.h"

long convertelong2 (double x){
    long l;
    l = x;
    x = l;
    return x;
}









void aritimeticasimples (char *oper){
    if (strcmp(oper, "-") == 0) {
        Tipoval  Y = POP ();
        Tipoval  X = POP ();
        X.tipo = comparatipo (Y.tipo,X.tipo);
        X.valor = X.valor - Y.valor;
        PUSH (X);
    } else if (strncmp(oper, "+",1) == 0) {

        Tipoval  Y = POP ();

        Tipoval  X = POP ();
        X.tipo = comparatipo (Y.tipo,X.tipo);
        X.valor = Y.valor + X.valor;
        PUSH (X);
    } else if (strncmp(oper, "*", 1) == 0) {
        Tipoval  Y = POP ();
        Tipoval  X = POP ();
        X.tipo = comparatipo (X.tipo,Y.tipo);
        X.valor = X.valor * Y.valor;
        PUSH (X);
    } else if (strncmp(oper, "/",1) == 0) {
        Tipoval  Y = POP ();
        Tipoval  X = POP ();
        X.tipo = comparatipo (Y.tipo,X.tipo);
        X.valor = X.valor / Y.valor;
        X.valor = convertelong (X.valor,X.tipo);
        
        PUSH (X);

    }

}

void aritimeticaresto (char *oper){
    if (strncmp(oper, "#",1) == 0) {
        Tipoval  Y = POP ();
        Tipoval  X = POP ();
        X.valor = pow (X.valor,Y.valor);
        X.tipo = 'f';
        PUSH (X);
    } else if (strncmp(oper, "%",1) == 0) {
        Tipoval  Y = POP ();
        Tipoval  X = POP ();
        long a =X.valor;
        long b = Y.valor;
        X.valor = a%b;
        PUSH (X);
    } else if (strncmp(oper, "(",1) == 0) {
        Tipoval  X = POP ();
        X.valor = X.valor - 1;
        PUSH (X);
    } else if (strncmp(oper, ")",1) == 0) {
        Tipoval  X = POP ();
        X.valor = X.valor + 1;
        PUSH (X);
    }


}



void aritimetica (char *oper){
    if (strstr ("+*/-",oper)){
        aritimeticasimples (oper);
    }
    else if (strstr("#%()",oper)){
        aritimeticaresto(oper);
    }

}
