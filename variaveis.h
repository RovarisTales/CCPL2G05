/**
 * @file É o ficheiro que contem a head do ficheiro variaveis.c
 *
 */

/**
 * \brief Função que vai reencaminhar para as suas subfunções (variaveisA (com :) e variaveisB(sem :))
 * @param token dentro dos mencionados no parser (":ABCDEFGHIJKLMNOPQRSTUVWXYZ")
 * @param alfabeto Letra do alfabeto em maiuscula que corresponde ao codigo ascii (65-90)
 * @param s Pointer para a stack
 */
void variaveis(char *token, Tipoval *alfabeto,SPointer s);
