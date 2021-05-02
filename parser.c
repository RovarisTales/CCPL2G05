/**
 * @file É o ficheiro que contém a função parser, que separa o input em tokens e realiza as operaçoes baseado na stack.
 *Neste ficheiro também esta a ser usado o ficheiro stack.h e os ficheiros auxiliares das funções com as operações previamente mencionadas.
 *(aritimetica.h , logicabin.h , manipstack.h , logica.h , convertetipo.h , readline.h , variaveis.h)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "stack.h"
#include "aritimetica.h"
#include "logicabin.h"
#include "manipstack.h"
#include "logica.h"
#include "convertetipo.h"
#include "readline.h"
#include "variaveis.h"
#include "array.h"

/**
 * \brief Compara tipos
 * @param a Tipo da primeira variavel
 * @param b Tipo da segunda variavel
 * @return Retorna o proprio tipo se forem iguais,se um deles for float retorna em float e se forem diferentes retorna em long
 */
/*
int charcomparar (char a, char *string){
    while (*string != '\0'){
        if (a == *string) return 1;
        else string++;
    }
    return 0;

}
char *gettoken (char *line , char **resto){

    int i = 0;
    char *token;
    while (charcomparar(line[i]," \n\t") != 0){
        token[i] = line[i];
        i++;
    }
    while(charcomparar(line[i]," \n\t") == 0){
        i++;
    }
    *resto = &line[i];
    return token;

}*/
char comparatipo (char a, char b){

    if (a == b) return a;
    else if (a == 'f' || b == 'f') return 'f';
    else return 'l';

}
int comparatipo2(char a, char b){
    if (a == 'F' || b == 'F') return 0; // 0 para array ou string
    else return 1; // 1 para normal

}
/**
 * \brief Como o proprio nome converte a variavel para long.
 * @param x Variavel que queremos converter
 * @param a Tipo de x
 * @return Retorna o valor introduzido no tipo long
 */

double convertelong (double x, char a){
    long l;
    if (a == 'l') {
        l = x;
        x = l;
    }else if (a == 'i') {
        l = x;
        x = l;
    }
    
    return x;
}
void funnormal (char *token,Tipoval *alfabeto){

    if ((strstr("-+/*#%()",token) != NULL)) {
        aritimetica(token);
            
    }else if ((strstr("&^~|",token) != NULL)) {
        logicabin (token);

      }else if (strstr("_;\\@$",token) != NULL ) {
           manipstack(token);
        
        }else if(strstr("ifc",token) != NULL){
            convertetipo(token);
            
        }else if(strstr("l",token) != NULL){
            readline(token);
        }else if (strstr("=e&e|e<e>?!<>",token) != NULL){
            logica(token);
        }else if (strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZ:",token) != NULL ){
            variaveis(token, alfabeto);
        }

}


void parsenormal (char *token,Tipoval *alfabeto){
    char *sobra;
    char *sobra2;
    long valint = strtol(token, &sobra, 10);
    double valdouble = strtod(token, &sobra2);
    if (strlen(sobra) == 0){
            Tipoval X;
            X.valor = valint;
            X.tipo = 'i';
            X.tipo2 = 'n';
            PUSH(X);
        }else if (strlen(sobra2) == 0) {
            Tipoval X;
            X.valor = valdouble;
            X.tipo = 'f';
            X.tipo2 = 'n';
            PUSH(X);
    } else if ((strstr("+*()#_=<>~/",token) != NULL)){
        Tipoval X , Y;
        X = POP();
        Y = POP();
        int a = comparatipo2(X.tipo2,Y.tipo2);
        PUSH (Y);
        PUSH(X);
        if (a) funnormal(token,alfabeto);
        else funarray(token);
    }
}

