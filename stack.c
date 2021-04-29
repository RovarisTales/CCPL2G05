/**
 *@file Este ficheiro contem as funçoes utilizadas para realizar a stack.
 *
 */
#include <stdio.h>
#include "stack.h"


int MAXSIZE = 10240;
struct StackT stack[10240];
int top = -1;

/**
 * \brief Esta funçao verifica se a stack se encontra vazia.
 * @return 1 se a stack estiver vazia e retorna 0 se tiver algum elemento.
 */

int vazio() {

    if(top == -1)
        return 1;
    else
        return 0;
}

void MOVE (int a){
    top = top + a;
}

/**
 * \brief Esta funçao verifica se a stack se encontra cheia.
 * @return 1 se a stack estiver cheia e retorna 0 se não estiver cheia.
 */

int cheio(){
    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}

/**
 * \brief Esta funçao retira o elemento mais acima na stack.
 * @return data que é o elemento mais acima na stack.
 */

Tipoval POP() {
    Tipoval data;
    if(!vazio()) {
        data.valor = stack[top].valor;
        data.tipo = stack[top].tipo;
        top = top - 1;
    }
    return data;
}

Tipoval MOVEPOP (int a){
    top = top - a;
    
    Tipoval x = POP();
    return x;
}

/**
 * \brief Esta funçao adiciona o elemento no topo da stack.
 */

void PUSH(Tipoval a) {

    if(!cheio()) {
        top = top + 1;
        stack[top] = a;
    }
}

/**
 * \brief Esta função imprime todos os elementos da stack.
 */

void print_stack(){
    Tipoval data;
    int i=0;
    struct StackT stacks[10240];
    while(!vazio()) {
        data = POP();
        stacks[i].valor = data.valor;
        stacks[i].tipo = data.tipo;
        i++;
        }
    for (i=i-1;i>-1;i--) {
        if(stacks[i].tipo == 'c'){
            char cara = stacks[i].valor;
            printf("%c", cara);
            }else if (stacks[i].tipo == 'i'){
                int inteiro = stacks[i].valor;
                printf("%d", inteiro);
            }else if (stacks[i].tipo == 'l'){
                long floate = stacks[i].valor;
                printf("%ld", floate);
            }else if (stacks[i].tipo == 'f'){
                printf("%g", stacks[i].valor);
            }
    }putchar('\n');
}

