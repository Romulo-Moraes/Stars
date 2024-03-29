#include "./../includes/configuration.h"

static void messageAndExit(char *message){
    puts(message);
    exit(1);
}

static bool isDigit(char *string){
    while(*string){
        if(isdigit(*string) == 0){
            return false;
        }

        string++;
    }

    return true;
}

void configureNcurses(){
    initscr();
    raw();
    noecho();
    start_color();
    use_default_colors();
    curs_set(0);
    
    // Delay to run the main loop based
    // on the getch() function
    timeout(25);
}

void configureApplication(){
    // Set the locale for the program
    setlocale(LC_ALL, "");
    // Initialize the rand seed for random 
    // numbers generation
    srand(time(NULL));
}

int parseCustomProportionality(char *proportionality){
    int customProportionality;

    if(proportionality != NULL){
        if(isDigit(proportionality) == true){
            customProportionality = atoi(proportionality);

            if(customProportionality != 0){
                return customProportionality;
            } else {
                messageAndExit("The proportionality wasn't a positive integer");
            }

            messageAndExit("The proportionality needs to be a positive value");
        } else {
            messageAndExit("The proportionality wasn't a positive integer");
        }
    }
    
    return DEFAULT_PROPORTIONALITY_VALUE;
}

unsigned short calculateProportionality(TerminalMeasures measures, int customProportionality){
    return (measures.width * measures.height) / customProportionality;
}