#include "../includes/arguments.h"

#define PROGRAM_NAME "Stars"
#define PROGRAM_VERSION "4.0"
#define PROGRAM_DESCRIPTION "Ascii stars for terminal interfaces"
#define CREATORS "Cypher (romulo.moraes.dev@gmail.com)"

static anemone_struct anemone;

void configureArgumentParser(int argc, char *argv[]){
    initialize_lib(&anemone, PROGRAM_NAME, PROGRAM_VERSION, PROGRAM_DESCRIPTION, CREATORS, NULL, NULL);

    create_optional_argument(&anemone, "--color", "-c", ANEMONE_TRUE, ANEMONE_FALSE);
    create_optional_argument(&anemone, "--proportionality", "-p", ANEMONE_TRUE, ANEMONE_FALSE);
    create_optional_argument(&anemone, "--mode", "-p", ANEMONE_TRUE, ANEMONE_FALSE);
    create_optional_argument(&anemone, "--intervals", "-i", ANEMONE_TRUE, ANEMONE_FALSE);

    compile(&anemone, argc, argv);
}

Arguments getProgramArguments(){
    Arguments arguments = {
	.color = get_optional_argument(anemone, "--color"),
	.proportionality = get_optional_argument(anemone, "--proportionality"),
	.mode = get_optional_argument(anemone, "--mode"),
	.intervals = get_optional_argument(anemone, "--intervals")
    };
   
    return arguments;
}
