#ifndef GLOBAL_INCLUDES
#define GLOBAL_INCLUDES

    #include <stdlib.h>
    #include <ncurses.h>
    #include <locale.h>
    #include <time.h>
    #include <string.h>
    #include <unistd.h>

    #include "stars-macros.h"


    typedef struct{
        unsigned short x;
        unsigned short y;
    } _2DPoint;

    typedef struct{
        _2DPoint starPosition;
        unsigned short starLength;
    } StarSetup;

    typedef struct{
        int width;
        int height;
    } TerminalMeasures;

#endif