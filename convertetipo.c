/**
 * @file É o ficheiro que contem a função quando detetamos tokens relativamente á conversão de tipo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

/**
 * \brief Função auxiliar do converte tipo
 * @param x valor para ser convertido
 * @param s pointer para a stack
 */

double converte(double x,char a){
        if (a == 'i'){
                int X = x;
                x = X;
                return x;
        }
        else if (a == 'f'){
                double X = x;
                x = X;
                return x;
        }
        else {
                long X = x;
                x = X;
                return x;
        }
}
/**
 * \brief Função relacionada com a conversão do tipo
 * @param token dentro dos mencionados no parser ("ifc")
 * @param s pointer para a stack
 */

void convertetipo (char *token, SPointer s){
    if(strncmp(token, "i",1) == 0){
            
        Tipoval x = POP(s);
        x.tipo = 'i';
        x.valor = converte(x.valor, 'i');
        PUSH(x,s);
    }else if(strncmp(token, "f",1) == 0){
        
        Tipoval x = POP(s);
        x.tipo = 'f';
        x.valor = converte(x.valor, 'f');
          
        PUSH(x,s);

    }else if(strncmp(token, "c",1) == 0){
        Tipoval x = POP(s);
        x.tipo = 'c';
        x.valor = converte(x.valor, 'c');
        PUSH(x,s);
            
    }
}
