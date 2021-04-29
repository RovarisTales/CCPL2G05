#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

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

void convertetipo (char *token){
    if(strncmp(token, "i",1) == 0){
            
        Tipoval x = POP();
        x.tipo = 'i';
        x.valor = converte(x.valor, 'i');
        PUSH(x);

    }else if(strncmp(token, "f",1) == 0){
        
        Tipoval x = POP();
        x.tipo = 'f';
        x.valor = converte(x.valor, 'f');
          
        PUSH(x);

    }else if(strncmp(token, "c",1) == 0){
        Tipoval x = POP();
        x.tipo = 'c';
        x.valor = converte(x.valor, 'c');
        PUSH(x);
            
    }
}