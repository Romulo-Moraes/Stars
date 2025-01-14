#ifndef UTILITIES 
#define UTILITIES

#include "render.h"
#include "fixed.h"

char *pickRandomStar(char **stars, size_t arraySz);
_2DPoint pickRandom2DPoint(int maxWidth, int maxHeight);
StarSetup setupNewStar(_2DPoint starPosition, unsigned short starLength);
FixedStar* setupStars(char *starsArray[], size_t starsArraySz, unsigned short numberOfStars, TerminalMeasures measures, int lowerBound, int upperBound);
long long getCurrentTimeInMilliseconds();
bool parseInterval(char *intervalBuffer, int *lower, int *upper);

#endif
