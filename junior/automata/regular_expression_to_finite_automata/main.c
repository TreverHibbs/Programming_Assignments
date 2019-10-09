#include "parser.h"

void main(int argc, char *argv[]){

    int length = 100;
    char regex[length];
    int i = 0;
    FILE *fp; 
    fp = fopen(argv[1], "r");
    fgets(regex, length, (FILE*)fp);
    printf("1 : %s\n", regex );
    fclose(fp);
    fgets(regex, length, (FILE*)fp);
    
    while (regex[i]){ 
        c = next character in postfix expression;
        if (c == ’&’){ 
            nFA2= pop();
            nFA1= pop();
            push(NFAthat accepts the concatenation of L(nFA1) followedby L(nFA2));
        } else if (c == ’|’) { 
            nFA2= pop();
            nFA1= pop();
            push(NFAthat accepts L(nFA1) |L(nFA2));
        } else if (c == ’*’) { 
            nFA= pop();
            push(NFAthat accepts L(nFA)star);
        } else
            push(NFAthat accepts a single character c);
        }
}
