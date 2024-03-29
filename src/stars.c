#include "./../includes/global-includes.h"
#include "./../includes/queue.h"
#include "./../includes/utilities.h"
#include "./../includes/configuration.h"
#include "./../includes/arguments.h"
#include "./../includes/colors.h"


int main(int argc, char *argv[]){
    char *starsArray[] = {STAR1, STAR2, STAR3, STAR4, STAR5, STAR6, STAR7, STAR8, STAR9};
    size_t starsArraySz = sizeof(starsArray) / sizeof(starsArray[0]);
    QueueHead starsQueue = createQueue(65);
    TerminalMeasures measures;
    _2DPoint starPosition;
    char *randomStar;
    StarSetup newStarSetup;
    int starsProportionality;
    Arguments args;
    Color starsColor;

    // Configuring the app
    configureArgumentParser(argc, argv);
    configureApplication();
    configureNcurses();

    args = getProgramArguments();

    initializeColors();

    if(args.color.set == ANEMONE_TRUE) {
        starsColor = checkForColorExistence(args.color.value);

        if(starsColor != NO_COLOR_MATCH) {
            setColor(starsColor);
        }
    }

    starsProportionality = parseCustomProportionality(args.proportionality.value);

    getTerminalMeasures(&measures.width, &measures.height);    

    updateMaxQueueCapacity(&starsQueue, calculateProportionality(measures, starsProportionality));

    // Main loop of the program
    while(true){
        // Run until press any key
        if(getch() != EXIT_KEY){

            if(checkForTerminalResizes()){
                wipeOutTheStars(&starsQueue);
                getTerminalMeasures(&measures.width, &measures.height);
                updateMaxQueueCapacity(&starsQueue, calculateProportionality(measures, starsProportionality));
            }

            // Pick a random point on terminal and a random star
            starPosition = pickRandom2DPoint(measures.width, measures.height);
            randomStar = pickRandomStar(starsArray, starsArraySz);

            // Create a star setup, using the position and the length
            // of the selected star
            newStarSetup = setupNewStar(starPosition, strlen(randomStar));

            // Try to enqueue the new setup
            if(enqueue(&starsQueue, newStarSetup) == QUEUE_FULL){
                
                // If the queue is full, remove the first star
                // from the queue and from the terminal
                removeStar(&starsQueue);

                // Enqueue the new star
                enqueue(&starsQueue, newStarSetup);
            }

            // Print the new star
            printStar(starPosition, randomStar);
        }else{
            break;
        }
    }

    endwin();

    return EXIT_SUCCESS;
}