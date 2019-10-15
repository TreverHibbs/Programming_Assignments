#include "parser.h"

struct nfa nfa_union(struct nfa nfa1, struct nfa nfa2, int **current_state){

     //nfa2= pop();
    //nfa1= pop();
    //push(NFAthat accepts L(nFA1) |L(nFA2));
    struct transition *transition1 = (struct transition*)malloc(sizeof(struct transition)); 
    transition1->symbol = 0;
    struct transition *transition2 = (struct transition*)malloc(sizeof(struct transition)); 
    transition1->symbol = 0;
    transition1->nextTransitionPointer = transition2;
    struct transition *transition3 = (struct transition*)malloc(sizeof(struct transition)); 
    transition3->symbol = 0;
    struct transition *transition4 = (struct transition*)malloc(sizeof(struct transition)); 
    transition4->symbol = 0;
    transition1->nextTransitionPointer = nfa1.transitionPointer;
    transition2->nextTransitionPointer = nfa2.transitionPointer;

    //create new start state with E transitions
    struct nfa new_nfa;
    new_nfa.startState = (*(*current_state))++;
    new_nfa.finalState = (*(*current_state))++;

    transition1->state1 = new_nfa.startState;
    transition1->state2 = nfa1.startState;
    transition2->state1 = new_nfa.startState;
    transition2->state2 = nfa2.startState;

    //create new final state with E transitions
    struct nfa new_final_state;
    new_final_state.finalState = (*(*current_state))++;
    new_final_state.startState = nfa1.finalState;
    new_final_state.s
}