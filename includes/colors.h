#include <ctype.h>
#include <ncurses.h>
#include <string.h>

#define BLACK 1
#define BLUE 2
#define CYAN 3
#define GREEN 4
#define MAGENTA 5
#define RED 6
#define WHITE 7
#define YELLOW 8
#define NO_COLOR_MATCH -1

typedef char Color;

void initializeColors();
Color checkForColorExistence(char *color);
void setColor(Color color);
Color getColor();
