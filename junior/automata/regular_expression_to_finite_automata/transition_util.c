#include"parser.h"

void add_to_end(struct transition *transition1, struct transition *transition2){

    if(transition1->nextTransitionPointer == NULL){
        transition1->nextTransitionPointer = transition2;
    }else{
        add_to_end(transition1->nextTransitionPointer, transition2);
    }
    return;
}

char convert_symbol_to_char(int symbol){
    if(symbol == 1){
        return('a');
    }else if(symbol == 2){
        return('b');
    }else if(symbol == 3){
        return('c');
    }else if(symbol == 4){
        return('d');
    }else if(symbol == 5){
        return('e');
    }else if(symbol==0){
        return('E');
    }else{
        return('z');
    }
}

void print_transition_list(struct transition* transition, int startState, int finalState){

    char symbol = convert_symbol_to_char(transition->symbol);

    if(transition->state2 == -1){
        printf("(q%i,%c)-->q%i, q%i\n", transition->state1, symbol, 
        transition->nextTransitionPointer->state1, transition->nextTransitionPointer->state2);

        transition = transition->nextTransitionPointer;
    }else if(transition->nextTransitionPointer->state2 == -2){
        printf("S (q%i,%c)-->q%i\n", transition->state1, symbol, transition->state2);
        printf("F (q%i,E)\n",transition->state1);
    }else if(startState == transition->state1 && transition->state2 != -2){
        printf("S (q%i,%c)-->q%i\n",transition->state1,symbol,transition->state2);
        if(finalState == transition->state2 && transition->nextTransitionPointer == NULL){
            printf("F (q%i,E)\n",transition->state2);
        }
    }else if(transition == NULL){
        return;
    }else{
        printf("(q%i,%c)-->q%i\n",transition->state1,symbol,transition->state2);  
        if(finalState == transition->state2 && transition->nextTransitionPointer == NULL){
            printf("F (q%i,E)\n",transition->state2);
        } 
    }
    print_transition_list(transition->nextTransitionPointer, startState, finalState);
    return;
}

int adjust_transitionPointer(struct transition *myTransitionPointer, int startState){
    if(myTransitionPointer->nextTransitionPointer == NULL){
        myTransitionPointer->state1=startState;
        myTransitionPointer->state2=startState+1;

        return(myTransitionPointer->state2);
    }

    myTransitionPointer->state1=startState;
    myTransitionPointer->state2=startState+1;

    return(adjust_transitionPointer(myTransitionPointer->nextTransitionPointer, startState+1));    
    
}

void change_last_transition_state2(struct transition* myTranstionPointer, int finalState){
    if(myTranstionPointer->nextTransitionPointer == NULL){
        myTranstionPointer->state2 = finalState;
        return;
    }else{
        change_last_transition_state2(myTranstionPointer->nextTransitionPointer, finalState);
        return;
    }    
}