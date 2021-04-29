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

void variaveis(char *token, Tipoval *alfabeto){

    
    if (strncmp(token,":",1) == 0) {

        int a = token[1];

        a = a-65;
        Tipoval x = POP();

        alfabeto[a] = x;

        PUSH(x);
    }
    if (strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZ",token) != NULL){
        int a = token[0];

        a=a-65;
        Tipoval x = alfabeto[a];
        PUSH(x);
    }
        

    

}
