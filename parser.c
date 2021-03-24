/**
 * @file É o ficheiro que contém a função parser, que separa o input em tokens e realiza as operaçoes baseado na stack.
 *Neste ficheiro também esta a ser usado o ficheiro stack.h.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
/*
void swapM (int *x, int *y){
    int t = *x; 
    *x = *y; 
    *y = t; 
}

void swap (int v[], int i, int j){
    swapM(v+i,v+j);
}

void inverteArray (int v[], int N){
    int i,j;
    j = N-1;
    i=0;
    while(i<j){
        swap(v,i,j);
        i++;
        j--;
    }
}

int convertedecimal(int a[]){
int i;
long x=0;

for(i=0;i<16;i++){
 if (a[i]==1){x=x+pow(2,i);}
}
return x;
}
void convertebinario(long x, int a[]){
    int i;
    for(i=0;x>0;i++){
    a[i]=x%2;
    x=x/2;
    }
}
*/
/**
 * \brief Realiza as operações utilizando as funçoes da stack.
 *
 * Estas operações dependem do caracter introduzido.
 *
 * @param line A linha que foi lida na main para realizar o parser.
 */
void parser (char *line){
    char delimit[8] = " \n\t";
    char *token;
    for(token = strtok(line, delimit); token != NULL;token = strtok(NULL, delimit) ){
        char *sobra;
        long valint = strtol(token, &sobra, 10);
        if (strlen(sobra) == 0){
            PUSH(valint);
    }else if (strncmp(token, "-",1) == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (X - Y);
    } else if (strncmp(token, "+",1) == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (X + Y);
    } else if (strncmp(token, "*", 1) == 0) {
        long  Y = POP ();
        long  X = POP ();
        long a = X*Y;
        PUSH (a);
    } else if (strncmp(token, "/",1) == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (X / Y);
    } else if (strncmp(token, "#",1) == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (pow (X,Y));
    } else if (strncmp(token, "%",1) == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (X % Y);
    } else if (strncmp(token, "(",1) == 0) {
        long  X = POP ();
        X = X - 1;
        PUSH (X);
    } else if (strncmp(token, ")",1) == 0) {
        long  X = POP ();
        X = X + 1;
        PUSH (X);
/*  }else if (strncmp(token, "&",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        int a[16]={0};
        convertebinario (X, a);
        int b[16]={0};
        convertebinario (Y, b);
        inverteArray (a,16);
        inverteArray (b,16);
        int i;
        int resultado[16]={0};
        for(i=0;i<16;i++){
            if(a[i]==1 && b[i]==1) resultado[i] = 1;
            else resultado[i] = 0;
        }
        inverteArray (resultado,16);
        long A = convertedecimal (resultado);
        PUSH(A);

    }else if (strncmp(token, "|",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        int a[16]={0};
        convertebinario (X, a);
        int b[16]={0};
        convertebinario (Y, b);
        inverteArray (a,16);
        inverteArray (b,16);
        int i;
        int resultado[16]={0};
        for(i=0;i<16;i++){
            if(a[i]==1 || b[i]==1) resultado[i] = 1;
            else resultado[i] = 0;
        }
        inverteArray (resultado,16);
        long A = convertedecimal (resultado);

        PUSH(A);

    }else if (strncmp(token, "^",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        int a[16]={0};
        convertebinario (X, a);
        int b[16]={0};
        convertebinario (Y, b);
        inverteArray (a,16);
        inverteArray (b,16);
        int i;
        int resultado[16]={0};
        for(i=0;i<16;i++){
            if(a[i] != b[i]) resultado[i] = 1;
            else resultado[i] = 0;
        }
        inverteArray (resultado,16);
        long A = convertedecimal (resultado);
        PUSH(A);

       }else if (strncmp(token, "~",1) == 0) {
        long  X = POP ();
        X = -X -1;
        PUSH(X);}*/
            
            
    }else if (strncmp(token, "&",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        long A = X & Y;
        PUSH(A);

    }else if (strncmp(token, "|",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        long A = X | Y;

        PUSH(A);

    }else if (strncmp(token, "^",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        long A = X ^ Y;

        PUSH(A);

       }else if (strncmp(token, "~",1) == 0) {
        long  X = POP ();
        long A = ~X;

        PUSH(A);

      }
        
    }
    print_stack();
}


