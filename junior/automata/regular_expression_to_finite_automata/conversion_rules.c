#include"parser.h"

struct nfa nfa_concat(struct node **top){
    struct transition new_transition;

    struct nfa nfa2 = pop(top);
    struct nfa nfa1 = pop(top);

    new_transition.state1 = nfa1.finalState;
    new_transition.state2 = nfa2.startState;
    new_transition.symbol = 0;

    nfa1.startState = nfa2.finalState;
    add_to_end(nfa1.transitionPointer, &new_transition);

    new_transition.nextTransitionPointer = nfa2.transitionPointer;

    return(nfa1);
}