/**
 * @file É o ficheiro que contem a função quando detetamos tokens relativamente ás expressões matemáticas binárias.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

/**
 * \brief Função relacionada com as expressões matemáticas binárias.
 * @param token dentro dos mencionados no parser ("&|^~")
 */

void logicabin (char *token){
    if (strncmp(token, "&",1) == 0) {
        Tipoval  X = POP ();
        Tipoval  Y = POP ();
        long x,y;
        x = X.valor;
        y = Y.valor;
        X.valor = x&y;
        PUSH(X);

    }else if (strncmp(token, "|",1) == 0) {
        Tipoval  X = POP ();
        Tipoval  Y = POP ();
        long x,y;
        x = X.valor;
        y = Y.valor;
        X.valor = x | y;

        PUSH(X);

    }else if (strncmp(token, "^",1) == 0) {
        Tipoval  X = POP ();
        Tipoval  Y = POP ();
        long x,y;
        x = X.valor;
        y = Y.valor;
        X.valor = x ^ y;

        PUSH(X);

       }else if (strncmp(token, "~",1) == 0) {
        Tipoval  X = POP ();
        long A = X.valor;
        X.valor = ~A;

        PUSH(X);
       }
}
