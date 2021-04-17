#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"
void variaveis(char *token){
    int A = 10;
    int B = 11;
    int C = 12;
    int D = 13;
    int E = 14;
    int F = 15;
    char N = '\n';
    char S = ' ';
    int X = 0;
    int Y = 1;
    int Z = 2;
    if (strncmp(token, "A",1) == 0) {
        PUSH (A,'i');
    }else if (strncmp(token, "B",1) == 0) {
        PUSH(B,'l');
    }else if (strncmp(token, "C",1) == 0) {
        PUSH(C,'l');
    }else if (strncmp(token, "D",1) == 0) {               //:ABCDEFNSXYZ
        PUSH(D,'l');
    }else if (strncmp(token, "E",1) == 0) {
        PUSH(E,'l');
    }else if (strncmp(token, "F",1) == 0) {
        PUSH(F,'l');
    }else if (strncmp(token, "N",1) == 0) {
        PUSH(N,'c');
    }else if (strncmp(token, "S",1) == 0) {
        PUSH(S,'c');
    }else if (strncmp(token, "X",1) == 0) {
        PUSH(X,'l');
    }else if (strncmp(token, "Y",1) == 0) {
        PUSH(Y,'l');
    }else if (strncmp(token, "Z",1) == 0) {
        PUSH(Z,'l');
        }
}
