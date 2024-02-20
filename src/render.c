#include "./../includes/render.h"

void printStar(_2DPoint starPosition, char *selectedStar){
    mvprintw(starPosition.y, starPosition.x, selectedStar);
    refresh();
}

void removeStar(QueueHead *qHead){
    StarSetup starSetup = peekQueue(qHead);

    mvaddnstr(starSetup.starPosition.y, starSetup.starPosition.x, WHITE_SPACE, starSetup.starLength);
    dequeue(qHead);
}