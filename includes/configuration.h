#ifndef CONFIGURATION_GUARD
#define CONFIGURATION_GUARD

#include "global-includes.h"

#define EXIT_KEY '\n'
#define DEFAULT_PROPORTIONALITY_VALUE 8

void configureNcurses();
void configureApplication();
int parseCustomProportionality(char *proportionality);
unsigned short calculateProportionality(TerminalMeasures measures, int customProportionality);

#endif