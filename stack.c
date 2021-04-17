/**
 *@file Este ficheiro contem as funçoes utilizadas para realizar a struct/stack.
 *
 */

#include <stdio.h>

/**
 *\brief Definir uma struct.
 *
 */

struct StackT{
    double valor;
    char tipo ;

};

/**
 *\brief Declaração de variaveis que correspondem ao tamanho maximo da stack,a struct, e o topo da stack respetivamente.
 *
 */

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

/**
 * \brief Esta funçao retira o elemento mais acima na stack.
 * @param a Posição para onde vamos deslocar.
 */

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
 * \brief Esta funçao verifica se a stack se encontra cheia.
 * @return 1 se a stack estiver cheia e retorna 0 se não estiver cheia.
 */

char POPT(){
    char a= 'l';
    if(!vazio()){
        a = stack[top].tipo;
    }
    return a;
}

/**
 * \brief Esta funçao retira o elemento mais acima na stack.
 * @return data que é o elemento mais acima na stack.
 */

double POP() {
    double data = 0;
    if(!vazio()) {
        data = stack[top].valor;
        top = top - 1;
    }
    return data;
}

/**
 * \brief Esta função serve para retirar um elemento numa posição espefica na stack.
 * @param a Posição onde queremos retirar o elemento.
 * @return Retorna o elemento na posição da stack inserida.
 */

double MOVEPOP (int a){
    top = top - a;
    
    double x = POP();
    return x;
}

/**
 * \brief Esta funçao adiciona o elemento no topo da stack.
 * @param data elemento mais a cima na stack
 * @param a Tipo do valor
 */

void PUSH(double data,char a) {

    if(!cheio()) {
        top = top + 1;
        stack[top].valor = data;
        stack[top].tipo = a;
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

