//file containing the structures for the NFAs and transitions
#include "parser.h"

struct transition{
//1=a,2=b,3=c,etc
    int state1;
    int state2;
    int symbol;
    struct transition *transitionPointer;
};

struct nfa{
    int startState;
    int finalState;
    struct transition *transitionPointer;
};