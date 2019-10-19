#include"parser.h"

void add_to_end(struct transition *transition1, struct transition *transition2){

    if(transition1->nextTransitionPointer == NULL){
        transition1->nextTransitionPointer == &transition2;
    }else{
        add_to_end(transition1->nextTransitionPointer, transition2);
    }
}