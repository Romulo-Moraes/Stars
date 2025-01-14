#ifndef RENDER_GUARD
#define RENDER_GUARD

#include "global-includes.h"
#include "queue.h"

#define UNSET_MEASURE -1

void printStar(_2DPoint starPosition, char *selectedStar);
void removeStar(QueueHead *qHead);
StarSetup setupNewStar(_2DPoint starPosition, unsigned short starLength);
void getTerminalMeasures(int *width, int *height);
bool checkForTerminalResizes();
void wipeOutTheStars(QueueHead *starsQueue);

#endif
