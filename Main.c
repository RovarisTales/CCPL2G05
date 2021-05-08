/**
 * @file Ficheiro que contém a função main do programa.
 * Esta função é a função inicial do programa que contem a função parse do modulo parser.h
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "parser.h"
#include "stack.h"
/**
 * \brief Função principal do programa
 * Esta função le um input introduzido pelo ser misterioso, realiza a função parser e imprime oque encontra-se na stack
 *
 * @return 0
 */
int main (){
    char line[10240];
    
    assert(fgets(line,10240,stdin)!=NULL);
   
    assert(line[strlen(line)- 1]== '\n');

    SPointer s;

    s = parser(line);
    print_stack(s);
    putchar('\n');
    return 0;
}



