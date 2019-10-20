#include"parser.h"

struct nfa nfa_concat(struct node **top){
    struct transition *newTransition = (struct transition*)malloc(sizeof(struct transition));

    struct nfa nfa2 = pop(top);
    struct nfa nfa1 = pop(top);

    newTransition->state1 = nfa1.finalState;
    newTransition->state2 = nfa1.finalState+1;
    newTransition->symbol = 0;

    nfa1.finalState = adjust_transitionPointer(nfa2.transitionPointer, nfa1.finalState+1);

    add_to_end(nfa1.transitionPointer, newTransition);

    newTransition->nextTransitionPointer = nfa2.transitionPointer;

    return(nfa1);
}

void create_nfa_that_accepts_c(struct node **top, char c){
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

struct nfa nfa_union(struct node **top){
    struct transition *newTransitionStart = (struct transition*)malloc(sizeof(struct transition));
    struct transition *newTransitionStartNext = (struct transition*)malloc(sizeof(struct transition));
    struct transition *newTransitionFinalNfa2 = (struct transition*)malloc(sizeof(struct transition));
    struct transition *newTransitionFinalNfa1 = (struct transition*)malloc(sizeof(struct transition));

    struct nfa myNfa2 = pop(top);
    struct nfa myNfa1 = pop(top);

    newTransitionStart->nextTransitionPointer = newTransitionStartNext;
    newTransitionStart->state1 = 1;
    //state2 = -1 will identify union transitions
    newTransitionStart->state2 = -1;
    newTransitionStart->symbol = 0;
    myNfa1.finalState = adjust_transitionPointer(myNfa1.transitionPointer, 2);
    myNfa1.startState = 2;
    newTransitionStartNext->state1 = 2;
    newTransitionStartNext->nextTransitionPointer = myNfa1.transitionPointer;

    myNfa2.finalState = adjust_transitionPointer(myNfa2.transitionPointer, myNfa1.finalState);
    myNfa2.startState = myNfa1.finalState;
    change_last_transition_state2(myNfa1.transitionPointer, myNfa2.finalState+1);

    add_to_end(myNfa1.transitionPointer, myNfa2.transitionPointer);

    newTransitionStartNext->state2 = myNfa2.startState;

    newTransitionFinalNfa2->symbol = 0;
    newTransitionFinalNfa2->state1 = myNfa2.finalState;
    newTransitionFinalNfa2->state2 = myNfa2.finalState+2;
    newTransitionFinalNfa2->nextTransitionPointer = NULL;
    add_to_end(myNfa2.transitionPointer, newTransitionFinalNfa2);

    myNfa1.finalState = myNfa2.finalState+1;
    myNfa1.startState = 1;
    myNfa1.transitionPointer = newTransitionStart;

    return(myNfa1);
}

struct nfa nfa_star(struct node **top){
    struct transition *newTransitionFinal = (struct transition*)malloc(sizeof(struct transition));
    struct transition *newTransitionStart = (struct transition*)malloc(sizeof(struct transition));
    struct transition *newTransitionStarFlag = (struct transition*)malloc(sizeof(struct transition));

    struct nfa myNfa = pop(top);

    newTransitionFinal->state1 = myNfa.finalState;
    //-2 will indicate star operation for print
    newTransitionFinal->state2 = myNfa.finalState+1;
    newTransitionFinal->symbol = 0;
    newTransitionFinal->nextTransitionPointer = newTransitionStart;
    newTransitionStart->state1 = myNfa.finalState+1;
    newTransitionStart->state2 = 1;
    newTransitionStart->symbol = 0;
    newTransitionStart->nextTransitionPointer = newTransitionStarFlag;
    newTransitionStarFlag->state1 = myNfa.finalState+1;
    newTransitionStarFlag->state2 = -2;
    newTransitionStarFlag->symbol = 0;
    newTransitionStarFlag->nextTransitionPointer = NULL;

    myNfa.startState = myNfa.finalState+1;
    myNfa.finalState = myNfa.finalState+1;

    add_to_end(myNfa.transitionPointer, newTransitionFinal);

    return(myNfa);
}