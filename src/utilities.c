#include "./../includes/utilities.h"
#include "./../includes/modes.h"
#include "./../includes/configuration.h"
#include "./../includes/fixed.h"
#include <stdio.h>

char *pickRandomStar(char **stars, size_t arraySz){
    return stars[rand() % arraySz];
}

_2DPoint pickRandom2DPoint(int maxWidth, int maxHeight){
    return (_2DPoint){
	.x = rand() % maxWidth,
	.y = rand() % maxHeight
    };
}

StarSetup setupNewStar(_2DPoint starPosition, unsigned short starLength){
    return (StarSetup){
	.starPosition = starPosition,
	.starLength = starLength
    };
}

FixedStar* setupStars(char *starsArray[], size_t starsArraySz, unsigned short numberOfStars, TerminalMeasures measures, int lowerBound, int upperBound) {
    FixedStar *stars = malloc(sizeof(FixedStar) * numberOfStars);
    int interval;

    if (stars == NULL) {
	return NULL;
    }

    for (unsigned short i = 0; i < numberOfStars; i++) {
	interval = (rand() % (upperBound - lowerBound)) + lowerBound;
	
	stars[i].star = pickRandomStar(starsArray, starsArraySz);
	stars[i].starSize = strlen(stars[i].star);
	stars[i].starState = rand() % 2 == 1 ? STATE_HIDDEN : STATE_VISIBLE;
	stars[i].lastFlip = (getCurrentTimeInMilliseconds() - (rand() % interval));
	stars[i].interval = interval;
	stars[i].position = (_2DPoint) {
	    .x = rand() % measures.width,
	    .y = rand() % measures.height
	};
    }

    return stars;
}

long long getCurrentTimeInMilliseconds() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (long long)(ts.tv_sec) * 1000 + (ts.tv_nsec / 1000000);
}

bool parseInterval(char *intervalBuffer, int *lower, int *upper) {
    int lowerBound, upperBound, pos;

    int read = sscanf(intervalBuffer, "%d-%d%n", &lowerBound, &upperBound, &pos);

    if (read != 2 || intervalBuffer[pos] != '\0' || lowerBound >= upperBound) {
	return false;
    }

    *lower = lowerBound;
    *upper = upperBound;

    return true;
}
