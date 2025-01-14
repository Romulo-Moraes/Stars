#include "./../libs/Anemone/public/anemone_ap.h"

#define PROGRAM_NAME "Stars"
#define PROGRAM_VERSION "5.0"
#define PROGRAM_DESCRIPTION "Unicode stars for terminal interfaces"
#define CREATORS "Cypher (romulo.moraes.dev@gmail.com)"


typedef struct {
    anemone_optional_return_value color;
    anemone_optional_return_value proportionality;
    anemone_optional_return_value mode;
    anemone_optional_return_value interval;
} Arguments;

void configureArgumentParser(int argc, char *argv[]);
Arguments getProgramArguments();
