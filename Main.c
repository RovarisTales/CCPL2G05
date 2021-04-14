/**
 * @file Ficheiro que contém a função main do programa.
 * Esta função é a função inicial do programa que contem a função parse do modulo parser.h
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "parser.h"
/**
 * \brief Função principal do programa
 * Esta função le um input introduzido pelo ser misterioso e realiza a função parser.
 *
 * @return 0
 */
int main (){
    char line[10240];
    assert(fgets(line,10240,stdin)!=NULL);
    assert(line[strlen(line)- 1]== '\n');
    parser(line);
    return 0;
}


// isso é um teste
