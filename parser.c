#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.h"

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
        }
    }
}



