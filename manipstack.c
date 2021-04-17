#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"




void manipstack (char *token){
    if (strncmp(token, "_",1) == 0) {
        char A = POPT();
        double  Y = POP ();
        PUSH (Y,A);
        PUSH (Y,A);
        
    }else if (strncmp(token, ";",1) == 0) {
        double  X = POP ();
        X++;

    }else if (strcmp(token, "\\") == 0) {
        char A = POPT();
        double  X = POP ();
        char B = POPT();
        double  Y = POP ();
        
        PUSH (X,A);
        PUSH (Y,B);

    }else if (strncmp(token, "@",1) == 0) {
        
        char A = POPT();
        double  X = POP ();
        char B = POPT();
        double  Y = POP ();
        char C = POPT();
        double  Z = POP (); 
        PUSH (Y,B);
        PUSH (X,A);
        PUSH (Z,C);
    }else if(strncmp(token, "$",1) == 0){
            double x = POP();
            int a = MOVEPOP(x);
            char b = POPT();
            PUSH(a,b);
            MOVE(x);
            PUSH(a,b);
    }
}