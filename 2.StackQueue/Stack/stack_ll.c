#include "linked_list.h"
#include "stack.h"
#include <stdlib.h>
#include "heap_usage.h"

struct Stack{
    LIST ll;

};


Stack *newStack(){
    Stack* s = (Stack *)myalloc(sizeof(Stack));
    if(s != NULL){
        s->ll = createNewList();
    }
    return s;
}


bool push(Stack *stack, Element element){    
    NODE e = createNewNode(element);
    insertNodeIntoList(e,stack->ll);
    return true;
}

Element *top(Stack *stack){
    NODE t = stack->ll->head;
    if(t == NULL) return NULL;
    else return &(t->data);
} 


bool pop(Stack *stack){
    if(stack->ll->count == 0)return false;
    removeFirstNode(stack->ll);
    return true;
}


bool isEmpty(Stack *stack){
    if(stack->ll->count == 0) return true;
    else return false;
}


void freeStack(Stack *stack){
    destroyList(stack->ll);
    free(stack);
}
