#ifndef QUEUE_H
#define QUEUE_H

#include "element.h"
#include <stdbool.h>

typedef struct Queue Queue;

Queue *createQueue();

bool enqueue(Queue *queue, Element element);

bool dequeue(Queue *queue);

Element *front(Queue *queue);

int size(Queue *queue);

bool isEmpty(Queue *queue);

void destroyQueue(Queue *queue);

#endif