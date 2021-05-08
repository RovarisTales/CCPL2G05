/**
 * @file É o ficheiro que contem a head do ficheiro stack.c.
 *
 */

// void stack (char *line); (nao existe funçao stack)

typedef struct Tipovalor Tipoval;
typedef struct Stack *SPointer;

struct Tipovalor{
    double valor;
    char tipo ;
    SPointer array;
};
struct Stack{
    Tipoval *stack;
    int top;
};

int vazio(SPointer s);
int cheio(SPointer s);
Tipoval POP(SPointer s);
void PUSH(Tipoval a,SPointer s);
void print_stack(SPointer s);
void MOVE (int a,SPointer s);
Tipoval MOVEPOP (int a,SPointer s);
SPointer criaStack(SPointer s,int tamanho);
void PUSHARRAY (Tipoval a, SPointer s);
Tipoval POPFALSO(SPointer s);
Tipoval POPFALSO2(SPointer s);
SPointer copystack(SPointer s,SPointer x);

