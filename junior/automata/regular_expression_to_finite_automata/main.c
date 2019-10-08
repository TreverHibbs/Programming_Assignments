#include<stdio.h>

void main(arg, argv){

    while (not end of postfix expression){ 
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