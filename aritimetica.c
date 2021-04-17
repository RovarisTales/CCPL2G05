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
 * \brief Função relacionada com as expressões matemáticas
 * @param oper Token dentro dos mencionados no parser ("-+/*#%()")
 */

void aritimetica (char *oper){
    if (strcmp(oper, "-") == 0) {
        char A = POPT();
        double  Y = POP ();
        char B = POPT();
        double  X = POP ();
        A = comparatipo (A,B);
        PUSH (X - Y,A);
    } else if (strncmp(oper, "+",1) == 0) {
        char A = POPT();
        double  Y = POP ();
        char B = POPT();
        double  X = POP ();
        A = comparatipo (A,B);
        PUSH (X + Y,A);
    } else if (strncmp(oper, "*", 1) == 0) {
        char A = POPT();
        double  Y = POP ();
        char B = POPT();
        double  X = POP ();
        double a = X*Y;
        A = comparatipo (A,B);
        PUSH (a,A);
    } else if (strncmp(oper, "/",1) == 0) {
        char A = POPT();
        double  Y = POP ();
        char B = POPT();
        double  X = POP ();
        A = comparatipo(A,B);
        double T = X / Y;
        T = convertelong (T,A);
        
        PUSH (T,A);
    } else if (strncmp(oper, "#",1) == 0) {
        double  Y = POP ();
        double  X = POP ();
        PUSH (pow (X,Y),'f');
    } else if (strncmp(oper, "%",1) == 0) {
        long  Y = POP ();
        long  X = POP ();
        
        PUSH (X % Y,'i');
    } else if (strncmp(oper, "(",1) == 0) {
        char A = POPT();
        double  X = POP ();
        X = X - 1;
        PUSH (X,A);
    } else if (strncmp(oper, ")",1) == 0) {
        char A = POPT();
        double  X = POP ();
        X = X + 1;
        PUSH (X,A);
    }


}




