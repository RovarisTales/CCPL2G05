
#include <stdio.h>
int MAXSIZE = 100;
int stack[100];
int top = -1;

int vazio() {

    if(top == -1)
        return 1;
    else
        return 0;
}

 {
int cheio(){
    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}


int pop() {
    int data;

    if(!vazio()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Stack está vazia.\n");
    }
}

int push(int data) {

    if(!cheio()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("A stack esta cheia nao pode introduzir mais informaçao.\n");
    }
}
//print stack data
void printstack(int *a){
    while(!vazio()) {
        int data = pop();
        printf("%d\n",data);
        }
    }

