#include "../includes/colors.h"

static Color selectedColor = WHITE;

void initializeColors(){
    init_pair(BLACK, COLOR_BLACK, -1);
    init_pair(BLUE, COLOR_BLUE, -1);
    init_pair(CYAN, COLOR_CYAN, -1);
    init_pair(GREEN, COLOR_GREEN, -1);
    init_pair(MAGENTA, COLOR_MAGENTA, -1);
    init_pair(RED, COLOR_RED, -1);
    init_pair(WHITE, COLOR_WHITE, -1);
    init_pair(YELLOW, COLOR_YELLOW, -1);
}

static void toLowerCase(char *value){
    while(*value){
        *value = tolower(*value);

        value++;
    }
}

Color checkForColorExistence(char *color){
    toLowerCase(color);

    if(strcmp(color, "black") == 0){
        return BLACK;
    } else if(strcmp(color, "blue") == 0) {
        return BLUE;
    } else if(strcmp(color, "cyan") == 0) {
        return CYAN;
    } else if(strcmp(color, "green") == 0) {
        return GREEN;
    } else if(strcmp(color, "magenta") == 0) {
        return MAGENTA;
    } else if(strcmp(color, "red") == 0) {
        return RED;
    } else if(strcmp(color, "white") == 0) {
        return WHITE;
    } else if(strcmp(color, "yellow") == 0) {
        return YELLOW;
    } else {
        return NO_COLOR_MATCH;
    }
}

Color getColor(){
    return selectedColor;
}

void setColor(Color color){
    selectedColor = color;
}