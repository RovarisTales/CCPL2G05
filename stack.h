/**
 * @file É o ficheiro que contem a head do ficheiro stack.c.
 *
 */

// void stack (char *line); (nao existe funçao stack)

/**
 * \brief Estamos a definir uma struct para o Tipoval
 */
typedef struct Tipovalor Tipoval;

/**
 * \brief Estamos a definir um pointer para a stack
 */
typedef struct Stack *SPointer;

/**
 * \brief Estamos a definir um novo tipo (tipoValor) que como o nome indica tem um char (tipo) e um valor (double) relacionado.
 */

struct Tipovalor{
    double valor;
    char tipo ;
    SPointer array;
};

/**
 * \brief Estamos a definir uma struct stack com um top (topo da stack) e um pointer stack
 */

struct Stack{
    Tipoval *stack;
    int top;
};

/**
 * \brief Head da função vazio que se encontra em stack.c
 * @param s Pointer para a stack principal
 */

int vazio(SPointer s);

/**
 * \brief Head da função POP que se encontra em stack.c
 * @param s Pointer para s stack principal
 */
Tipoval POP(SPointer s);

/**
 * \brief Head da função PUSH que se encontra em stack.c
 * @param s Pointer para a stack principal
 * @param a Valor que queremos colocar na stack
 */
void PUSH(Tipoval a,SPointer s);

/**
 * \brief Head da função print_stack que se encontra em stack.c
 * @param s Pointer para s stack principal
 */
void print_stack(SPointer s);

/**
 * \brief Head da função MOVE que se encontra em stack.c
 * @param s Pointer para s stack principal
 * @param a Posição para onde vamos deslocar.
 */
void MOVE (int a,SPointer s);

/**
 * \brief Head da função MOVEPOP que se encontra em stack.c
 * @param a Posição onde queremos retirar o elemento.
 * @param s Pointer para a stack principal
 */
Tipoval MOVEPOP (int a,SPointer s);

/**
 *\brief Head da função criaStack que se encontra em stack.c
 * @param s Pointer para a stack
 * @param tamanho Tamanho da stack que queremos criar
 */
SPointer criaStack(SPointer s,int tamanho);

/**
 * \brief Head da função copystack que se encontra em stack.c
 * @param x Para onde vamos colocar a copia da stack
 * @param s Pointer para a stack principal
 */
SPointer copystack(SPointer s,SPointer x);

