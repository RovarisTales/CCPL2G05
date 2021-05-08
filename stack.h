/**
 * @file É o ficheiro que contem a head do ficheiro stack.c.
 *
 */

// void stack (char *line); (nao existe funçao stack)

typedef struct Tipovalor Tipoval;
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
 * \brief Esta funçao verifica se a SPointer se encontra vazia.
 * @param s Pointer para a stack principal
 */

int vazio(SPointer s);

/**
 * \brief Esta funçao remove o elemento no topo da stack
 * @param s Pointer para s stack principal
 */
Tipoval POP(SPointer s);

/**
 * \brief Esta funçao adiciona o elemento colocado como argumento para o topo da stack
 * @param s Pointer para a stack principal
 * @param a Valor que queremos colocar na stack
 */
void PUSH(Tipoval a,SPointer s);

/**
 * \brief Esta funçao que imprime todos os elementos da stack
 * @param s Pointer para s stack principal
 */
void print_stack(SPointer s);

/**
 * \brief Esta funçao move o top do pointer da stack para uma posição especifica
 * @param s Pointer para s stack principal
 * @param a Posição para onde vamos deslocar.
 */
void MOVE (int a,SPointer s);

/**
 * \brief Esta função serve para retirar um elemento numa posição espefica na stack.
 * @param a Posição onde queremos retirar o elemento.
 * @param s Pointer para a stack principal
 */
Tipoval MOVEPOP (int a,SPointer s);

/**
 *\brief Como o próprio nome indica cria uma stack 
 * @param s Pointer para a stack
 * @param tamanho Tamanho da stack que queremos criar
 * return s Retorna a stack criada
 */
SPointer criaStack(SPointer s,int tamanho);

/**
 * \brief Esta função copia a stack 
 * @param x Para onde vamos colocar a copia da stack
 * @param s Pointer para a stack principal
 */
SPointer copystack(SPointer s,SPointer x);

