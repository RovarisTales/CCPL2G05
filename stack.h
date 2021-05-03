/**
 * @file É o ficheiro que contem a head do ficheiro stack.c.
 *
 */

// void stack (char *line); (nao existe funçao stack)
#define Max 10240
struct StackT{
    double valor;
    char tipo ;
    char tipo2;

};
typedef struct StackT Tipoval;
struct StackG{
    Tipoval stack[Max];
    int top;
};
typedef struct StackG *SPointer;
int vazio(SPointer s);
int cheio(SPointer s);
Tipoval POP(SPointer s);
void PUSH(Tipoval a,SPointer s);
void print_stack(SPointer s);
void MOVE (int a,SPointer s);
Tipoval MOVEPOP (int a,SPointer s);
SPointer criaStack();

