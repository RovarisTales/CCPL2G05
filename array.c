//TOKEN + EM ARRAYS
void concat(SPointer s){
Tipoval X = POP(s);
Tipoval Y = POP(s);
SPointer dois = Y.array;
SPointer  um = X.array;
Tipoval r=POP(s);
        if (X.tipo == 'a'){concatarray(um,dois);}
        if (X.tipo2 == 'n'){concatnum(r);}
        }
    }
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
//..........................................
//TOKEN ~ EM ARRAYS
void tiraarrayb (char *token, SPointer s){
Tipoval Y = POP(s)
SPointer dois = Y.array;
    if(strncmp(token, "~",1) == 0){
        tiraarray(dois);
        }
    }
void tiraarray(SPointer s,SPointer dois){
    Tipoval l;
    Tipoval a[100]= {{0}};
    int b;
    for(b=1;dois->top!=-1;b++){
        a[b]=POP(dois);}
    int xpto=b;
    for(b=xpto;b!=0;b--){
        PUSH(a[b],s);}
    }
//---------------------------------------
//TOKEN * EM ARRAYS
void multi (char *token){
Tipoval Y = POP(s)
SPointer dois = Y.array;
    if(strncmp(token, "*",1) == 0){
        Tipoval r = POP(s);
        multiarray(dois,s,r);
        }
    }
void multiarray(SPointer dois, SPointer s,tipoval r){
    Tipoval l;
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
//-------------------------------------------------
//TOKEN , ARRAYS E NORMAL
void bruh (char *token,SPointer s){
Tipoval Y = POP(s);
    if(strncmp(token, ",",1) == 0){
        if (Y.tipo == 'a'){bruharray(Y,s);}
        if (Y.tipo == 'n'){bruhnormal(Y,s);}
        }
    }
void bruhnormal(SPointer s,Tipoval Y){
    Tipoval t;
       for(int t=0;t!=Y.valor;t++){
    y.tipo='i';
    y.valor=t;
            PUSH(y,s);}
}
void bruharray(Tipoval Y, SPointer s){
SPointer dois = Y.array;
    Tipoval r;
    int b,c;
    for(b=0;top!=-1;b++){r=POP(dois);}
    Tipoval y;
    y.tipo='i';
    y.valor=b;
        PUSH(y,s);
}
//----------------------------------------------
//TOKEN <> EM ARRAYS
void fimarray (char *token,SPointer s){
    if(strncmp(token, ">",1) == 0){
        Tipoval r = POP(s);
        Tipoval Y = POP(s);
        if (Y.tipo == 'a'){fimarray(Y,r);}
        }
    }
    void fimarray(SPointer Y,Tipoval r){
    SPointer dois = Y.array;
    Tipoval a[100]= {{0}};
    int b;
    for(b=0;(b!=r.valor);b++){
        a[b]=POP(dois);}
    for(b;b!=0;b--){
        PUSH(a[b],s);}
        }
void inicioarray (char *token,SPointer s){
    if(strncmp(token, "<",1) == 0){
        Tipoval r = POP(s);
        Tipoval Y = POP(s);
        if (Y.tipo == 'a'){inicioarray(Y,r);}}
    }

void inicioarray(SPointer Y,Tipoval r){
    SPointer dois = Y.array;
    Tipoval a[100]= {{0}};
    int b;
    for(b=0;dois->top!=-1;b++){
        a[b]=POP(dois);}
    int xpto=b;
    for(b;b!=xpto-r.valor;b--){
        PUSH(a[b],s);}
        }
}
//---------------------------------------

//(AINDA TENHO DE MUDAR ISTO)
void parentesesfechado (char *token){
        if(strncmp(token, ")",1) == 0){
            parentesesaberto(*secundaria,*principal);
        }
    }
    void parentesesfechado(SPointer secundaria, SPointer principal){
        Tipoval l;
        l = POP(secundaria);
        PUSH(l,principal);
    }
    void parentesesaberto (char *token){
        if (strncmp(token, "(", 1) == 0) {
        }
        parentesesfechado(*secundaria,*principal);
    }
    void parentesesaberto(SPointer secundaria, SPointer principal) {
        Tipoval l;
        Tipoval a[100];
        int b;
        for(b=1;secundaria->top!=-1;b++){
            a[b]=POP(secundaria);
        }
        PUSH(a[b],principal);
    }
