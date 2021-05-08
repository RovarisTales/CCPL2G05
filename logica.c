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

void logicanormal (char *token, SPointer s){
    Tipoval true, false;
    true.valor = 1;
    true.tipo = 'i';
    false.valor = 0;
    false.tipo = 'i';

    if(strncmp(token, "=",1) == 0){
        Tipoval X = POP(s);
        Tipoval Y = POP(s);
        if (X.valor == Y.valor) PUSH (true,s);
        else PUSH (false,s);
    }else if (strncmp(token, "?",1) == 0){
        Tipoval X = POP(s);
        Tipoval Y = POP(s);
        Tipoval Z = POP(s);

        if (Z.valor) PUSH(Y,s);
        else PUSH (X,s);
    }else if (strncmp(token,"<",1) == 0){
        Tipoval X = POP(s);
        Tipoval Y = POP(s);
        if (Y.valor<X.valor) PUSH(true,s);
        else PUSH(false,s);
    }else if (strncmp(token,">",1) == 0){
        Tipoval X = POP(s);
        Tipoval Y = POP(s);
        if (Y.valor<X.valor) PUSH(false,s);
        else PUSH(true,s);
    }else if (strncmp(token,"!",1) == 0){
        Tipoval X = POP(s);
        if (X.valor==0) PUSH(true,s);
        else PUSH(false,s);
    }

}

void logicaE (char *token, SPointer s){
    Tipoval false;
    false.valor = 0;
    false.tipo = 'i';
    if (strncmp(token, "e&",2) == 0){
        Tipoval a = POP(s);
        Tipoval b = POP(s);
        Tipoval x;
        x.valor = 0;
        x.tipo = 'i';
        if (a.valor!= 0 && b.valor != 0) PUSH(a,s);
        else PUSH(x,s);
    }else if (strncmp(token, "e|",2) == 0){
        Tipoval a = POP(s);
        Tipoval b = POP(s);
        if (a.valor!= 0 || b.valor != 0) {
            if (b.valor != 0) PUSH(b,s);
            else PUSH(a,s);
        }else PUSH(false,s);
        
    }else if (strncmp(token, "e<",2) == 0){
        Tipoval X = POP(s);
        Tipoval Y = POP(s);
        if (X.tipo == 'a' || X.tipo == 's'){
            Tipoval um, dois;
            SPointer xis, ips;
            xis = Y.array;
            ips = X.array;
            SPointer one, two;
            one = NULL;
            two = NULL;
            one = copystack(xis,one);
            two = copystack(ips,two);
            int i = 0;

            while(i != 1  && !vazio(xis) && !vazio(ips)){
                um = POP(xis);
                dois = POP(ips);
                if(um.valor > dois.valor) i = 1;
                else i = 0;
            }

            if(i == 0) {    
                Y.array = one;
                PUSH(Y,s);
            }else {
                X.array = two;
                PUSH(X,s);
            }
        }
        else {
            if (X.valor>Y.valor) PUSH(Y,s);
        else PUSH (X,s);
        }
    }else if (strncmp(token, "e>",2) == 0){
        Tipoval X = POP(s);
        Tipoval Y = POP(s);
        if (X.tipo == 'a' || X.tipo == 's'){
            Tipoval um, dois;
            SPointer xis, ips;
            xis = Y.array;
            ips = X.array;
            SPointer one, two;
            one = NULL;
            two = NULL;
            one = copystack(xis,one);
            two = copystack(ips,two);
            int i = 0;

            while(i != 1  && !vazio(xis) && !vazio(ips)){
                um = POP(xis);
                dois = POP(ips);
                if(um.valor < dois.valor) i = 1;
                else i = 0;
            }

            if(i == 1) {    
                Y.array = one;
                PUSH(Y,s);
            }else {
                X.array = two;
                PUSH(X,s);
            }

        }else{
            if (X.valor<Y.valor) PUSH(Y,s);
            else PUSH (X,s);
        }
    }
}


void logica (char *token, SPointer s){
    if (strstr("=?<>!",token)){
        logicanormal(token,s);
    }
    else logicaE(token,s);
}



















