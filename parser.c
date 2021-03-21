#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"
#include "stack.h"

void swap (int *x, int *y){
    int t = *x; 
    *x = *y; 
    *y = t; 
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
int convertdecimal(int a[16]){
int i;
long x=0;

for(i=0;i<=16;i++){
 if (a[i]==1){x=x+powerbruh(2,i);}
}
return x;
}
int convertbinário(int x){  
    int a[16],x,i;     
    for(i=0;x>0;i++){    
    a[i]=x%2;    
    x=x/2;}    
    return a[16];  
}

void parser (char *line){
    char *delimit = " /n/t";
    
    for(char *token = strtok(line, demilit);token != NULL; token = strtok(NULL, demilit)){
        char *sobra;
        long valint = strtol(token; &sobra; 10);
        if (strlen(sobra) == 0){
            PUSH(valint);
    }else if (strcmp(token, "-") == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (X - Y);
    } else if (strcmp(token, "+") == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (X + Y);
    } else if (strcmp(token, "*") == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (X * Y);
    } else if (strcmp(token, "/") == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (X / Y);
    } else if (strcmp(token, "#") == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (pow (X,Y));
    } else if (strcmp(token, "%") == 0) {
        long  Y = POP ();
        long  X = POP ();
        PUSH (X % Y);
    } else if (strcmp(token, "(") == 0) {
        long  X = POP ();
        PUSH (X--);
    } else if (strcmp(token, ")") == 0) {
        long  X = POP ();
        PUSH (X++);
    }else if (strcmp(token, "&") == 0) {
        long  X = POP ();
        long  Y = POP ();
        *int a[16] = convertedecimal (X,16);
        *int b[16] = convertedecimal (Y,16);

        a = inverteArray (a,16);
        b = inverteArray (b,16);

        int i;
        int resultado[16]
        for(i=0;i<16;i++){
            if(a[i]==b[i]==1) resultado[i] = 1;
            else resultado[i] = 0;
        }

        long A = convertebinario (resultado,16);

        PUSH(A);

    }else if (strcmp(token, "|") == 0) {
        long  X = POP ();
        long  Y = POP ();
        *int a[16] = convertedecimal (X,16);
        *int b[16] = convertedecimal (Y,16);

        a = inverteArray (a,16);
        b = inverteArray (b,16);

        int i;
        int resultado[16]
        for(i=0;i<16;i++){
            if(a[i]==1 || b[i]==1) resultado[i] = 1;
            else resultado[i] = 0;
        }

        long A = convertebinario (resultado,16);

        PUSH(A);

    }else if (strcmp(token, "^") == 0) {
        long  X = POP ();
        long  Y = POP ();
        *int a[16] = convertedecimal (X,16);
        *int b[16] = convertedecimal (Y,16);

        a = inverteArray (a,16);
        b = inverteArray (b,16);

        int i;
        int resultado[16]
        for(i=0;i<16;i++){
            if(a[i] == b[i]) resultado[i] = 0;
            else resultado[i] = 1;
        }

        long A = convertebinario (resultado,16);

        PUSH(A);

        }
    }
    Print_stack();
}



