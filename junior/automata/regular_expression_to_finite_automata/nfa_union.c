#include "parser.h"

struct nfa nfa_union(struct nfa nfa1, struct nfa nfa2, int **current_state){

     //nfa2= pop();
    //nfa1= pop();
    //push(NFAthat accepts L(nFA1) |L(nFA2));
    struct transition *transition1 = (struct transition*)malloc(sizeof(struct transition)); 
    transition1->symbol = 0;
    struct transition *transition2 = (struct transition*)malloc(sizeof(struct transition)); 
    transition2->symbol = 0;
    struct transition *transition3 = (struct transition*)malloc(sizeof(struct transition)); 
    transition3->symbol = 0;
    struct transition *transition4 = (struct transition*)malloc(sizeof(struct transition)); 
    transition4->symbol = 0;
    
    transition1->nextTransitionPointer = transition2;
    transition2->nextTransitionPointer = nfa1.transitionPointer;

    struct transition *tmp = nfa1.transitionPointer; 
    while(tmp->nextTransitionPointer != NULL){
        tmp->nextTransitionPointer = tmp->nextTransitionPointer->nextTransitionPointer;
    }
    tmp->nextTransitionPointer = nfa2.transitionPointer;

    tmp = nfa2.transitionPointer; 
    while(tmp->nextTransitionPointer != NULL){
        tmp->nextTransitionPointer = tmp->nextTransitionPointer->nextTransitionPointer;
    }
    tmp->nextTransitionPointer = transition3;
    transition3->nextTransitionPointer = transition4;

    //create new start and final states with E transitions
    struct nfa new_nfa;
    new_nfa.startState = (*(*current_state))++;
    new_nfa.finalState = (*(*current_state))++;

    transition1->state1 = new_nfa.startState;
    transition1->state2 = nfa1.startState;
    transition2->state1 = new_nfa.startState;
    transition2->state2 = nfa2.startState;

    //create new final state with E transitions
    transition3->state1 = nfa1.finalState;
    transition4->state1 = nfa2.finalState;
    transition3->state2 = new_nfa.finalState;
    transition4->state2 = new_nfa.finalState;

    new_nfa.transitionPointer = transition1;

    return(new_nfa);
}