#include "./../includes/queue.h"

static QueueNode* allocateQueueNode(){
    QueueNode *starSetup;

    starSetup = (QueueNode*) malloc(sizeof(QueueNode));

    return starSetup;
}

QueueHead createQueue(unsigned short maxSz){
    QueueHead head = (QueueHead){
        .maxSz = maxSz,
        .queueSz = 0,
        .queue = NULL,
        .tail = NULL
    };

    return head;
}

EnqueueStatus enqueue(QueueHead *queue, StarSetup value){
    QueueNode *newQueueNode;

    // Check if the queue can store more one node
    if(queue->queueSz + 1 > queue->maxSz){
        return QUEUE_FULL;
    }

    // Allocate new queue node
    newQueueNode = allocateQueueNode();

    // Copy data to the node
    memcpy(&newQueueNode->setup, &value, sizeof(StarSetup));
    newQueueNode->next = NULL;

    // Insert into queue
    if(queue->queue != NULL){
        queue->tail->next = newQueueNode;
        queue->tail = newQueueNode;
    }else{
        queue->queue = newQueueNode;
        queue->tail = newQueueNode;
    }

    queue->queueSz += 1;

    return ENQUEUE_FINE;
}

void dequeue(QueueHead *queue){
    QueueNode *nodeToDelete;

    if(queue->queueSz > 0){
        nodeToDelete = queue->queue;
        queue->queue = nodeToDelete->next;

        free(nodeToDelete);

        queue->queueSz--;
    }
}

StarSetup peekQueue(QueueHead *queue){
    return queue->queue->setup;
}

void truncateQueue(QueueHead *queue){
    QueueNode *x, *y;

    x = queue->queue;
    y = x->next;

    while(y){
        free(x);
        x = y;

        y = y->next;
    }

    if(x){
        free(x);
    }

    queue->queue = NULL;
    queue->tail = NULL;
    queue->queueSz = 0;
}

void updateMaxQueueCapacity(QueueHead *queue, unsigned short newMaxSz){
    queue->maxSz = newMaxSz;
}