#include "./../includes/configuration.h"

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

int parseCustomProportionality(int argc, char *argv[]){
    int customProportionality;

    if(argc >= 2){

        if(isDigit(argv[1]) == true){
            customProportionality = atoi(argv[1]);

            if(customProportionality != 0){
                return customProportionality;
            }

            puts("The proportionality needs to be a positive value");
            exit(1);
        }

        puts("Proportionality value was not a positive number");
        exit(1);
    }

    return DEFAULT_PROPORTIONALITY_VALUE;
}

unsigned short calculateProportionality(TerminalMeasures measures, int customProportionality){
    return (measures.width * measures.height) / customProportionality;
}