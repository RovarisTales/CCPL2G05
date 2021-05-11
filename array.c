/**
 *@file Este ficheiro contem as funçoes utilizadas para arrays.
 *
 */

// TOKEN + EM ARRAYS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

/**
 *\brief Coloca o conteudo de um array dentro do outro
 * @param s Pointer para a stack
 * @param x Array 
 * @param y Array 
 */
void concatigual (Tipoval x,Tipoval y, SPointer s){
    Tipoval a[1024];
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

/**
 *\brief Coloca um numero dentro do array quando aparece um numero primeiro que um array
 * @param s Pointer para a stack
 * @param x Array ou numero
 * @param y Array ou numero
 */
void concatnumarray (Tipoval x,Tipoval y, SPointer s){
    SPointer um = y.array;
    PUSH(x,um);
    y.array = um;
    PUSH(y,s);
}
/**
 *\brief Coloca um numero dentro do array quando aparece um array primeiro que um numero
 * @param s Pointer para a stack
 * @param x Array ou numero
 * @param y Array ou numero
 */
void concatarraynum (Tipoval x ,Tipoval y, SPointer s){
    Tipoval a[1024];
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
/**
 *\brief Quando é detado um array ou uma string juntamente de o token '+' esta função reencaminha para as suas subfunções (concatigual, concatnumarray,concatarraynum). 
 * Estas ações depende do tipo do que se encontra no topo da stack.
 * @param s Pointer para a stack
 */
void concat(SPointer s){
    Tipoval X = POP(s);
    Tipoval y = POP(s);
        if (X.tipo ==  y.tipo)concatigual(X,y,s);
        else if (X.tipo != 'a' && (y.tipo == 'a' || y.tipo == 's'))concatnumarray(X,y,s);
        else concatarraynum(X,y,s);
}
    

//..........................................
//TOKEN ~ EM ARRAYS

/**
 *\brief Coloca todos os elementos no topo da stack
 * @param s Pointer para a stack
 * @param dois Array/string
 */
void tiraarray(SPointer s,SPointer dois){
    
    Tipoval a[1024];
    int b;
    for(b=1;dois->top!=-1;b++){
        a[b]=POP(dois);}
    int xpto=b;
    for(b=xpto;b!=0;b--){
        PUSH(a[b],s);}
}
/**
 *\brief Reencaminha para a sua subfunção (tiraarray) relacionada com o token '~' em arrays
 * @param s Pointer para a stack
 */
void tiraarrayb ( SPointer s){
    Tipoval Y = POP(s);
    SPointer dois = Y.array;
    
    tiraarray(s,dois);
        
}
//---------------------------------------
//TOKEN * EM ARRAYS
/**
 *\brief Repete um array/string dependendo do numero que lhe segue na stack. Esta ação ocorre quando um '*' é detetado juntamente com um array e um numero.
 * @param s Pointer para a stack
 */
void multi(SPointer s){

    Tipoval fator,array;
    fator = POP(s);
    array = POP(s);
    SPointer dois = array.array;
    



    Tipoval a[10240];
    int b = 0;
    while(!vazio(dois)){
        Tipoval r = POP(dois);
        if(r.tipo == 'i' || r.tipo == 'l' || r.tipo == 'f' || r.tipo == 'c' || r.tipo == 'a'|| r.tipo == 's'){
                a[b]=r;
                b++;
            }
        }
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

/**
 *\brief Faz o range de um numero. Ação correspondente ao token ','.
 * @param s Pointer para a stack
 * @param X Numero no topo da stack
 */
void bruhnormal(SPointer s,Tipoval X){
    
    int a = X.valor;
    
    SPointer new = NULL;
    new = criaStack(new,1024);
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

/**
 *\brief Indica o tamanho do array. Ação correspondente ao token ',' em arrays.
 * @param s Pointer para a stack
 * @param Y Array/string
 */
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

/**
 *\brief Quando é detado um array ou uma string juntamente de o token ',' esta função reencaminha para as suas subfunções (bruharray, bruhnormal).
 * @param s Pointer para a stack
 */
void bruh (SPointer s){
    Tipoval Y = POP(s);
    
    if (Y.tipo == 'a' || Y.tipo == 's'){bruharray(Y,s);}
    else {bruhnormal(s,Y);}
        
}
//----------------------------------------------
//TOKEN <> EM ARRAYS

/**
 *\brief Coloca uma certa quantidade do conteudo no fim do array/string na stack (esta quantia está associada ao numero introduzido na linha juntamente com o array).
 * @param s Pointer para a stack
 * @param y Array/string
 * @param r Numero relativamente á quantidade previamente mencionada
 */
void fimarray2(SPointer s,Tipoval y,Tipoval r){
    Tipoval a[1024];
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

/**
 *\brief Faz a operação '>' entre arrays/strings.
 * @param s Pointer para a stack
 * @param Y Array/string
 * @param r Array/string
 */
void comparaarrayfim(SPointer s, Tipoval Y, Tipoval r){
    
    Tipoval um, dois;

    SPointer xis, ips;
    xis = r.array;
    ips = Y.array;

    int i = 0;

    while(i != 1  && !vazio(xis) && !vazio(ips)){
        um = POP(xis);
        dois = POP(ips);
        if(um.valor < dois.valor) i = 1;
        else i = 0;
    }
    Tipoval bolo;
    bolo.valor = i;
    bolo.tipo = 'i';
    bolo.array = NULL;
    PUSH(bolo,s);



}

/**
 *\brief Função relacionada com a operação '>' , ela reencaminha para as suas subfunções dependendo do tipo(arrays/strings/numeros) do topo da stack.
 * @param s Pointer para a stack
 */
void fimarray (SPointer s){
    
        Tipoval r = POP(s);
        Tipoval Y = POP(s);
        if ((Y.tipo == 'a' || Y.tipo == 's') && r.tipo == 'i'){fimarray2(s,Y,r);}
        else if (Y.tipo == r.tipo) comparaarrayfim(s,Y,r);
        
}

/**
 *\brief Coloca uma certa quantidade do conteudo no inicio do array/string na stack (esta quantia está associada ao numero introduzido na linha juntamente com o array).
 * @param s Pointer para a stack
 * @param y Array/string
 * @param r Numero relativamente á quantidade previamente mencionada
 */
void inicioarray2(SPointer s,Tipoval y,Tipoval r){
    SPointer Y = y.array;
    Tipoval a[1024];
    int b;
    for(b=0;Y->top!=-1;b++){
        a[b]=POP(Y);}
    
    int xpto=b;
    for(;b!=xpto-r.valor-1;b--){
        PUSH(a[b],Y);};
        
        y.array = Y;
        PUSH(y,s);
    
}

/**
 *\brief Faz a operação '<' entre arrays/strings.
 * @param s Pointer para a stack
 * @param Y Array/string
 * @param r Array/string
 */
void comparaarrayinicio(SPointer s, Tipoval Y, Tipoval r){
    
    Tipoval um, dois;

    SPointer xis, ips;
    xis = r.array;
    ips = Y.array;

    int i = 1;

    while(i != 0  && !vazio(xis) && !vazio(ips)){
        um = POP(xis);
        dois = POP(ips);
        if(um.valor > dois.valor) i = 0;
        else i = 1;
    }
    Tipoval bolo;
    bolo.valor = i;
    bolo.tipo = 'i';
    bolo.array = NULL;
    PUSH(bolo,s);



}

/**
 *\brief Função relacionada com a operação '<' , ela reencaminha para as suas subfunções dependendo do tipo(arrays/strings/numeros) do topo da stack.
 * @param s Pointer para a stack
 */
void inicioarray (SPointer s){

        Tipoval r = POP(s);
        Tipoval Y = POP(s);
        if ((Y.tipo == 'a' || Y.tipo == 's') && r.tipo == 'i'){inicioarray2(s,Y,r);}
        else if (Y.tipo == r.tipo) comparaarrayinicio(s,Y,r);
}
//-------------------- # com dois arrays -- PROCURAR y em z --
/**
 *\brief Procura um array/strings dentro de um array/strings, ação relacionada com o token '#' em arrays/strings.
 * @param s Pointer para a stack
 * @param Y Array/string
 * @param r Array/string
 */
void subarray(Tipoval Y,Tipoval Z, SPointer s){
    SPointer ypslon = Y.array;
    SPointer ze = Z.array;
    Tipoval y[100];
    Tipoval z[100];
            int b;
            int a;
            int contb;
            int tamanho;
            
            for (b=0;!vazio(ypslon);b++){ // pega os elementos de y
                y[b] = POP(ypslon);
            }
            b--;
            contb = b;
            for (a=0;!vazio(ze);a++){ // pega os elementos de z
                z[a] = POP(ze); 
            }
            a--;
            tamanho = a;
            while (a!=-1 && b!= -1){ // procura de tras pra frente
                
                if(z[a].valor==y[b].valor){b--;a--;}
                else { a--;b=contb;}
                
            }
            
            if(a==-1 && b != -1) {
                tamanho = 0;
                a=0;
                contb=0;
            }
            Tipoval aux;
            aux.valor = tamanho - a -contb - 1;
            aux.tipo = 'i';
            aux.array = NULL;
            PUSH(aux,s);
}

/**
 *\brief Função relacionada com a operação '#' , ela reencaminha para a sua subfunção (subarray).
 * @param s Pointer para a stack
 * @param token É o token que vamos verificar se coincide com '#'
 */
void sub (char *token,SPointer s){
    if(strncmp(token, "#",1) == 0){
        Tipoval Y = POP(s);
        Tipoval Z = POP(s);
      subarray(Y, Z,  s); 
    }
}




//---------------------------------------

//(AINDA TENHO DE MUDAR ISTO)

/**
 *\brief Remove o ultimo elemento de um array/string e coloca na stack, ação relacionada com o token ')' em arrays/strings.
 * @param principal Pointer para a stack
 * @param secundaria Pointer para a stack do array/string
 */
void parentesesfechado2(SPointer secundaria, SPointer principal){
        Tipoval a[1024];
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

/**
 *\brief Remove o primeiro elemento de um array/string e coloca na stack, ação relacionada com o token '(' em arrays/strings.
 * @param principal Pointer para a stack
 * @param secundaria Pointer para a stack do array/string
 */
void parentesesaberto2(SPointer secundaria, SPointer principal) {
        
        Tipoval a[1024];
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

/**
 *\brief Função relacionada com a operação ')' , ela reencaminha para a sua subfunção (subarray).
 * @param s Pointer para a stack
 */
void parentesesfechado (SPointer s){
        
            Tipoval l = POP(s);
            SPointer secundaria = l.array;
            parentesesfechado2(secundaria,s);
        
}
/**
 *\brief Função relacionada com a operação '(' , ela reencaminha para a sua subfunção (subarray).
 * @param s Pointer para a stack
 */
void parentesesaberto (SPointer s){
        
        Tipoval l = POP(s);
        SPointer secundaria = l.array;
        parentesesaberto2(secundaria,s);
        
}
// -----------------------------------------------
/**
 *\brief Verifica se os arrays/strings são iguais, ação relacionada com o token '(' em arrays/strings.
 * @param s Pointer para a stack
 * @param x Array/strings
 * @param y Array/strings
 */
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

/**
 *\brief Vai pegar num numero/letra no array/string dependendo do numero colocado no input juntamente com esta, ação relacionada com o token '(' em arrays/strings com um numero.
 * @param s Pointer para a stack
 * @param x Numero
 * @param y Array/strings
 */
void igualnum (Tipoval x, Tipoval y, SPointer s){

    int c = x.valor;
    SPointer um;
    um = y.array;

    Tipoval a[100];
    int b = 0;
    
    while(!vazio(um)){
        Tipoval r =POP(um);
        if(r.tipo == 'i' || r.tipo == 'l' || r.tipo == 'f' || r.tipo == 'c' || r.tipo == 'a'|| r.tipo == 's' ){
                a[b] = r;
                b++;
            }
        }

    PUSH(a[b-c-1],s);




}


/**
 *\brief Função relacionada com a operação '=' , ela reencaminha para as suas subfunções (igualnum,igualarray) dependendo do imput (array e num ou array's).
 * @param s Pointer para a stack
 * @param token É o token que vamos verificar se coincide com '#'
 */
void igual (SPointer s){

    Tipoval X = POP(s);
    Tipoval Y = POP(s);


    if (X.tipo == 'i')igualnum(X,Y,s);
    else igualarray(X,Y,s);



}




/**
 *\brief Função relacionada com as operações "()<>,*~+=" em arrays/strings , ela reencaminha para as suas subfunções correspondentes ao token introduzido.
 * @param s Pointer para a stack
 * @param token Token detetado
 */
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
    else sub(token,s);
}
