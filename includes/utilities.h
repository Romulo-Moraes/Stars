#ifndef UTILITIES 
#define UTILITIES
#include "render.h"

typedef struct{
    _2DPoint starPosition;
    unsigned short starLength;
} StarSetup;

char *pickRandomStar(char **stars, size_t arraySz);
_2DPoint pickRandom2DPoint(int maxWidth, int maxHeight);
StarSetup setupNewStar(_2DPoint starPosition, unsigned short starLength);


#endif