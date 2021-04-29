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

void manipstack (char *token){
    if (strncmp(token, "_",1) == 0) {
        Tipoval  Y = POP ();
        PUSH (Y);
        PUSH (Y);
        
    }else if (strncmp(token, ";",1) == 0) {
        Tipoval  X = POP ();
        X.valor++;

    }else if (strcmp(token, "\\") == 0) {

        Tipoval  X = POP ();

        Tipoval  Y = POP ();
        
        PUSH (X);
        PUSH (Y);

    }else if (strncmp(token, "@",1) == 0) {
        

        Tipoval  X = POP ();

        Tipoval  Y = POP ();

        Tipoval  Z = POP (); 
        PUSH (Y);
        PUSH (X);
        PUSH (Z);
    }else if(strncmp(token, "$",1) == 0){
            Tipoval x = POP();
            Tipoval a = MOVEPOP(x.valor);
            PUSH(a);
            MOVE(x.valor);
            PUSH(a);
    }
}
