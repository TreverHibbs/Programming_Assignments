#include "parser.h"

void main(int argc, char *argv[]){

    struct nfa *nfa1 = (struct nfa*)malloc(sizeof(struct nfa));
    struct nfa *nfa2 = (struct nfa*)malloc(sizeof(struct nfa));
    struct node *top = NULL;

    int length = 100;
    char regex[length];
    int i = 0;
    FILE *fp; 

    fp = fopen(argv[1], "r");
    fgets(regex, length, (FILE*)fp);
    
    if(fp != NULL)
    do{
        while (regex[i] != '\0'){ 
            char c = regex[i];
            if (c == '&'){ 
                //nfa1= pop();
                //nfa2= pop();
                //push(NFAthat accepts the concatenation of L(nFA1) followedby L(nFA2));
            } else if (c == '|') { 
                //nfa2= pop();
                //nfa1= pop();
                //push(NFAthat accepts L(nFA1) |L(nFA2));
            } else if (c == '*') { 
                //nfa1 = pop();
                //push(NFAthat accepts L(nFA)star);
            } else{
                //create nfa that accepts c
                struct transition *transition = (struct transition*)malloc(sizeof(struct transition));
                transition->state1 = 1;
                transition->state2 = 2;
                if(c == 'a'){
                    transition->symbol = 1;
                }else if (c == 'b')
                {
                    transition->symbol = 1; 
                }else if (c == 'c')
                {
                    transition->symbol = 1; 
                }else if (c == 'd')
                {
                    transition->symbol = 1; 
                }else if (c == 'e')
                {
                    transition->symbol = 1; 
                }

                nfa1->startState = 1;
                nfa1->startState = 2;
                nfa1->transitionPointer = transition; 
                push(nfa1, top);
            }
            i++;    
        }
    fgets(regex, length, (FILE*)fp);
    }while(fp != NULL);
}
