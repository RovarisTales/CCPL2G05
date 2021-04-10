/**
 *@file Este ficheiro contem as funçoes utilizadas para realizar a stack.
 *
 */
#include <stdio.h>
int MAXSIZE = 10240;
int stack[10240];
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
int POP() {
    int data = 0;

    if(!vazio()) {
        data = stack[top];
        top = top - 1;
    }
    return data;
}
/**
 * \brief Esta funçao adiciona o elemento no topo da stack.
 */
void PUSH(int data) {

    if(!cheio()) {
        top = top + 1;
        stack[top] = data;
    }
}
/**
 * \brief Esta função imprime todos os elementos da stack.
 */

void print_stack(){
    double data;
    int i=0;
    char a;
    struct StackT stacks[10240];
    while(!vazio()) {
        a = POPT();
        data = POP();
        stacks[i].valor = data;
        stacks[i].tipo = a;
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
