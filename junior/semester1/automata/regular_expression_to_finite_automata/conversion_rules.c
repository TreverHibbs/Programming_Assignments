#include"parser.h"

struct nfa nfa_concat(struct node **top){
    struct transition *newTransition1 = (struct transition*)malloc(sizeof(struct transition));
    struct transition *newTransition2 = (struct transition*)malloc(sizeof(struct transition));

    struct nfa nfa2 = pop(top);
    struct nfa nfa1 = pop(top);

    newTransition1->state1 = nfa1.finalState;
    newTransition1->state2 = nfa1.finalState+1;
    newTransition1->state3 = 0;
    newTransition1->rule = 0;
    newTransition1->symbol = 0;
    newTransition1->nextTransitionPointer = newTransition2;

    newTransition2->state1 = nfa1.finalState+1;
    newTransition2->state2 = nfa1.finalState+2;
    newTransition2->state3 = 0;
    newTransition2->rule = 0;
    newTransition2->symbol = 0;
    newTransition2->nextTransitionPointer = nfa2.transitionPointer;

    nfa1.finalState = adjust_transitionPointer(nfa2.transitionPointer, nfa1.finalState+2);

    add_to_end(nfa1.transitionPointer, newTransition1);

    nfa1.actualStartState = nfa1.startState;
    return(nfa1);
}

void create_nfa_that_accepts_c(struct node **top, char c){
    struct nfa newNfa;
    struct transition *transition = (struct transition*)malloc(sizeof(struct transition));
    
    transition->state1 = 1;
    transition->state2 = 2;
    transition->rule = 4;
    transition->nextTransitionPointer = NULL;

    if(c == 'a'){
        transition->symbol = 1;
    }else if (c == 'b'){
        transition->symbol = 2; 
    }else if (c == 'c'){
        transition->symbol = 3; 
    }else if (c == 'd'){
        transition->symbol = 4; 
    }else if (c == 'e'){
        transition->symbol = 5; 
    }else if(c == 'E'){
        transition->symbol = 0;
    }

    newNfa.startState = transition->state1;
    newNfa.finalState = transition->state2;
    transition->state3 = 0;
    newNfa.transitionPointer = transition;
    newNfa.actualStartState = newNfa.startState;
    push(newNfa, top);
}

struct nfa nfa_union(struct node **top){
    
    struct transition *StartToNfa1AndNfa2 = (struct transition*)malloc(sizeof(struct transition));
    //struct transition *StartToNfa2 = (struct transition*)malloc(sizeof(struct transition));
    struct transition *Nfa1FinalToNewFinal = (struct transition*)malloc(sizeof(struct transition));
    struct transition *Nfa2FinalToNewFinal = (struct transition*)malloc(sizeof(struct transition));

    struct nfa nfa2 = pop(top);
    struct nfa nfa1 = pop(top);
    
    int newStartState = 0;
    int newFinalState = 0;

    StartToNfa1AndNfa2->state1 = nfa1.startState;
    StartToNfa1AndNfa2->state2 = nfa1.startState+1;

    //initialize Nfa1FinalToNewFinal with known values
    Nfa1FinalToNewFinal->rule=1;
    Nfa1FinalToNewFinal->symbol=0;
    Nfa1FinalToNewFinal->nextTransitionPointer = NULL;
    Nfa1FinalToNewFinal->state1 = nfa1.finalState;
    Nfa1FinalToNewFinal->state2 = -1;
    Nfa1FinalToNewFinal->state3 = 0;

    //find the new start state and final state of nfa2 transition
    nfa2.startState = add_union_transition_together(nfa1,nfa2,Nfa1FinalToNewFinal);

    //initialize start transition with known values
    //and point its values twards start state of nfa1 and nfa2.
    StartToNfa1AndNfa2->rule = 1;
    StartToNfa1AndNfa2->state1 = nfa1.startState;
    StartToNfa1AndNfa2->state2 = nfa1.startState+1;
    StartToNfa1AndNfa2->state3 = nfa2.startState;
    StartToNfa1AndNfa2->nextTransitionPointer = nfa1.transitionPointer;
    StartToNfa1AndNfa2->symbol = 0;

    Nfa2FinalToNewFinal->rule = 1;
    //set to final sate so that the transition points twards new final and end of nfa2. 
    Nfa2FinalToNewFinal->state1 = Nfa1FinalToNewFinal->state2-1;
    Nfa2FinalToNewFinal->state2 = Nfa1FinalToNewFinal->state2;
    Nfa2FinalToNewFinal->symbol = 0;
    //set transition pointers so that Nfa2FinalToNewFinal transition is 
    //at the end of the transition linked list and points twards null at end.
    Nfa2FinalToNewFinal->nextTransitionPointer = NULL;
    add_to_end(StartToNfa1AndNfa2, Nfa2FinalToNewFinal);
    Nfa2FinalToNewFinal->state3 = 0;


    nfa1.transitionPointer = StartToNfa1AndNfa2;

    //print_transition_list(StartToNfa1AndNfa2, nfa1.startState, nfa1.finalState);
    nfa1.actualStartState = nfa1.startState;
    return(nfa1);

}

struct nfa nfa_star(struct node **top){
    struct transition *newTransitionFinal = (struct transition*)malloc(sizeof(struct transition));
    struct transition *newTransitionStart = (struct transition*)malloc(sizeof(struct transition));

    struct nfa myNfa = pop(top);

    //initialize new Transition final with known values.
    //so that end of transition list points to it
    //and it points twards new transition start.
    newTransitionFinal->state1 = myNfa.finalState;
    //-2 will indicate star operation for print
    newTransitionFinal->state2 = myNfa.finalState+1;
    newTransitionFinal->state3 = 0;\
    newTransitionFinal->rule = 2;
    newTransitionFinal->symbol = 0;
    newTransitionFinal->nextTransitionPointer = newTransitionStart;

    //initialize new transition start with known vlues.
    newTransitionStart->state1 = myNfa.finalState+1;
    newTransitionStart->state2 = myNfa.actualStartState;
    newTransitionStart->state3 = 0;
    newTransitionStart->rule = 2;
    newTransitionStart->symbol = 0;
    newTransitionStart->nextTransitionPointer = NULL;

    myNfa.actualStartState = myNfa.finalState+1;
    myNfa.finalState = myNfa.finalState+1;

    add_to_end(myNfa.transitionPointer, newTransitionFinal);

    return(myNfa);
}