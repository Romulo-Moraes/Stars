#ifndef UTILITIES 
#define UTILITIES
#include "render.h"

char *pickRandomStar(char **stars, size_t arraySz);
_2DPoint pickRandom2DPoint(int maxWidth, int maxHeight);
StarSetup setupNewStar(_2DPoint starPosition, unsigned short starLength);
int calculateProportionality(TerminalMeasures measures);

#endif