#include "./../includes/configuration.h"

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