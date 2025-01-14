#include "../includes/arguments.h"
#include <stddef.h>

static anemone_struct anemone;

void configureArgumentParser(int argc, char *argv[]){
    initialize_lib(&anemone, PROGRAM_NAME, PROGRAM_VERSION, PROGRAM_DESCRIPTION, CREATORS, NULL, NULL);

    create_optional_argument(&anemone, "--color", "-c", ANEMONE_TRUE, ANEMONE_FALSE);
    create_optional_argument(&anemone, "--proportionality", "-p", ANEMONE_TRUE, ANEMONE_FALSE);
    create_optional_argument(&anemone, "--mode", "-p", ANEMONE_TRUE, ANEMONE_FALSE);
    create_optional_argument(&anemone, "--interval", "-i", ANEMONE_TRUE, ANEMONE_FALSE);

    compile(&anemone, argc, argv);
}

Arguments getProgramArguments(){
    Arguments arguments = {
	.color = get_optional_argument(anemone, "--color"),
	.proportionality = get_optional_argument(anemone, "--proportionality"),
	.mode = get_optional_argument(anemone, "--mode"),
	.interval = get_optional_argument(anemone, "--interval")
    };
   
    return arguments;
}
