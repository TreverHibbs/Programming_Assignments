#include "parser.h"

void print_nfa(struct node **top){
    
    struct nfa myNfa = (*top)->nfa;

    print_transition_list(myNfa.transitionPointer,myNfa.startState,myNfa.finalState);
    
    return;
}