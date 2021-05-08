/**
 * @file É o ficheiro que contem a função quando detetamos tokens relativamente á expressões matemáticas.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "parser.h"

/**
 * \brief Função relacionada com as expressões matemáticas simples
 * @param oper Token dentro dos mencionados no parser ("-+/")
 */

void aritimeticasimples (char *oper, SPointer s){
    if (strcmp(oper, "-") == 0) {
        Tipoval  Y = POP (s);
        Tipoval  X = POP (s);
        X.tipo = comparatipo (Y.tipo,X.tipo);
        X.valor = X.valor - Y.valor;
        PUSH (X,s);
    } else if (strncmp(oper, "+",1) == 0) {

        Tipoval  Y = POP (s);

        Tipoval  X = POP (s);
        X.tipo = comparatipo (Y.tipo,X.tipo);
        X.valor = Y.valor + X.valor;
        PUSH (X,s);
    } else if (strncmp(oper, "*", 1) == 0) {
        Tipoval  Y = POP (s);
        Tipoval  X = POP (s);
        X.tipo = comparatipo (X.tipo,Y.tipo);
        X.valor = X.valor * Y.valor;
        PUSH (X,s);
    } else if (strncmp(oper, "/",1) == 0) {
        Tipoval  Y = POP (s);
        Tipoval  X = POP (s);
        X.tipo = comparatipo (Y.tipo,X.tipo);
        X.valor = X.valor / Y.valor;
        X.valor = convertelong (X.valor,X.tipo);
        
        PUSH (X,s);

    }

}

/**
 * \brief Função relacionada com as expressões matemáticas que requerem cuidado com o resto
 * @param oper Token dentro dos mencionados no parser ("#%()")
 */

void aritimeticaresto (char *oper, SPointer s){
    if (strncmp(oper, "#",1) == 0) {
        Tipoval  Y = POP (s);
        Tipoval  X = POP (s);
        X.valor = pow (X.valor,Y.valor);
        X.tipo = 'f';
        PUSH (X,s);
    } else if (strncmp(oper, "%",1) == 0) {
        Tipoval  Y = POP (s);
        Tipoval  X = POP (s);
        long a =X.valor;
        long b = Y.valor;
        X.valor = a%b;
        PUSH (X,s);
    } else if (strncmp(oper, "(",1) == 0) {
        Tipoval  X = POP (s);
        X.valor = X.valor - 1;
        PUSH (X,s);
    } else if (strncmp(oper, ")",1) == 0) {
        Tipoval  X = POP (s);
        X.valor = X.valor + 1;
        PUSH (X,s);
    }


}

/**
 * \brief Função que vai reencaminhar para as suas subfunções (aritimeticasimples e aritimeticaresto)
 * @param oper Token dentro dos mencionados no parser ("+*-/#%()")
 */

void aritimetica (char *oper, SPointer s){
    if (strstr ("+*/-",oper)){
        aritimeticasimples (oper, s);
    }
    else if (strstr("#%()",oper)){
        aritimeticaresto(oper, s);
    }

}
