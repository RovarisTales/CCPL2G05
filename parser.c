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



void funnormal (char *token,Tipoval *alfabeto,SPointer s){

    if ((strstr("-+/*#%()",token) != NULL)) {
        aritimetica(token,s);
            
    }else if ((strstr("&^~|",token) != NULL)) {
        logicabin (token,s);

      }else if (strstr("_;\\@$",token) != NULL ) {
           manipstack(token,s);
        
        }else if(strstr("ifc",token) != NULL){
            convertetipo(token,s);
            
        }else if(strstr("l",token) != NULL){
            readline(token,s);
        }else if (strstr("=e&e|e<e>?!<>",token) != NULL){
            logica(token,s);
        }else if (strstr("ABCDEFGHIJKLMNOPQRSTUVWXYZ:",token) != NULL ){
            
            variaveis(token, alfabeto,s);
        }

}
void arrayounormal (char *token,Tipoval *alfabeto,SPointer s){
    Tipoval x = POPFALSO(s);
    Tipoval y = POPFALSO2(s);
    if (strcmp(token, ",") == 0){
         funarray(token,s);
    }else if (x.tipo == 'a'){
        
        funarray(token,s);

    }else {
        if (y.tipo == 'a'){
            funarray(token,s);
        }
        else {
            funnormal(token,alfabeto,s);
        }
    }


}


void parsenormal (char *token,Tipoval *alfabeto,SPointer s){
    char *sobra;
    char *sobra2;
    long valint = strtol(token, &sobra, 10);
    double valdouble = strtod(token, &sobra2);
    if (strlen(sobra) == 0){
            Tipoval X;
            X.valor = valint;
            X.tipo = 'i';
            X.array = NULL;
            PUSH(X,s);
        }else if (strlen(sobra2) == 0) {
            Tipoval X;
            X.valor = valdouble;
            X.tipo = 'f';
            X.array = NULL;
            PUSH(X,s);
    }else if (strstr("~+()<>*,=", token) != NULL){
        arrayounormal(token,alfabeto,s);
        
    
    }else if (strstr("le&e|e<e>?!ABCDEFGHIJKLMNOPQRSTUVWXYZifc_;\\@$&^~|-+/*#%()",token) != NULL){
        
        funnormal(token,alfabeto,s);
    }else if (strncmp(token, ":",1) == 0){
        variaveis(token,alfabeto,s);
    }
}

void parsearray (char *token,char **resto, char *demilit,Tipoval *alfabeto,SPointer mini){

        
        for (token = strtok_r(*resto, demilit,resto); strcmp(token,"]") != 0;token = __strtok_r(NULL,demilit,resto) ){
            
            char *sobra;
            char *sobra2;
            long valint = strtol(token, &sobra, 10);
            double valdouble = strtod(token, &sobra2);
            
                 if (strlen(sobra) == 0){
                    Tipoval X;
                    X.valor = valint;
                    X.tipo = 'i';
                    X.array = NULL;
                    PUSH(X,mini);
                    
                }else if (strlen(sobra2) == 0) {
                    Tipoval X;
                    X.valor = valdouble;
                    X.tipo = 'f';
                    X.array = NULL;
                    PUSH(X,mini);
                    
                }else if(strcmp("[",token)== 0) {
                
                    struct Stack s2;
                    SPointer new = &s2;
                    new = criaStack(new,1024);
                    Tipoval Y;
                    Y.valor = 0;
                    Y.tipo = 'a';
                    Y.array = new;
                    PUSH(Y,mini);
                    parsearray(token,resto,demilit,alfabeto,new);
                    
                }
                else{ parsenormal (token,alfabeto,mini);
                
                }
        }
        
            
           

}











/*
void swapM (int *x, int *y){
    int t = *x; 
    *x = *y; 
    *y = t; 
}struct StackG s1;
    SPointer s = &s1;

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
    struct Stack s1;
    SPointer s = &s1;
    
    s = criaStack(s,10240);
    Tipoval alfabeto[26] = {
        {10,'i',NULL},
        {11,'i',NULL},
        {12,'i',NULL},
        {13,'i',NULL},
        {14,'i',NULL},
        {15,'i',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {10,'c',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {0,'i',NULL}, 
        {0,'i',NULL},
        {32,'c',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {0,'i',NULL},
        {1,'i',NULL},
        {2,'i',NULL},
            };
    char *resto;
    char delimit[8] = " \n\t";
    char *token;
    for(token = strtok_r(line, delimit,&resto); token != NULL;token = __strtok_r(NULL,delimit,&resto) ){
        printf("token : %s\n", token);
        if (strstr("\"[",token) != NULL){
            
            
            struct Stack s2;
            SPointer mini = &s2;
            mini = criaStack(mini,1024);
            Tipoval Y;
            Y.valor = 0;
            Y.tipo = 'a';
            Y.array = mini;
            PUSH(Y,s);
            parsearray(token,&resto,delimit,alfabeto,mini);
            
            
        }

        else {
            parsenormal(token,alfabeto,s);
        }
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
    printf("sai ciclo\n");
    print_stack(s);
    putchar('\n');
}



