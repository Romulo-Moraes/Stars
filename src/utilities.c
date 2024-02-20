#include "./../includes/utilities.h"

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