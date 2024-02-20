#ifndef RENDER_GUARD
#define RENDER_GUARD

#include "global-includes.h"
#include "queue.h"

void printStar(_2DPoint starPosition, char *selectedStar);
void removeStar(QueueHead *qHead);
StarSetup setupNewStar(_2DPoint starPosition, unsigned short starLength);

#endif