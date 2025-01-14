#include "./../libs/Anemone/public/anemone_ap.h"
#include <stdio.h>


typedef struct {
    anemone_optional_return_value color;
    anemone_optional_return_value proportionality;
    anemone_optional_return_value mode;
    anemone_optional_return_value intervals;
} Arguments;

void configureArgumentParser(int argc, char *argv[]);
Arguments getProgramArguments();
