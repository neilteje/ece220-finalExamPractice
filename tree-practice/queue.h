#ifndef QUEUE
#define QUEUE

#include "tree.h"
#define MAXSIZE 500

struct queue {
    node * contents[MAXSIZE];
    int head;
    int tail;
};

void initQueue(queue * inQueue);

void enqueue(queue * inQueue, node * element);

node * dequeue(queue * inQueue);

int isEmpty(queue * inQueue);

int isFull(queue * inQueue);

#endif /*!QUEUE*/
