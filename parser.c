/**
 * @file É o ficheiro que contém a função parser, que separa o input em tokens e realiza as operaçoes baseado na stack.
 *Neste ficheiro também esta a ser usado o ficheiro stack.h.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "parser.h"
#include "stack.h"

char comparatipo (char a, char b){

    if (a == b) return a;
    else if (a == 'f' || b == 'f') return 'f';
    else return 'l';

}

void aritimetica (char *oper){
    if (strcmp(oper, "-") == 0) {
        char A = POPT();
        double  Y = POP ();
        char B = POPT();
        double  X = POP ();
        A = comparatipo (A,B);
        PUSH (X - Y,A);
    } else if (strncmp(oper, "+",1) == 0) {
        char A = POPT();
        double  Y = POP ();
        char B = POPT();
        double  X = POP ();
        A = comparatipo (A,B);
        PUSH (X + Y,A);
    } else if (strncmp(oper, "*", 1) == 0) {
        char A = POPT();
        double  Y = POP ();
        char B = POPT();
        double  X = POP ();
        double a = X*Y;
        A = comparatipo (A,B);
        PUSH (a,A);
    } else if (strncmp(oper, "/",1) == 0) {
        char A = POPT();
        double  Y = POP ();
        char B = POPT();
        double  X = POP ();
        if (A == 'i' && B == 'i') {
            long a = Y;
            long b = X;
            PUSH(b / a,'i');
        }
        else if (A == B) PUSH (X / Y,A);
        else PUSH (X / Y,'f');
    } else if (strncmp(oper, "#",1) == 0) {
        double  Y = POP ();
        double  X = POP ();
        PUSH (pow (X,Y),'f');
    } else if (strncmp(oper, "%",1) == 0) {
        long  Y = POP ();
        long  X = POP ();
        
        PUSH (X % Y,'i');
    } else if (strncmp(oper, "(",1) == 0) {
        char A = POPT();
        double  X = POP ();
        X = X - 1;
        PUSH (X,A);
    } else if (strncmp(oper, ")",1) == 0) {
        char A = POPT();
        double  X = POP ();
        X = X + 1;
        PUSH (X,A);
    }


}

void logica (char *token){
    if (strncmp(token, "&",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        long A = X & Y;
        PUSH(A,'l');

    }else if (strncmp(token, "|",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        long A = X | Y;

        PUSH(A,'l');

    }else if (strncmp(token, "^",1) == 0) {
        long  X = POP ();
        long  Y = POP ();
        long A = X ^ Y;

        PUSH(A,'l');

       }else if (strncmp(token, "~",1) == 0) {
        long  X = POP ();
        long A = ~X;

        PUSH(A,'l');
       }
}

void manipstack (char *token){
    if (strncmp(token, "_",1) == 0) {
        char A = POPT();
        double  Y = POP ();
        PUSH (Y,A);
        PUSH (Y,A);
        
    }else if (strncmp(token, ";",1) == 0) {
        double  X = POP ();
        X++;

    }else if (strcmp(token, "\\") == 0) {
        char A = POPT();
        double  X = POP ();
        char B = POPT();
        double  Y = POP ();
        
        PUSH (X,A);
        PUSH (Y,B);

    }else if (strncmp(token, "@",1) == 0) {
        
        char A = POPT();
        double  X = POP ();
        char B = POPT();
        double  Y = POP ();
        char C = POPT();
        double  Z = POP (); 
        PUSH (Y,B);
        PUSH (X,A);
        PUSH (Z,C);
    }else if(strncmp(token, "$",1) == 0){
            double x = POP();
            int a = MOVEPOP(x);
            char b = POPT();
            PUSH(a,b);
            MOVE(x);
            PUSH(a,b);
    }
}

void convertetipo (char *token){
    if(strncmp(token, "i",1) == 0){
            
            double x = POP();
            
            PUSH(x,'i');

    }else if(strncmp(token, "f",1) == 0){
           
            float x = POP();
            
            PUSH(x,'f');

    }else if(strncmp(token, "c",1) == 0){
            long x = POP();

            PUSH(x,'c');
            
    }
}

void readline (char *token){
    if(strncmp(token, "l",1) == 0){
        char lerlinha [10240];
        char *oi;
        assert(fgets(lerlinha,10240,stdin)!=NULL);
        assert(lerlinha[strlen(lerlinha)- 1]== '\n');
        double a = strtod(lerlinha,&oi);
        PUSH(a,'f');
    }
}
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
        char *sobra2;
        long valint = strtol(token, &sobra, 10);
        double valdouble = strtod(token, &sobra2);
        // char *tokencmp;
        if (strlen(sobra) == 0){
            PUSH(valint,'i');
        }else if (strlen(sobra2) == 0) {
            
            PUSH(valdouble,'f');
    } else if (strstr("-+/*#%()",token) != NULL) {
        aritimetica(token);
        
/*  }else if (strncmp(token, "&",1) == 0) {
        double  X = POP ();
        double  Y = POP ();
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
        double A = convertedecimal (resultado);
        PUSH(A);

    }else if (strncmp(token, "|",1) == 0) {
        double  X = POP ();
        double  Y = POP ();
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
        double A = convertedecimal (resultado);

        PUSH(A);

    }else if (strncmp(token, "^",1) == 0) {
        double  X = POP ();
        double  Y = POP ();
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
        double A = convertedecimal (resultado);
        PUSH(A);

       }else if (strncmp(token, "~",1) == 0) {
        double  X = POP ();
        X = -X -1;
        PUSH(X);}*/
            
            
    }else if (strstr("&^~|",token) != NULL) {
        logica (token);

      }else if (strstr("_;\\@$",token) != NULL) {
           manipstack(token);
        
        }else if(strstr("ifc",token) != NULL){
            convertetipo(token);
            
        }else if(strstr("l",token) != NULL){
            readline(token);
        }
    }
    print_stack();
}



