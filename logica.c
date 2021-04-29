/**
 * @file É o ficheiro que contem a função quando detetamos tokens relativamente á logica.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"
/**
 * \brief Função relacionada com a logica.
 * @param token dentro dos mencionados no parser ("=e&e|e<e>?")
 */

void logicanormal (char *token){
    Tipoval true, false;
    true.valor = 1;
    true.tipo = 'i';
    false.valor = 0;
    false.tipo = 'i';

    if(strncmp(token, "=",1) == 0){
        Tipoval X = POP();
        Tipoval Y = POP();
        if (X.valor == Y.valor) PUSH (true);
        else PUSH (false);
    }else if (strncmp(token, "?",1) == 0){
        Tipoval X = POP();
        Tipoval Y = POP();
        Tipoval Z = POP();

        if (Z.valor) PUSH(Y);
        else PUSH (X);
    }else if (strncmp(token,"<",1) == 0){
        Tipoval X = POP();
        Tipoval Y = POP();
        if (Y.valor<X.valor) PUSH(true);
        else PUSH(false);
    }else if (strncmp(token,">",1) == 0){
        Tipoval X = POP();
        Tipoval Y = POP();
        if (Y.valor<X.valor) PUSH(false);
        else PUSH(true);
    }else if (strncmp(token,"!",1) == 0){
        Tipoval X = POP();
        if (X.valor==0) PUSH(true);
        else PUSH(false);
    }

}

void logicaE (char *token){
    Tipoval false;
    false.valor = 0;
    false.tipo = 'i';
    if (strncmp(token, "e&",2) == 0){
        Tipoval a = POP();
        Tipoval b = POP();
        Tipoval x;
        x.valor = 0;
        x.tipo = 'i';
        if (a.valor!= 0 && b.valor != 0) PUSH(a);
        else PUSH(x);
    }else if (strncmp(token, "e|",2) == 0){
        Tipoval a = POP();
        Tipoval b = POP();
        if (a.valor!= 0 || b.valor != 0) {
            if (b.valor != 0) PUSH(b);
            else PUSH(a);
        }else PUSH(false);
        
    }else if (strncmp(token, "e<",2) == 0){
        Tipoval X = POP();
        Tipoval Y = POP();
        if (X.valor>Y.valor) PUSH(Y);
        else PUSH (X);
    }else if (strncmp(token, "e>",2) == 0){
        Tipoval X = POP();
        Tipoval Y = POP();
        if (X.valor<Y.valor) PUSH(Y);
        else PUSH (X);
    }
}


void logica (char *token){
    if (strstr("=?<>!",token)){
        logicanormal(token);
    }
    else logicaE(token);
}



