void parsearray (char *token,char **resto, char *demilit,Tipoval *alfabeto){
        Tipoval X;
        X.valor = 0;
        X.tipo = 'i';
        X.tipo2 = 'I';
        PUSH(X);
        for (token = strtok_r(*resto, demilit,resto); ((strcmp(token,"]") != 0) && (strcmp(token,"[") != 0));token = __strtok_r(NULL,demilit,resto) ){
            char *sobra;
            char *sobra2;
            long valint = strtol(token, &sobra, 10);
            double valdouble = strtod(token, &sobra2);
            
                 if (strlen(sobra) == 0){
                    Tipoval X;
                    X.valor = valint;
                    X.tipo = 'i';
                    X.tipo2 = 'a';
                    PUSH(X);
                    
                }else if (strlen(sobra2) == 0) {
                    Tipoval X;
                    X.valor = valdouble;
                    X.tipo = 'f';
                    X.tipo2 = 'a';
                    PUSH(X);
                    
                }
                else parsenormal (token,alfabeto);
                




                }
            if (strncmp(token,"]",1) == 0){
                Tipoval X;
                X.valor = 0;
                X.tipo = 'i';
                X.tipo2 = 'F';
                PUSH(X);
                
            }
            else if(strcmp("[",token)== 0) {
                printf("novo array \n");
                parsearray(token,resto,demilit,alfabeto);
                
                }

    
}











/*
void swapM (int *x, int *y){
    int t = *x; 
    *x = *y; 
    *y = t; 
}

void swap (int v[], int i, int j){
    swapM(v+i,v+j);
}

void inverteArray (int v[], int N){
    int i,j;
    j = N-1;
    i=0;
    while(i<j){
        swap(v,i,j);
        i++;
        j--;
    }
}

int convertedecimal(int a[]){
int i;
long x=0;

for(i=0;i<16;i++){
 if (a[i]==1){x=x+pow(2,i);}
}
return x;
}
void convertebinario(long x, int a[]){
    int i;
    for(i=0;x>0;i++){
    a[i]=x%2;
    x=x/2;
    }
}
*/
/**
 * \brief Realiza as operações utilizando as funçoes da stack.
 *
 * Estas operações dependem do caracter introduzido.
 *
 * @param line A linha que foi lida na main para realizar o parser.
 */
void parser (char *line){

    Tipoval alfabeto[26] = {
        {10,'i','n'},
        {11,'i','n'},
        {12,'i','n'},
        {13,'i','n'},
        {14,'i','n'},
        {15,'i','n'},
        {0,'i','n'},
        {0,'i','n'},
        {0,'i','n'},
        {0,'i','n'},
        {0,'i','n'},
        {0,'i','n'},
        {0,'i','n'},
        {10,'c','n'},
        {0,'i','n'},
        {0,'i','n'},
        {0,'i','n'}, 
        {0,'i','n'},
        {32,'c','n'},
        {0,'i','n'},
        {0,'i','n'},
        {0,'i','n'},
        {0,'i','n'},
        {0,'i','n'},
        {1,'i','n'},
        {2,'i','n'},
            };
    char *resto;
    char delimit[8] = " \n\t";
    char *token;
    for(token = strtok_r(line, delimit,&resto); token != NULL;token = __strtok_r(NULL,delimit,&resto) ){
        if (strstr("\"[",token) != NULL){
            
            parsearray(token,&resto,delimit,alfabeto);
            
        }else if (strncmp(token,"]",1) == 0){
                Tipoval X;
                X.valor = 0;
                X.tipo = 'i';
                X.tipo2 = 'F';
                PUSH(X);
            }

        else parsenormal(token,alfabeto);

       /* if (strlen(sobra) == 0){
            Tipoval X;
            X.valor = valint;
            X.tipo = 'i';
            PUSH(X);
        }else if (strlen(sobra2) == 0) {
            Tipoval X;
            X.valor = valdouble;
            X.tipo = 'f';
            PUSH(X);
    } else if (strstr("-+#%()",token) != NULL) {
        aritimetica(token);
        

            
            
    }else if (strstr("&^~|",token) != NULL) {
        logicabin (token);

      }else if (strstr("_;\\@$",token) != NULL) {
           manipstack(token);
        
        }else if(strstr("ifc",token) != NULL){
            convertetipo(token);
            
        }else if(strstr("l",token) != NULL){
            readline(token);
        }else if (strstr("=e&e|e<e>?!<>",token) != NULL){
            logica(token);
        }else if (strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZ",token) != NULL ){
            variaveis(token, alfabeto);
        }else if (strncmp(token,":",1) == 0){
            variaveis(token, alfabeto);
        }*/
    }
    print_stack();
}



