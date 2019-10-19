#include "parser.h"

void initialize(struct node **top){
    *top = NULL;
}

void push(struct nfa inputNfa, struct node **top){
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    
    if(!tmp){
        printf("no memory left :(");
        return;
    }

    tmp->nfa = inputNfa;
    tmp->next = *top;
    *top = tmp;
    //test code
    //printf("This is end of desired if statement\n");

    return;
}

struct nfa pop(struct node **top){

    if(*top == NULL){
        printf("empty list");
    }else{

        struct nfa returnNfa;
        returnNfa = (*top)->nfa;

        struct node *tmp = *top;
        *top = (*top)->next;
        free(tmp);

        return(returnNfa);
    }
}

