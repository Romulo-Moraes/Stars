#ifndef RENDER
#define RENDER

#include "global-includes.h"
#include "queue.h"

typedef struct{
    unsigned short x;
    unsigned short y;
} _2DPoint;

void printStar(_2DPoint starPosition, char *selectedStar);
void removeStar(QueueHead *qHead);

#endif