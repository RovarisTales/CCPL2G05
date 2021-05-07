// TOKEN + EM ARRAYS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

void concatigual (Tipoval x,Tipoval y, SPointer s){
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
    for(b=0;X->top!=-1;b++){
        a[b]=POP(X);
        }
    int cont=b;
    PUSH(y,X);
    for(b=cont;b!=-1;b--){
        PUSH(a[b],X);}
    x.array = X;
    PUSH(x,s);



}
void concat(SPointer s){
    Tipoval X = POP(s);
    Tipoval y = POP(s);
        if (X.tipo ==  y.tipo)concatigual(X,y,s);
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
    int b = 0;
    while(!vazio(dois)){
        
        Tipoval r;
        r=POP(dois);
        if(r.tipo == 'i' || r.tipo == 'l' || r.tipo == 'f' || r.tipo == 'c' || r.tipo == 'a'|| r.tipo == 's' ){
        b++;
        r.valor ++;
        }
        }
    Tipoval y;
    y.tipo='i';
    y.valor=b;
    y.array = NULL;
    PUSH(y,s);
}

void bruh (SPointer s){
    Tipoval Y = POP(s);
    
    if (Y.tipo == 'a' || Y.tipo == 's'){bruharray(Y,s);}
    else {bruhnormal(s,Y);}
        
}
//----------------------------------------------
//TOKEN <> EM ARRAYS
void fimarray2(SPointer s,Tipoval y,Tipoval r){
    Tipoval a[100]= {{0}};
    SPointer Y = y.array;
    int b ;
    int c = r.valor;
    for(b=0;!vazio(Y);b++){
        a[b]=POP(Y);}
    for(b = r.valor - 1;c != -1;b--,c--){
        PUSH(a[b],Y);}
    y.array = Y;
    PUSH(y,s);
}
void fimarray (SPointer s){
    
        Tipoval r = POP(s);
        Tipoval Y = POP(s);
        if (Y.tipo == 'a' || Y.tipo == 's'){fimarray2(s,Y,r);}
        
}
void inicioarray2(SPointer s,Tipoval y,Tipoval r){
    SPointer Y = y.array;
    Tipoval a[100];
    int b;
    for(b=0;Y->top!=-1;b++){
        a[b]=POP(Y);}
    
    int xpto=b;
    for(;b!=xpto-r.valor-1;b--){
        PUSH(a[b],Y);};
        
        y.array = Y;
        PUSH(y,s);
    
}

void inicioarray (SPointer s){

        Tipoval r = POP(s);
        Tipoval Y = POP(s);
        if (Y.tipo == 'a' || Y.tipo == 's'){inicioarray2(s,Y,r);}
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
// -----------------------------------------------
void igualarray (Tipoval x, Tipoval y, SPointer s){
    Tipoval um, dois;

    SPointer xis, ips;
    xis = x.array;
    ips = y.array;

    int i = 1;

    while(i != 0  && !vazio(xis) && !vazio(ips)){
        um = POP(xis);
        dois = POP(ips);
        if(um.valor == dois.valor) i = 1;
        else i = 0;
    }
    Tipoval bolo;
    bolo.valor = i;
    bolo.tipo = 'i';
    bolo.array = NULL;
    PUSH(bolo,s);


}

void igual (SPointer s){

    Tipoval X = POP(s);
    Tipoval Y = POP(s);


    if (X.tipo == 'i');
    else igualarray(X,Y,s);



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
    else if (strcmp(token,"=") == 0) igual(s);

}