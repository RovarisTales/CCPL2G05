/**
 * @file É o ficheiro que contem a head do ficheiro parser.c
 *
 */

/**
 * \brief Estamos a definir um pointer para a stack
 */
typedef struct Stack *SPointer;

/**
 * \brief Estamos a definir uma struct para o Tipoval
 */
typedef struct Tipovalor Tipoval;
/**
 * \brief Head do comparatipo que se encontra no parser.c
 * @param a Tipo da primeira variavel
 * @param b Tipo da segunda variavel
 */
char comparatipo (char a, char b);

/**
 * \brief Head do convertlong que se encontra no parser.c
 * @param x Variavel que queremos converter
 * @param a Tipo de x
 */
double convertelong (double x, char a);

/**
 * \brief Head do parser que se encontra no parser.c
 * @param line A linha que foi lida na main para realizar o parser.
 * @param alfabeto Alfabeto em maiuscula que corresponde ao codigo ascii (65-90)
 */
SPointer parser (char *line, Tipoval *alfabeto);


/* void convertebinario(long x, int a[]);

int convertedecimal(int a[]);

void swapM (int *x, int *y);

void swap (int v[], int i, int j);

void inverteArray (int v[], int N);*/







