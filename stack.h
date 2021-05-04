/**
 * @file É o ficheiro que contem a head do ficheiro stack.c.
 *
 */

// void stack (char *line); (nao existe funçao stack)
#define Max 10240
typedef struct StackT Tipoval;
typedef struct StackG *SPointer;
struct StackT{
    double valor;
    char tipo ;
    SPointer array;
};
struct StackG{
    Tipoval stack[Max];
    int top;
};

int vazio(SPointer s);
int cheio(SPointer s);
Tipoval POP(SPointer s);
void PUSH(Tipoval a,SPointer s);
void print_stack(SPointer s);
void MOVE (int a,SPointer s);
Tipoval MOVEPOP (int a,SPointer s);
SPointer criaStack();
void PUSHARRAY (Tipoval a, SPointer s, SPointer mini);

