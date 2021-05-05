// TOKEN + EM ARRAYS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

void concatarray (SPointer um,SPointer dois){
    Tipoval a[100]= {{0}};
    int b;
    for(b=1;dois->top!=-1;b++){
        a[b]=POP(dois);}
    int xpto=b;
    for(b=xpto;b!=0;b--){
        PUSH(a[b],um);}
}
void concatnum (Tipoval r,SPointer dois){
    PUSH(r,dois);
}

void concat(SPointer s){
    Tipoval X = POP(s);
    Tipoval Y = POP(s);
    SPointer dois = Y.array;
    SPointer  um = X.array;
    
        if (X.tipo == 'a'){concatarray(um,dois);}
        if (X.tipo != 'a'){concatnum(X,dois);}
}
    

//..........................................
//TOKEN ~ EM ARRAYS

void tiraarray(SPointer s,SPointer dois){
    
    Tipoval a[100]= {{0}};
    int b;
    for(b=1;dois->top!=-1;b++){
        a[b]=POP(dois);}
    int xpto=b;
    for(b=xpto;b!=0;b--){
        PUSH(a[b],s);}
}
void tiraarrayb ( SPointer s){
    Tipoval Y = POP(s);
    SPointer dois = Y.array;
    
    tiraarray(s,dois);
        
}
//---------------------------------------
//TOKEN * EM ARRAYS
void multiarray(SPointer dois, SPointer s,Tipoval r){

    Tipoval a[100]= {{0}};
    int b;
    for(b=1;dois->top!=-1;b++){
        a[b]=POP(dois);}
    int xpto=b;
    for(int c=0;c!=r.valor;c++){
    for(b=xpto;b!=0;b--){
        PUSH(a[b],s);}
        }
}

void multi (SPointer s){
    
    
    Tipoval r = POP(s);
    Tipoval Y = POP(s);
    SPointer dois = Y.array;
    multiarray(dois,s,r);
        
}
//-------------------------------------------------
//TOKEN , ARRAYS E NORMAL
void bruhnormal(SPointer s,Tipoval Y){
    
    int a = Y.valor;
    for(int t=0;t<a;t++){
        Y.valor=t;
        PUSH(Y,s);
    }
}
void bruharray(Tipoval Y, SPointer s){
    SPointer dois = Y.array;
    int b;
    for(b=0;vazio(dois)!=1;b++){
        
        Tipoval r;
        r=POP(dois);
        r.valor ++;
        }
    Tipoval y;
    y.tipo='i';
    y.valor=b;
    y.array = NULL;
        PUSH(y,s);
}
void bruh (SPointer s){
    Tipoval Y = POP(s);
    
    if (Y.tipo == 'a'){bruharray(Y,s);}
    if (Y.tipo != 'a'){bruhnormal(s,Y);}
        
}
//----------------------------------------------
//TOKEN <> EM ARRAYS
void fimarray2(SPointer s,SPointer Y,Tipoval r){
    Tipoval a[100]= {{0}};
    int b;
    for(b=0;(b!=r.valor);b++){
        a[b]=POP(Y);}
    for(;b!=0;b--){
        PUSH(a[b],s);}
}
void fimarray (SPointer s){
    
        Tipoval r = POP(s);
        Tipoval Y = POP(s);
        if (Y.tipo == 'a'){fimarray2(s,Y.array,r);}
        
}
void inicioarray2(SPointer s,SPointer Y,Tipoval r){
    Tipoval a[100]= {{0}};
    int b;
    for(b=0;Y->top!=-1;b++){
        a[b]=POP(Y);}
    int xpto=b;
    for(;b!=xpto-r.valor;b--){
        PUSH(a[b],s);}
}

void inicioarray (SPointer s){

        Tipoval r = POP(s);
        Tipoval Y = POP(s);
        if (Y.tipo == 'a'){inicioarray2(s,Y.array,r);}
}



//---------------------------------------

//(AINDA TENHO DE MUDAR ISTO)


void parentesesaberto2(SPointer secundaria, SPointer principal){
        Tipoval l;
        l = POP(secundaria);
        PUSH(l,principal);
}


void parentesesfechado2(SPointer secundaria, SPointer principal) {
        
        Tipoval a[100];
        int b;
        for(b=1;secundaria->top!=-1;b++){
            a[b]=POP(secundaria);
        }
        PUSH(a[b],principal);
}
void parentesesfechado (SPointer s){
        
            Tipoval l = POP(s);
            SPointer secundaria = l.array;
            parentesesaberto2(secundaria,s);
        
}
void parentesesaberto (SPointer s){
        
        Tipoval l = POP(s);
        SPointer secundaria = l.array;
        parentesesfechado2(secundaria,s);
        
}

void funarray (char *token, SPointer s){
    if (strcmp(token,"(") == 0) parentesesaberto(s);
    else if (strcmp(token,")") == 0) parentesesfechado(s);
    else if (strcmp(token,">") == 0) fimarray(s);
    else if (strcmp(token,"<") == 0) inicioarray(s);
    else if (strcmp(token,",") == 0) bruh(s);
    else if (strcmp(token,"*") == 0) multi(s);
    else if (strcmp(token,"~") == 0) tiraarrayb(s);
    else if (strcmp(token,"+") == 0) concat(s);




}