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
    int data;
    int i=0;
    int stacks[10240];
    while(!vazio()) {
        data = POP();

        stacks[i] = data;
        i++;

        }
    for (i=i-1;i>-1;i--) {
        printf("%d ", stacks[i]);
    }
    putchar('\n');
}
