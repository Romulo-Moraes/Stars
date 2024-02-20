#ifndef CONFIGURATION_GUARD
#define CONFIGURATION_GUARD

#include "global-includes.h"

void configureNcurses();
void getTerminalMeasures(int *width, int *height);
void configureApplication();

#endif