#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"
#include "stack.h"

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

void parser (char *line){
    char *delimit = " /n/t";
    
    for(char *token = strtok(line, delimit);token != NULL; token = strtok(NULL, delimit)){
        char *sobra;
        long valint = strtol(token, &sobra, 10);
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
        int a[16]={0};
        convertebinario (X, a);
        int b[16]={0};
        convertebinario (Y, b);
        int i;
        int resultado[16]={0};
        for(i=0;i<16;i++){
            if(a[i]==1 && b[i]==1) resultado[i] = 1;
            else resultado[i] = 0;
        }

        long A = convertedecimal (resultado);

        PUSH(A);

    }else if (strcmp(token, "|") == 0) {
        long  X = POP ();
        long  Y = POP ();
        int a[16]={0};
        convertebinario (X, a);
        int b[16]={0};
        convertebinario (Y, b);
        int i;
        int resultado[16]={0};
        for(i=0;i<16;i++){
            if(a[i]==1 || b[i]==1) resultado[i] = 1;
            else resultado[i] = 0;
        }

        long A = convertedecimal (resultado);

        PUSH(A);

    }else if (strcmp(token, "^") == 0) {
        long  X = POP ();
        long  Y = POP ();
        int a[16]={0};
        convertebinario (X, a);
        int b[16]={0};
        convertebinario (Y, b);
        int i;
        int resultado[16]={0};
        for(i=0;i<16;i++){
            if(a[i] != b[i]) resultado[i] = 1;
            else resultado[i] = 0;
        }

        long A = convertedecimal (resultado);

        PUSH(A);

       }
    }
    print_stack();
}



