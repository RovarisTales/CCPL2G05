
int MAXSIZE = 10240;
int stack[10240];
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
    }
}

int push(int data) {

    if(!cheio()) {
        top = top + 1;
        stack[top] = data;
    }
}

void printstack(int *a){
    while(!vazio()) {
        int data = pop();
        }
    }

