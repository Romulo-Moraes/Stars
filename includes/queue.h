#ifndef QUEUE_GUARD
#define QUEUE_GUARD

#include "global-includes.h"


#define ENQUEUE_FINE 1
#define QUEUE_FULL 0

typedef unsigned char EnqueueStatus;


typedef struct _QueueNode{
    StarSetup setup;
    struct _QueueNode *next;
} QueueNode;

typedef struct{
    unsigned short queueSz;
    unsigned short maxSz;
    QueueNode *queue;
    QueueNode *tail;
} QueueHead;

QueueHead createQueue(unsigned short maxSz);
EnqueueStatus enqueue(QueueHead *queue, StarSetup value);
void dequeue(QueueHead *queue);
StarSetup peekQueue(QueueHead *queue);


#endif