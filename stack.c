#include <stdio.h>
int MAXSIZE = 10240;
int stack[10240];
int top = -1;

int vazio() {

    if(top == -1)
        return 1;
    else
        return 0;
}


int cheio(){
    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}


int POP() {
    int data;

    if(!vazio()) {
        data = stack[top];
        top = top - 1;
        return data;
    }
}

int PUSH(int data) {

    if(!cheio()) {
        top = top + 1;
        stack[top] = data;
    }
}

void print_stack(int stack ){
    while(!vazio()) {
        int data;
        data = POP();
        printf("%d ", data);
        }putchar('\n');
    }

