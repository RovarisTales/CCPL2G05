/**
 * @file É o ficheiro que contem a função quando detetamos tokens relativamente ás variaveis.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"


/**
 * \brief Função relacionada com as variáveis
 * @param token dentro dos mencionados no parser (":ABCDEFGHIJKLMNOPQRSTUVWXYZ")
 * @param alfabeto Letra do alfabeto em maiuscula que corresponde ao codigo ascii (65-90)
 */

void variaveisA(char *token, Tipoval *alfabeto, SPointer s){

    
    if (strncmp(token,":",1) == 0) {
        
        int a = token[1];

        a = a-65;
        Tipoval x = POP(s);
        
        alfabeto[a].valor = x.valor;
        alfabeto[a].tipo = x.tipo;
        if (x.tipo == 'a' || x.tipo == 's'){
            SPointer aux = NULL;
            aux = copystack(x.array,aux);
            alfabeto[a].array = aux;
        }
        PUSH(x,s);
    }  
}
   
   
void variaveisB(char *token, Tipoval *alfabeto,SPointer s){

    
     if (strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZ",token) != NULL){
        int a = token[0];

        a=a-65;
        Tipoval x;
         x.valor = alfabeto[a].valor;
         x.tipo = alfabeto[a].tipo;
        if(alfabeto[a].tipo == 's' || alfabeto[a].tipo == 'a'){
            SPointer aux = NULL;
            aux = copystack(alfabeto[a].array,aux);
            x.array = aux;
        }
        
        
        
        PUSH(x,s);
    }

}
void variaveis(char *token, Tipoval *alfabeto,SPointer s){
    if (strncmp(token,":",1) == 0) variaveisA(token, alfabeto,s);
    else variaveisB(token, alfabeto,s);

}

