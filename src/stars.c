#include "./../includes/global-includes.h"
#include "./../includes/queue.h"
#include "./../includes/utilities.h"


int main(void){
    char *starsArray[] = {STAR1, STAR2, STAR3, STAR4, STAR5, STAR6, STAR7, STAR8, STAR9};
    size_t starsArraySz = sizeof(starsArray) / sizeof(starsArray[0]);
    QueueHead starsQueue = createQueue(65);
    int width, height;
    _2DPoint starPosition;
    char *randomStar;
    StarSetup newStarSetup;

    srand(time(NULL));
    setlocale(LC_ALL, "");
    
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    getmaxyx(stdscr, height, width);

    timeout(25);

    while(true){
        if(getch() == ERR){
            starPosition = pickRandom2DPoint(width, height);
            randomStar = pickRandomStar(starsArray, starsArraySz);

            newStarSetup = setupNewStar(starPosition, strlen(randomStar));

            if(enqueue(&starsQueue, newStarSetup) == QUEUE_FULL){
                removeStar(&starsQueue);

                enqueue(&starsQueue, newStarSetup);
            }

            printStar(starPosition, randomStar);
        }else{
            break;
        }
    }

    endwin();

    return EXIT_SUCCESS;
}