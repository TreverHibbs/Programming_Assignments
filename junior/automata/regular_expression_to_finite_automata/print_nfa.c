#include "parser.h"

void print_nfa(struct node **top){
    printf("inside print");
    for(int i = 1; i != 0; i++){
        if((*top)->nfa.transitionPointer->state1 == i){
            printf("(q%i, %i) -> q%i", i, (*top)->nfa.transitionPointer->symbol, (*top)->nfa.transitionPointer->state2);
        }
    }

    return;
}