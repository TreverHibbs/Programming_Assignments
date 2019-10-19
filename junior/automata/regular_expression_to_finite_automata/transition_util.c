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

    if(finalState == transition->state1){
        printf("F (q%i,%c)",transition->state1,symbol);
    }else if(startState == transition->state1){
        printf("S (q%i,%c)-->q%i",transition->state1,symbol,transition->state2);
    }else{
        printf("(q%i,%c)-->q%i",transition->state1,symbol,transition->state2);
    }   
    print_transition_list(transition->nextTransitionPointer, startState, finalState);
    return;
}