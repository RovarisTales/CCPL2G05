/**
 * @file É o ficheiro que contem a função quando detetamos tokens relativamente á manipulação da stack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

/**
 * \brief Função relacionada com a manipulação da stack
 * @param token dentro dos mencionados no parser ("_;\@$")
 */

void manipstack (char *token, SPointer s){
    if (strncmp(token, "_",1) == 0) {
        Tipoval  Y = POP (s);
        Tipoval X = Y;
        SPointer x = NULL;
        if (Y.tipo == 's' || Y.tipo == 'a'){
            x = copystack(Y.array,x);
            X.array = x;
            }
        PUSH (X,s);
        PUSH (Y,s);
        
    }else if (strncmp(token, ";",1) == 0) {
        Tipoval  X = POP (s);
        X.valor++;

    }else if (strcmp(token, "\\") == 0) {

        Tipoval  X = POP (s);

        Tipoval  Y = POP (s);
        
        PUSH (X,s);
        PUSH (Y,s);

    }else if (strncmp(token, "@",1) == 0) {
        

        Tipoval  X = POP (s);

        Tipoval  Y = POP (s);

        Tipoval  Z = POP (s); 
        PUSH (Y,s);
        PUSH (X,s);
        PUSH (Z,s);
    }else if(strncmp(token, "$",1) == 0){
            Tipoval x = POP(s);
            Tipoval a = MOVEPOP(x.valor,s);
            PUSH(a,s);
            MOVE(x.valor,s);
            PUSH(a,s);
    }
}
