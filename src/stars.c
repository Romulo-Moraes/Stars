#include "./../includes/global-includes.h"
#include "./../includes/configuration.h"
#include "./../includes/arguments.h"
#include "./../includes/colors.h"
#include "./../includes/modes.h"
#include "./../includes/utilities.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    TerminalMeasures measures;
    int starsProportionality;
    Arguments args;
    Color starsColor;
    int lowerBound, upperBound;

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
        } else {
	    endwin();
	    fprintf(stderr, "Unknown color specified!\n");

	    return EXIT_FAILURE;
	}
    }


    if (args.interval.set == ANEMONE_TRUE) {
	if (parseInterval(args.interval.value, &lowerBound, &upperBound) == false) {
	    endwin();
	    fprintf(stderr, "Malformated fixed mode interval\n");

	    return EXIT_FAILURE;
	}
    } else {
	lowerBound = MIN_INTERVAL;
	upperBound = MAX_INTERVAL;
    }

    starsProportionality = parseCustomProportionality(args.proportionality.value);

    if (args.mode.set == ANEMONE_TRUE) {
	if (strcmp(args.mode.value, "fixed") == 0) {
	    fixedMode(starsProportionality, lowerBound, upperBound);
	} else if (strcmp(args.mode.value, "queue") == 0) {
	    queueMode(starsProportionality);
	} else {
	    endwin();
	    fprintf(stderr, "Unknown mode specified\n");

	    return EXIT_FAILURE;
	}
    } else {
	queueMode(starsProportionality);
    }

    endwin();
	
    return EXIT_SUCCESS;
}
