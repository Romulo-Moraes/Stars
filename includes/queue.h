#include "global-includes.h"
#include "utilities.h"

#ifndef QUEUE
#define QUEUE

typedef struct{
    unsigned short queueSz;
    StarSetup *queue;
    StarSetup *tail;
} QueueHead;

#endif