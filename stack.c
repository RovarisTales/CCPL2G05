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
        data.array = s->stack[s->top].array;
        s->top = s->top - 1;
        printf("top diminuiu\n");
    }
    printf("popei %g\n",data.valor);
    printf("top é : %d\n", s->top);
    return data;
}
void PUSHARRAY(Tipoval a, SPointer s, SPointer mini){
    s->top = s->top + 1;
    printf("top aumentou\n");
    s->stack[s->top] = a;
    s->stack[s->top].array = mini;
    printf("pushei stack %g\n", a.valor);
    printf("pushei %c\n", a.tipo);
    
    printf("top é : %d\n", s->top);

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
    printf("top aumentou\n");
    s->stack[s->top] = a;
    printf("pushei %g\n", a.valor);
    printf("tipo: %c\n", a.tipo);
    printf("top é : %d\n", s->top);
}

/**
 * \brief Esta função imprime todos os elementos da stack.
 */

void print_stack2(SPointer s){
    Tipoval data;
    int i=0;
    struct StackT stacks[1024] = {{0}};
    while(!vazio(s)) {
        data = POP(s);
        stacks[i].valor = data.valor;
        printf("%g\n", data.valor);
        stacks[i].tipo = data.tipo;
        printf("%c\n", data.tipo);
        stacks[i].array = data.array;
        i++;
        }
    for (i=i-1;i>-1;i--){
        if (stacks[i].tipo != 'a'){
        
            if(stacks[i].tipo == 'c'){
                char cara = stacks[i].valor;
                printf("printei :");
                printf("%c\n", cara);
                }else if (stacks[i].tipo == 'i'){
                    int inteiro = stacks[i].valor;
                    printf("printei :");
                    printf("%d\n", inteiro);
                }else if (stacks[i].tipo == 'l'){
                    long floate = stacks[i].valor;
                    printf("printei :");
                    printf("%ld\n", floate);
                    
                }else if (stacks[i].tipo == 'f'){
                    printf("printei :");
                    printf("%g\n", stacks[i].valor);
            }
        }
    }
}

void print_stack(SPointer s){
    Tipoval data;
    int i=0;
    struct StackT stacks[1024] = {{0}};
    while(!vazio(s)) {
        data = POP(s);
        stacks[i].valor = data.valor;
        printf("%g\n", data.valor);
        stacks[i].tipo = data.tipo;
        printf("%c\n", data.tipo);
        stacks[i].array = data.array;
        i++;
        }
    for (i=i-1;i>-1;i--){
        if (stacks[i].tipo != 'a'){
        
            if(stacks[i].tipo == 'c'){
                char cara = stacks[i].valor;
                printf("printei :");
                printf("%c\n", cara);
                }else if (stacks[i].tipo == 'i'){
                    int inteiro = stacks[i].valor;
                    printf("printei :");
                    printf("%d\n", inteiro);
                }else if (stacks[i].tipo == 'l'){
                    long floate = stacks[i].valor;
                    printf("printei :");
                    printf("%ld\n", floate);
                    
                }else if (stacks[i].tipo == 'f'){
                    printf("printei :");
                    printf("%g\n", stacks[i].valor);
            }
        }else print_stack2(stacks[i].array);
    }
    putchar('\n');
}

