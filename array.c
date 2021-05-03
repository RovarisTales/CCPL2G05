
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



void bruhnormal(Tipoval X, SPointer s){
    Tipoval y;
    y.valor = 0;
    y.tipo = 'i';
    y.tipo2 = 'I';
    for(int t=0;t!=X.valor;t++){
    y.tipo='i';
    y.tipo2='a';
    y.valor=t;
            PUSH(y,s);}
    y.valor = 0;
    y.tipo = 'i';
    y.tipo2 = 'F';
}
void bruharray(SPointer s){
    Tipoval r = POP(s);
    int b;
    for(b=0;r.tipo2!='F';b++){r=POP(s);}
    Tipoval y;
    y.tipo='i';
    y.tipo2='n';
    y.valor=b;
        PUSH(y,s);
}
void bruh (char *token, SPointer s){
    if(strncmp(token, ",",1) == 0){
        Tipoval X = POP(s);
        if (X.tipo2 == 'I'){bruharray(s);}
        if (X.tipo2 == 'n'){bruhnormal(X,s);}
        }
    }


void nope (char *token,SPointer s ){
    if(strncmp(token, "~",1) == 0){
        Tipoval X = POP(s);
        Tipoval guardar[50];
        int i;
        while(X.tipo2 != 'I'){
            i=0;
            X = POP(s);
            guardar[i] = X;
            i++;
        }
        while(i>-1){
         PUSH (guardar[i],s);
         i--;
        }
    }





}

void concatarray (SPointer s){
    Tipoval a[100]= {{0}};
    int b;
    for(b=1;a[b].tipo2!='I';b++){
        a[b]=POP(s);}

    Tipoval y = POP(s);

    for(;b!=1;b--){
        PUSH(a[b],s);}
    
    y.tipo='i';
    y.tipo2='F';
    y.valor='0';
    PUSH(y,s);
}
void concatnum (Tipoval r,SPointer s){
    Tipoval y = POP(s);
    PUSH(r,s);

    y.tipo='i';
    y.tipo2='F';
    y.valor='0';
    PUSH(y,s);
}
void concat(SPointer s){
        Tipoval X = POP(s);
        if (X.tipo2 == 'F'){concatarray(s);}
        if (X.tipo2 == 'n'){concatnum(X,s);}
}
    
void inicioarray(Tipoval X,Tipoval r, SPointer s){
    Tipoval a[100]= {{0}};
    int b;
    a[0]=X;
    for(b=1;a[b].tipo2!='I';b++){
        a[b]=POP(s);}
    int xpto=b;
    for(;b!=xpto-r.valor;b--){
        PUSH(a[b],s);}
}

void fimarray(Tipoval X,Tipoval r,SPointer s){
    Tipoval a[100]= {{0}};
    int b;
    a[0]=X;
    for(b=1;b!=r.valor+1;b++){
        a[b]=POP(s);}
    for(;a[b].tipo2!='F';b--){
        PUSH(a[b],s);}
}
void inifim(char *token, SPointer s){
    Tipoval Y = POP(s);
    Tipoval X = POP(s);
    if (strncmp(token, "<",1) == 0) inicioarray(X,Y,s);
    else fimarray(X,Y,s);

}
void igual (char *token, SPointer s){
    if(strncmp(token, "=",1) == 0){
        Tipoval X = POP(s);
        Tipoval Y = POP(s);
        while (X.valor != 0){
            Y = POP(s);
            X.valor--;
        }
        X.valor = Y.valor;
        X.tipo = Y.tipo;
        while(Y.tipo != 'I'){
            Y = POP(s);
        }
    }
    else if(strncmp(token, "*",1) == 0){
    Tipoval r = POP(s);
    Tipoval X = POP(s);
    Tipoval a[100] = {{0}};
    int b;
    a[0]=X;
    
    for(b=1;a[b].tipo2!='I';b++){
        a[b]=POP(s);}
    int xpto = b;
    for(int c=0;c!=r.valor;c++){
    for(b = xpto;a[b].tipo2!='F';b--){
        PUSH(a[b],s);}
        }
    }
}
void tira (char *token, SPointer s){
    if(strncmp(token, ")",1) == 0){
        Tipoval X = POP(s);
        X.tipo2 = 'n';
        PUSH(X,s);
    }

    if(strncmp(token, "(",1) == 0){
        Tipoval Y = POP(s);
        Tipoval banana[50] = {{(0)}};
        int i=0;
        
        
        while(Y.tipo2 != 'I'){
            Y = POP(s);
            banana[i] = Y;
            i++;
        }
        
        int a = i;
        a++;
        a--;
        i--;
        while (i>-1){
            PUSH(banana[i],s);
        }
        Tipoval X = banana[a];
        X.tipo2 = 'n';
        PUSH(X,s);
    }

}



void multiarray(SPointer s){
    Tipoval a[100] = {{0}};
    Tipoval r = POP(s);
    Tipoval X = POP(s);
    int b;
    a[0]=X;
    
    for(b=1;a[b].tipo2!='I';b++){
        a[b]=POP(s);}
    int xpto = b;
    for(int c=0;c!=r.valor;c++){
    for(b = xpto;a[b].tipo2!='F';b--){
        PUSH(a[b],s);}
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


void funarray (char *token, SPointer s){

    if(strcmp(token,"()")) tira (token,s);
    else if(strcmp(token,"=*") ) igual (token,s);
    else if (strncmp(token, ",",1) == 0) bruh(token,s);
    else if (strncmp(token, "+",1) == 0) concat(s);
    else if (strncmp(token, "<>",1) == 0) inifim(token,s);






}














