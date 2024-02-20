#include "./../includes/render.h"

void printStar(_2DPoint starPosition, char *selectedStar){
    mvprintw(starPosition.y, starPosition.x, selectedStar);
    refresh();
}

void removeStar(QueueHead *qHead){
    StarSetup starSetup = peekQueue(qHead);

    // WHITE_SPACE is a macro filled with white spaces
    // a piece of those white spaces will be used to overwrite the existing 
    // stars on terminal aimed by the starSetup
    mvaddnstr(starSetup.starPosition.y, starSetup.starPosition.x, WHITE_SPACE, starSetup.starLength);

    // Remove the star from the queue
    dequeue(qHead);
}