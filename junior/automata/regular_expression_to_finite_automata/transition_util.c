#include"parser.h"

int add_to_end(struct transition *transition1, struct transition *transition2){

    if(transition1->nextTransitionPointer == NULL){
        transition1->nextTransitionPointer = transition2;
    }else{
        add_to_end(transition1->nextTransitionPointer, transition2);
    }
    return(length_of_transition_list(transition2));
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

    if(transition==NULL){
        return;
    }

    char symbol = convert_symbol_to_char(transition->symbol);

    if(transition->rule == 4){
        printf("(q%i,%c)->q%i\n", transition->state1,symbol ,transition->state2);
    }else if(transition->rule = 1){
        if(transition->state3 == 0){
            printf("(q%i,%c)->q%i\n",transition->state1,symbol,transition->state2);
        }else{
            printf("(q%i,%c)->q%i,q%i\n", transition->state1,symbol,transition->state2,transition->state3);
            if(transition->state2 == finalState && transition->nextTransitionPointer == NULL){
                printf("F (q%i,%c)\n", finalState, 'E');
            }
        }
    }else if(transition->rule == 0){
        printf("(q%i,%c)->q%i\n", transition->state1, symbol, transition->state2);
    }

    print_transition_list(transition->nextTransitionPointer, startState, finalState);

    return;

    /*
    if(transition->state2 == -1){
        printf("(q%i,%c)-->q%i, q%i\n", transition->state1, symbol, 
        transition->nextTransitionPointer->state1, transition->nextTransitionPointer->state2);

        transition = transition->nextTransitionPointer;
    }else if(startState == transition->state1){
        printf("S (q%i,%c)-->q%i\n",transition->state1,symbol,transition->state2);
        if(finalState == transition->state2){
            printf("F (q%i,E)\n",transition->state2);
        }
    }else if(transition == NULL){
        return;
    }else{
        printf("(q%i,%c)-->q%i\n",transition->state1,symbol,transition->state2);  
        if(finalState == transition->state2){
            printf("F (q%i,E)\n",transition->state2);
        } 
    }
    print_transition_list(transition->nextTransitionPointer, startState, finalState);
    return;
    */
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

int length_of_transition_list(struct transition *myTransition){
    int count = 0;
    if(myTransition != NULL){
        count = length_of_transition_list(myTransition->nextTransitionPointer);
        return(1+count);
    }else{
        return(0);
    }
}

int add_union_transition_together(struct nfa nfa1, struct nfa nfa2, struct transition *Nfa1ToNewFinal){
    add_to_end(nfa1.transitionPointer, Nfa1ToNewFinal);
    adjust_transitionPointer(Nfa1ToNewFinal, nfa1.finalState);

    add_to_end(nfa1.transitionPointer, nfa2.transitionPointer);
    nfa2.finalState = adjust_transitionPointer(nfa2.transitionPointer, nfa1.finalState+2);
    nfa2.startState = nfa1.finalState+2;

    nfa1.finalState = adjust_transitionPointer(nfa1.transitionPointer, 2);
    nfa1.startState = 2;
    Nfa1ToNewFinal->state2 = nfa2.finalState+1;

    Nfa1ToNewFinal->state3 = 0;

    return(nfa2.startState);

    //print_transition_list(nfa1.transitionPointer, nfa2.startState, nfa2.finalState);
}