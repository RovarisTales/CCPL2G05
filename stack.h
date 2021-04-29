/**
 * @file É o ficheiro que contem a head do ficheiro stack.c.
 *
 */
// void stack (char *line); (nao existe funçao stack)
struct StackT{
    double valor;
    char tipo ;

};
typedef struct StackT Tipoval;
int vazio();
int cheio();
Tipoval POP();
void PUSH(Tipoval a);
void print_stack();
void MOVE (int a);
Tipoval MOVEPOP (int a);
char POPT();

