#include"parser.h"

struct nfa nfa_concat(struct node **top){
    struct transition new_transition;

    struct nfa nfa2 = pop(top);
    struct nfa nfa1 = pop(top);

    new_transition.state1 = nfa1.finalState;
    new_transition.state2 = nfa1.finalState+1;
    new_transition.symbol = 0;

    adjust_transitionPointer(nfa2.transitionPointer, new_transition.state2);

    nfa1.finalState = nfa2.finalState+1;
    add_to_end(nfa1.transitionPointer, &new_transition);

    new_transition.nextTransitionPointer = nfa2.transitionPointer;

    return(nfa1);
}

void create_nfa_that_accepts_c(struct node **top){
    char c;
    struct nfa newNfa;
    struct transition *transition1 = (struct transition*)malloc(sizeof(struct transition));
    
    transition1->state1 = 1;
    transition1->state2 = 2;

    if(c == 'a'){
        transition1->symbol = 1;
    }else if (c == 'b'){
        transition1->symbol = 2; 
    }else if (c == 'c'){
        transition1->symbol = 3; 
    }else if (c == 'd'){
        transition1->symbol = 4; 
    }else if (c == 'e'){
        transition1->symbol = 5; 
    }


    newNfa.startState = transition1->state1;
    newNfa.finalState = transition1->state2;
    newNfa.transitionPointer = transition1;
    newNfa.transitionPointer->nextTransitionPointer = NULL;
    push(newNfa, top);
}