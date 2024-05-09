#include "element.h"
#include "stack.h"
#include "heap_usage.h"
#include <stdlib.h>

#define STACK_SIZE 1000

struct Stack{
    int top;
    Element data[STACK_SIZE];
};

Stack *newStack(){
    Stack *s = (Stack *)myalloc(sizeof(Stack));
    if(s!= NULL) s->top = -1;
    return s;
}

bool push(Stack *s, Element e){
    if(s->top == STACK_SIZE - 1) return false;
    s->data[++(s->top)] = e;
    return true;
}

Element *top(Stack *s){
    return (s->data)+(s->top);
}

bool pop(Stack *s){
    if(s->top == -1)return false;
    s->top--;
    return true;
}

bool isEmpty(Stack *s){
    if(s->top == -1) return true;
    else return false;
}

void freeStack(Stack *s){
    myfree(s);
    return;
}