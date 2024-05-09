#include "queue.h"
#include "heap_usage.h"
#include <stdbool.h>
#define ARRAY_SIZE 1000

struct Queue{
    Element data[ARRAY_SIZE];
    int front;
    int size;
};

Queue *createQueue(){
    Queue* q = (Queue *)myalloc(sizeof(Queue));
    q->front = 0;
    q->size = 0;
    return q;
}

bool enqueue(Queue *q, Element e){
    if(q->size == ARRAY_SIZE) return false;
    q->size++;
    int rear = (q->front + q->size - 1)%ARRAY_SIZE;
    q->data[rear] = e;    
    return true;
}

bool dequeue(Queue *q){
    if(q->size == 0) return false;
    q->front++;
    q->size--;
    if(q->front == ARRAY_SIZE)q->front = 0;
    return true;
}

Element *front(Queue *q){
    return q->data+q->front;
}

int size(Queue *q){
    return q->size;
}

bool isEmpty(Queue *q){
    if(q->size == 0) return true;
    else return false;
}

void destroyQueue(Queue *q){
    myfree(q);
}