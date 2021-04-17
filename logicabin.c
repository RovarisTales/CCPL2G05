#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"

void logicabin (char *token){
    if (strncmp(token, "&",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        long A = X & Y;
        PUSH(A,'l');

    }else if (strncmp(token, "|",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        long A = X | Y;

        PUSH(A,'l');

    }else if (strncmp(token, "^",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        long A = X ^ Y;

        PUSH(A,'l');

       }else if (strncmp(token, "~",1) == 0) {
        long  X = POP ();
        long A = ~X;

        PUSH(A,'l');
       }
}