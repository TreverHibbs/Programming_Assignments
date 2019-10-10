#include<stdio.h>
#include <stdlib.h>

void push(struct nfa, struct node*);
void initialize(struct node*);
struct nfa pop(struct node*);

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

struct node{
    struct nfa nfa;
    struct node *next;
};