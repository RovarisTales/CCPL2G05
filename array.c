
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"


// int search (char *main, char *procura){
//     int g,h;
//     while (main[g] != '\0'){
//         if(main[g] == procura[h]){
//         g++;
//         h++;
//     }
//     
// 
// 
// 
// 
//     }
// }



void bruhnormal(Tipoval X){
    Tipoval y;
    y.valor = 0;
    y.tipo = 'i';
    y.tipo2 = 'I';
    for(int t=0;t!=X.valor;t++){
    y.tipo='i';
    y.tipo2='a';
    y.valor=t;
            PUSH(y);}
    y.valor = 0;
    y.tipo = 'i';
    y.tipo2 = 'F';
}
void bruharray(){
    Tipoval r = POP();
    int b;
    for(b=0;r.tipo2!='F';b++){r=POP();}
    Tipoval y;
    y.tipo='i';
    y.tipo2='n';
    y.valor=b;
        PUSH(y);
}
void bruh (char *token){
    if(strncmp(token, ",",1) == 0){
        Tipoval X = POP();
        if (X.tipo2 == 'I'){bruharray();}
        if (X.tipo2 == 'n'){bruhnormal(X);}
        }
    }


void nope (char *token){
    if(strncmp(token, "~",1) == 0){
        Tipoval X = POP();
        Tipoval guardar[50];
        int i;
        while(X.tipo2 != 'I'){
            i=0;
            X = POP();
            guardar[i] = X;
            i++;
        }
        while(i>-1){
         PUSH (guardar[i]);
         i--;
        }
    }





}

void concatarray (){
    Tipoval a[100]= {{0}};
    int b;
    for(b=1;a[b].tipo2!='I';b++){
        a[b]=POP();}

    Tipoval y = POP();

    for(;b!=1;b--){
        PUSH(a[b]);}
    
    y.tipo='i';
    y.tipo2='F';
    y.valor='0';
    PUSH(y);
}
void concatnum (Tipoval r){
    Tipoval y = POP();
    PUSH(r);

    y.tipo='i';
    y.tipo2='F';
    y.valor='0';
    PUSH(y);
}
void concat(){
        Tipoval X = POP();
        if (X.tipo2 == 'F'){concatarray();}
        if (X.tipo2 == 'n'){concatnum(X);}
}
    
void inicioarray(Tipoval X,Tipoval r){
    Tipoval a[100]= {{0}};
    int b;
    a[0]=X;
    for(b=1;a[b].tipo2!='I';b++){
        a[b]=POP();}
    int xpto=b;
    for(;b!=xpto-r.valor;b--){
        PUSH(a[b]);}
}

void fimarray(Tipoval X,Tipoval r){
    Tipoval a[100]= {{0}};
    int b;
    a[0]=X;
    for(b=1;b!=r.valor+1;b++){
        a[b]=POP();}
    for(;a[b].tipo2!='F';b--){
        PUSH(a[b]);}
}
void inifim(char *token){
    Tipoval Y = POP();
    Tipoval X = POP();
    if (strncmp(token, "<",1) == 0) inicioarray(X,Y);
    else fimarray(X,Y);

}
void igual (char *token){
    if(strncmp(token, "=",1) == 0){
        Tipoval X = POP();
        Tipoval Y = POP();
        while (X.valor != 0){
            Y = POP();
            X.valor--;
        }
        X.valor = Y.valor;
        X.tipo = Y.tipo;
        while(Y.tipo != 'I'){
            Y = POP();
        }
    }
    else if(strncmp(token, "*",1) == 0){
    Tipoval r = POP();
    Tipoval X = POP();
    Tipoval a[100] = {{0}};
    int b;
    a[0]=X;
    
    for(b=1;a[b].tipo2!='I';b++){
        a[b]=POP();}
    int xpto = b;
    for(int c=0;c!=r.valor;c++){
    for(b = xpto;a[b].tipo2!='F';b--){
        PUSH(a[b]);}
        }
    }
}
void tira (char *token){
    if(strncmp(token, ")",1) == 0){
        Tipoval X = POP();
        X.tipo2 = 'n';
        PUSH(X);
    }

    if(strncmp(token, "(",1) == 0){
        Tipoval Y = POP();
        Tipoval banana[50] = {{(0)}};
        int i=0;
        
        
        while(Y.tipo2 != 'I'){
            Y = POP();
            banana[i] = Y;
            i++;
        }
        
        int a = i;
        a++;
        a--;
        i--;
        while (i>-1){
            PUSH(banana[i]);
        }
        Tipoval X = banana[a];
        X.tipo2 = 'n';
        PUSH(X);
    }

}



void multiarray(){
    Tipoval a[100] = {{0}};
    Tipoval r = POP();
    Tipoval X = POP();
    int b;
    a[0]=X;
    
    for(b=1;a[b].tipo2!='I';b++){
        a[b]=POP();}
    int xpto = b;
    for(int c=0;c!=r.valor;c++){
    for(b = xpto;a[b].tipo2!='F';b--){
        PUSH(a[b]);}
        }
}

//void hashtag (char *token){
//    if(strncmp(token, "(",1) == 0){
//    char main[100];
//    char procura[10];
//    int i;
//    Tipoval Y = POP();if(strncmp(token, ",",1) == 0)
//    Y = POP();
//    Y = POP();
//    i = 0;
//    while(Y.tipo2 != 'I'){
//    main[i] = Y.valor;
//    i++;
//    }
//    int g,h;
//    for(g=0,main[g]!= '\0', g++)
//    
//
//    }
//
//
//
//
//
//
//
//}


void funarray (char *token){

    if(strcmp(token,"()")) tira (token);
    else if(strcmp(token,"=*") ) igual (token);
    else if (strncmp(token, ",",1) == 0) bruh(token);
    else if (strncmp(token, "+",1) == 0) concat();
    else if (strncmp(token, "<>",1) == 0) inifim(token);






}














