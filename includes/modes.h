#ifndef __MODES_GUARD__
#define __MODES_GUARD__

#define MIN_INTERVAL 800
#define MAX_INTERVAL 1500

int queueMode(int starsProportionality);
int fixedMode(int starsProportionality, int lowerBound, int upperBound);

#endif
