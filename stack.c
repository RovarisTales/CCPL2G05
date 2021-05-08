/**
 *@file Este ficheiro contem as funçoes utilizadas para realizar a struct/stack.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/**
 *\brief Como o próprio nome indica cria uma stack 
 * @param s Pointer para a stack
 * @param tamanho Tamanho da stack que queremos criar
 * return s Retorna a stack criada
 */
SPointer criaStack(SPointer s,int tamanho){
    s = malloc(sizeof(SPointer));
    s->top = -1;
    s-> stack = malloc(tamanho * (sizeof(Tipoval)));
    
    return s;
}

/**
 * \brief Esta funçao verifica se a SPointer se encontra vazia.
 * @param s Pointer para a stack principal
 * @return 1 se a stack estiver vazia e retorna 0 se tiver algum elemento.
 */

int vazio(SPointer s) {

    if(s->top == -1)
        return 1;
    else
        return 0;
}

/**
 * \brief Esta funçao move o top do pointer da stack para uma posição especifica
 * @param s Pointer para s stack principal
 * @param a Posição para onde vamos deslocar.
 */

void MOVE (int a,SPointer s){
    s->top = s->top + a;
}

/**
 * \brief Esta função copia a stack 
 * @param x Para onde vamos colocar a copia da stack
 * @param s Pointer para a stack principal
 * @return x Stack copiada
 */
SPointer copystack(SPointer s,SPointer x){
    x = criaStack(x,2048);
    Tipoval a[2048];
    int i = 0;
    while (!vazio(s)){
        a[i] = POP(s);
        i++;
    }
    int xpto;
    xpto = i;
    while(i!= -1){
        PUSH(a[i],s);
        i--;
    }
    i = xpto;
    while(i != -1){
        PUSH(a[i],x);
        i--;
    }
    return x;



}

/**
 * \brief Esta funçao remove o elemento no topo da stack
 * @param s Pointer para s stack principal
 * @return data Valor que vamos retirar
 */
Tipoval POP(SPointer s) {
    Tipoval data;
    if(!vazio(s)) {
        data = s->stack[s->top];
        s->top = s->top - 1;
        
    }
    

    
    return data;
}

/**
 * \brief Esta função serve para retirar um elemento numa posição espefica na stack.
 * @param a Posição onde queremos retirar o elemento.
 * @param s Pointer para a stack principal
 * @return Retorna o elemento na posição da stack inserida.
 */

Tipoval MOVEPOP (int a, SPointer s){
    s->top = s->top - a;
    
    Tipoval x = POP(s);
    return x;
}

/**
 * \brief Esta funçao adiciona o elemento colocado como argumento para o topo da stack
 * @param s Pointer para a stack principal
 * @param a Valor que queremos colocar na stack
 */

void PUSH(Tipoval a, SPointer s) {
    s->top = s->top + 1;
    
    s->stack[s->top] = a;
    
    
    
}
<<<<<<< HEAD

=======
>>>>>>> 66a9db34645337fc81027cb0fa9a48cb5df5b8b0
/**
 * \brief Esta função auxiliar ao print_stack que imprime o elemento colocado como argumento conforme o seu tipo
 * @param data Valor que queremos dar print
 */

void printnormal(Tipoval data){
        if(data.tipo == 'c'){
                char cara = data.valor;
                printf("%c", cara);
                }else if (data.tipo == 'i'){
                    int inteiro = data.valor;
                    printf("%d", inteiro);
                }else if (data.tipo == 'l'){
                    long floate = data.valor;
                    printf("%ld", floate);
                    
                }else if (data.tipo == 'f'){
                    printf("%g", data.valor);
            }
}

/**
 * \brief Esta funçao que imprime todos os elementos da stack
 * @param s Pointer para s stack principal
 */
void print_stack(SPointer s){
    
    Tipoval data;
    int i;
    Tipoval stacks[500];
    for(i = 0;vazio(s) != 1;i++) {
        
        data = POP(s);
        //if(data.array != NULL){ 
            //Tipoval xpto;
           // xpto = POP(data.array);
           // printf("printei da stack%g\n", xpto.valor);
        //}
        stacks[i]= data;
        
        }
    i --;
    while (i>-1){
        if (stacks[i].tipo != 'a' && stacks[i].tipo != 's'){
            
            printnormal(stacks[i]);
            
        }else print_stack (stacks[i].array);

            i--;
        }
    
}

