#include "./../includes/modes.h"
#include "./../includes/render.h"
#include "./../includes/fixed.h"
#include "./../includes/utilities.h"
#include "./../includes/configuration.h"

static char *starsArray[] = {STAR1, STAR2, STAR3, STAR4, STAR5, STAR6, STAR7, STAR8, STAR9};
static size_t starsArraySz = sizeof(starsArray) / sizeof(starsArray[0]);

int fixedMode(int starsProportionality, int lowerBound, int upperBound) {
    TerminalMeasures measures;
    unsigned short numberOfStars;
    FixedStar *stars;
    long long timeDifference = 0;
  
    getTerminalMeasures(&measures.width, &measures.height);

    numberOfStars = calculateProportionality(measures, starsProportionality);

    stars = setupStars(starsArray, starsArraySz, numberOfStars, measures, lowerBound, upperBound);

    if (stars == NULL) {
	fprintf(stderr, "Couldn't allocate memory to execute the program!\n");
	return EXIT_FAILURE;
    }

    while (true) {
	if (getch() != EXIT_KEY) {
	    if(checkForTerminalResizes()){
		getTerminalMeasures(&measures.width, &measures.height);
		numberOfStars = calculateProportionality(measures, starsProportionality);
				
		free(stars);
		stars = setupStars(starsArray, starsArraySz, numberOfStars, measures, lowerBound, upperBound);

		clear();
	    }
			
	    for (unsigned short i = 0; i < numberOfStars; i++) {
		int a = stars[i].interval;
		timeDifference = getCurrentTimeInMilliseconds() - stars[i].lastFlip;

		if (timeDifference > stars[i].interval) {
		    stars[i].lastFlip = getCurrentTimeInMilliseconds();
					
		    switch (stars[i].starState) {
		    case STATE_VISIBLE:
			stars[i].starState = STATE_HIDDEN;
			mvaddnstr(stars[i].position.y, stars[i].position.x, WHITE_SPACE, stars[i].starSize);
			break;
		    case STATE_HIDDEN:
			stars[i].starState = STATE_VISIBLE;
			printStar(stars[i].position, stars[i].star);
			break;
		    }
		}
	    }
	} else {
	    break;
	}
    }
	
    return EXIT_SUCCESS;
}

int queueMode(int starsProportionality) {
    _2DPoint starPosition;
    char *randomStar;
    StarSetup newStarSetup;
    TerminalMeasures measures;
    QueueHead starsQueue = createQueue(65);

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

    return EXIT_SUCCESS;
}
