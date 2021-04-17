
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "stack.h"

void readline (char *token){
    if(strncmp(token, "l",1) == 0){
        char lerlinha [10240];
        char *oi;
        assert(fgets(lerlinha,10240,stdin)!=NULL);
        assert(lerlinha[strlen(lerlinha)- 1]== '\n');
        double a = strtod(lerlinha,&oi);
        PUSH(a,'f');
    }
}