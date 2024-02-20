#include "./../includes/configuration.h"

void configureNcurses(){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
}

void getTerminalMeasures(int *width, int *height){
    getmaxyx(stdscr, *height, *width);
}

void configureApplication(){
    // Set the locale for the program
    setlocale(LC_ALL, "");
    // Initialize the rand seed for random 
    // numbers generation
    srand(time(NULL));
}