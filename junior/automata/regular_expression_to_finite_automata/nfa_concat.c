#include"parser.h"

void nfa_concat(struct node **top){
    struct transition new_transition;

    struct nfa nfa2 = pop(top);
    struct nfa nfa1 = pop(top);

    new_transition.state1 = nfa1.finalState;
    new_transition.state2 = nfa2.startState;
    new_transition.symbol = 0;

    nfa1.startState = nfa2.finalState;
    //find the end of nfa1's transition's"
    while(nfa1.transitionPointer->nextTransitionPointer != NULL){
        if(nfa1.transitionPointer->nextTransitionPointer == NULL)
        nfa1.transitionPointer = &new_transition;
    }

    new_transition.nextTransitionPointer = nfa2.transitionPointer;

}