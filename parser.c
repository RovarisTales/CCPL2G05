#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"


void parser (char *line){
    char *delimit = " /n/t";
    
    for(char *token = strtok(line, demilit);token != NULL; token = strtok(NULL, demilit)){
        char *sobra;
        long valint = strtol(token; &sobra; 10)
    }
}



