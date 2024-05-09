#include "queue.h"
#include "heap_usage.h"
#include "linked_list.h"
#include <stdbool.h>


struct Queue{
    LIST ll;
};

Queue *createQueue(){
    Queue* q = (Queue *)myalloc(sizeof(Queue));
    q->ll->count = 0;

    return q;
}

bool enqueue(Queue *q, Element e){
    insertNodeAtEnd(createNewNode(e),q->ll);
    return true;
}

bool dequeue(Queue *q){
    if(q->ll->count == 0) return false;
    removeFirstNode(q->ll);
    return true;
}

Element *front(Queue *q){
    return &(q->ll->head->data);
}

int size(Queue *q){
    return q->ll->count;
}

bool isEmpty(Queue *q){
    if(q->ll->count == 0) return true;
    else return false;
}

void destroyQueue(Queue *q){
    destroyList(q->ll);
    myfree(q);
}