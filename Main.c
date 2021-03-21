#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "parser.h"

int main (){
    char line[10240];
    assert(fgets(line,10240,stdin)!=Null);
    assert(line[strlen(line)- 1]== '\n');
    parser(line);
    return 0;
}
