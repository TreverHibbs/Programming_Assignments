#include "parser.h"

void main(int argc, char *argv[]){

    struct nfa nfa1; //= (struct nfa*)malloc(sizeof(struct nfa));
    struct nfa nfa2; //= *
    struct node tmp;
    struct node *pointer = &tmp;
    struct node **top = &pointer;

    int length = 100;
    char regex[length];
    int i = 0;
    char c;
    int var = 1;
    int *ptr; 
    // double pointer for ptr
    int **current_state; 
    // storing address of var in ptr2 
    ptr = &var;
    //storing adress of 
    current_state = &ptr; 
    FILE *fp; 

    //test code
    //printf("this is argv[1] %s\n", argv[1]);

    fp = fopen(argv[1], "r");

    //test code
    //printf("this is regex[0] %c\n", regex[0]);

    while(fgets(regex, length, (FILE*)fp)){
        while(regex[i] != '\n'){ 
            c = regex[i];
            //test code
            //printf("this is regex %s", regex);
            printf("this is c %c\n", c);
            if (c == '&'){ 
                //0 = E transition symbol
                //nfa1= pop();
                //nfa2= pop();
                //push(NFAthat accepts the concatenation of L(nFA1) followedby L(nFA2));

                nfa2 = pop(top);
                nfa1 = pop(top);
                //test code
                //printf("This is the result of poping. %i\n", nfa1.transitionPointer->symbol);
 
                struct nfa new_nfa = nfa_union(nfa1, nfa2, current_state);
                push(new_nfa, top);

            } else if (c == '|') { 
                //nfa2= pop();
                //nfa1= pop();
                //push(NFAthat accepts L(nFA1) |L(nFA2));
                struct transition *transition = (struct transition*)malloc(sizeof(struct transition)); 
                transition->symbol = 0;

                nfa2 = pop(top);
                nfa1 = pop(top);

            } else if (c == '*') { 
                //nfa1 = pop();
                //push(NFAthat accepts L(nFA)star);
            } else{
                //create nfa that accepts c
                struct transition *transition = (struct transition*)malloc(sizeof(struct transition));
                transition->state1 = (*(*current_state))++;
                transition->state2 = (*(*current_state))++;
                //test printf
                //printf("this is current state%i", (*(*current_state)));
                if(c == 'a'){
                    transition->symbol = 1;
                    //test code
                    //printf("this is to test value of tansition->symbol %i\n", transition->symbol);
                }else if (c == 'b')
                {
                    transition->symbol = 2; 
                    //test code
                    //printf("this is to test value of tansition->symbol %i\n", transition->symbol);
                }else if (c == 'c')
                {
                    transition->symbol = 3; 
                }else if (c == 'd')
                {
                    transition->symbol = 4; 
                }else if (c == 'e')
                {
                    transition->symbol = 5; 
                }

                nfa1.startState = transition->state1;
                nfa1.finalState = transition->state2;
                nfa1.transitionPointer = transition; 
                nfa1.transitionPointer->nextTransitionPointer = NULL;
                push(nfa1, top);
                //test code
                //printf("This is end of desired if statement %i\n", *top);
            }
            i++;    
        }

    //test code
    //printf("this is top->nfa.transtiionpointer->symbol %i\n", top->nfa.transitionPointer->symbol);

    }

    //print_nfa(top);
}
