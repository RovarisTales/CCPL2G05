// TOKEN + EM ARRAYS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

void concatarray (Tipoval x,Tipoval y, SPointer s){
    Tipoval a[100];
    SPointer dois = x.array;
    SPointer um  = y.array;
    int b;
    for(b=0;!vazio(dois);b++){
        a[b]=POP(dois);}
    
    for(;b!=-1;b--){
        PUSH(a[b],um);}
        y.array = um;
        PUSH(y,s);
}
void concatnumarray (Tipoval x,Tipoval y, SPointer s){
    SPointer um = y.array;
    PUSH(x,um);
    y.array = um;
    PUSH(y,s);
}
void concatarraynum (Tipoval x ,Tipoval y, SPointer s){
    Tipoval a[100];
    int b;
    SPointer X;
    X = x.array;
    Tipoval xpto;
    
    xpto.valor = '0';
    xpto.tipo = 'a';
    xpto.array = NULL;
    
    SPointer um = xpto.array;
    criaStack(um,1024);
    PUSH(y,um);
    for(b=0;X->top!=-1;b++){
        a[b]=POP(X);
        }
    int cont=b;
    for(b=cont;b!=-1;b--){
        PUSH(a[b],um);}
    xpto.array = um;
    PUSH(xpto,s);



}
void concat(SPointer s){
    Tipoval X = POP(s);
    Tipoval y = POP(s);
        if (X.tipo == 'a' && y.tipo == 'a')concatarray(X,y,s);
        else if (X.tipo != 'a' && y.tipo == 'a')concatnumarray(X,y,s);
        else concatarraynum(X,y,s);
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
void multi(SPointer s){

    Tipoval fator,array;
    fator = POP(s);
    array = POP(s);
    SPointer dois = array.array;
    



    Tipoval a[100];
    int b;
    for(b=0;!vazio(dois);b++){
        a[b]=POP(dois);}
    int xpto=b;
    for(int c=0;c<fator.valor;c++){
        printf("primeiro ciclo\n");
        for(b=xpto;b!=-1;b--){
        PUSH(a[b],dois);
        }
    }
    array.array = dois;
    PUSH(array,s);
}


//-------------------------------------------------
//TOKEN , ARRAYS E NORMAL
void bruhnormal(SPointer s,Tipoval X){
    
    int a = X.valor;
    
    SPointer new = NULL;
    new = criaStack(new,150);
    Tipoval Y;
    Y.valor = 0;
    Y.tipo = 'a';
    Y.array = new;
    for(int t=0;t<a;t++){
        X.valor=t;
        PUSH(X,new);
    }
    
    PUSH(Y,s);
    
}
void bruharray(Tipoval Y, SPointer s){
    SPointer dois = Y.array;
    int b;
    for(b=0;vazio(dois)!=1;b++){
        
        Tipoval r;
        r=POP(dois);
        printf("%g\n", r.valor);
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


void parentesesfechado2(SPointer secundaria, SPointer principal){
        Tipoval a[100];
        int b;
        for(b=0;secundaria->top!=-1;b++){
            a[b]=POP(secundaria);
        }
        for (; b>0; b--){
            PUSH(a[b],secundaria);
        }
        Tipoval x;
        x.array = secundaria;
        x.tipo = 'a';
        x.valor = 0;
        PUSH(x,principal);
        PUSH(a[0],principal);
} // ta certo


void parentesesaberto2(SPointer secundaria, SPointer principal) {
        
        Tipoval a[100];
        int b;
        for(b=0;secundaria->top!=-1;b++){
            a[b]=POP(secundaria);
        }
        int c = b - 2;
        for (; c>-1; c--){
            PUSH(a[c],secundaria);
            
        }
        Tipoval x;
        x.array = secundaria;
        x.tipo = 'a';
        x.valor = 0;
        PUSH(x,principal);
        PUSH(a[b-1],principal);
}
void parentesesfechado (SPointer s){
        
            Tipoval l = POP(s);
            SPointer secundaria = l.array;
            parentesesfechado2(secundaria,s);
        
}
void parentesesaberto (SPointer s){
        
        Tipoval l = POP(s);
        SPointer secundaria = l.array;
        parentesesaberto2(secundaria,s);
        
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