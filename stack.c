/**
 *@file Este ficheiro contem as funçoes utilizadas para realizar a struct/stack.
 *
 */

#include <stdio.h>
#include "stack.h"


/**
 *\brief Declaração de variaveis que correspondem ao tamanho maximo da stack,a struct, e o topo da stack respetivamente.
 *
 */

SPointer criaStack(SPointer s){
    s->top = -1;
    return s;
}

/**
 * \brief Esta funçao verifica se a SPointer se encontra vazia.
 * @return 1 se a stack estiver vazia e retorna 0 se tiver algum elemento.
 */

int vazio(SPointer s) {

    if(s->top == -1)
        return 1;
    else
        return 0;
}

/**
 * \brief Esta funçao retira o elemento mais acima na stack.
 * @param a Posição para onde vamos deslocar.
 */

void MOVE (int a,SPointer s){
    s->top = s->top + a;
}

/**
 * \brief Esta funçao retira o elemento mais acima na stack.
 * @return data que é o elemento mais acima na stack.
 */

Tipoval POP(SPointer s) {
    Tipoval data;
    if(!vazio(s)) {
        data.valor = s->stack[s->top].valor;
        data.tipo = s->stack[s->top].tipo;
        data.tipo2 = s->stack[s->top].tipo2;
        s->top = s->top - 1;
    }
    return data;
}


/**
 * \brief Esta função serve para retirar um elemento numa posição espefica na stack.
 * @param a Posição onde queremos retirar o elemento.
 * @return Retorna o elemento na posição da stack inserida.
 */

Tipoval MOVEPOP (int a, SPointer s){
    s->top = s->top - a;
    
    Tipoval x = POP(s);
    return x;
}

/**
 * \brief Esta funçao adiciona o elemento no topo da stack.
 * @param data elemento mais a cima na stack
 * @param a Tipo do valor
 */

void PUSH(Tipoval a, SPointer s) {
    s->top = s->top + 1;
    s->stack[s->top] = a;

}

/**
 * \brief Esta função imprime todos os elementos da stack.
 */

void print_stack(SPointer s){
    Tipoval data;
    int i=0;
    struct StackT stacks[10240];
    while(!vazio(s)) {
        data = POP(s);
        stacks[i].valor = data.valor;
        stacks[i].tipo = data.tipo;
        stacks[i].tipo2 = data.tipo2;
        i++;
        }
    for (i=i-1;i>-1;i--) {
        if((stacks[i].tipo2 != 'F') && (stacks[i].tipo2 != 'I')){
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
        }
    }putchar('\n');
}

