#include <stdio.h>
#include <stdlib.h>

struct transition{
//1=a,2=b,3=c,etc
    int state1;
    int state2;
    int symbol;
    struct transition *nextTransitionPointer;
};

struct nfa{
    //this converter only supports nfa which do
    //not have any states with over 101 next states.
    int startState;
    int finalState;
    struct transition *transitionPointer;
};

struct node{
    struct nfa nfa;
    struct node *next;
};

void push(struct nfa, struct node **);
void initialize(struct node **);
struct nfa pop(struct node **);
struct nfa nfa_union(struct node **);
void print_nfa(struct node **);
struct nfa nfa_concat(struct node **);
void add_to_end(struct transition *, struct transition *);
void print_transition_list(struct transition*, int, int);
char convert_symbol_to_char(int symbol);
int adjust_transitionPointer(struct transition*, int);
void create_nfa_that_accepts_c(struct node **, char);
void change_last_transition_state2(struct transition *, int);