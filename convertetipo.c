#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"


void convertetipo (char *token){
    if(strncmp(token, "i",1) == 0){
            
            double x = POP();
            
            PUSH(x,'i');

    }else if(strncmp(token, "f",1) == 0){
           
            float x = POP();
            
            PUSH(x,'f');

    }else if(strncmp(token, "c",1) == 0){
            long x = POP();

            PUSH(x,'c');
            
    }
}