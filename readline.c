/**
 * @file É o ficheiro que contem a função relacionado com o token l
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "stack.h"

/**
 * \brief Função que lê a linha seguinte quando o token 'l' é detetado na stack
 * @param token Token l
 */

void readline (char *token,SPointer s){
    if(strncmp(token, "l",1) == 0){
        char lerlinha [10240];
        char *oi;
        assert(fgets(lerlinha,10240,stdin)!=NULL);
        assert(lerlinha[strlen(lerlinha)- 1]== '\n');
        double a = strtod(lerlinha,&oi);
        Tipoval x;
        x.valor = a;
        x.tipo = 'f';
        PUSH(x,s);
    }
}
