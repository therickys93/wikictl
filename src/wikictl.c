#include <wikictl.h>
#include <stdio.h>
#include <wikictl_execute.h>
#include <wikictl_parsing.h>
#include <wikictl_utilities.h>

static parameters_t params;

static const char*    optString = "H:P:h";
static struct option  long_options[] =
{
    {"help", no_argument, (int *)&(params.show_help), 1},
    {0,0,0,0}
};

int main(int argc, char *argv[]) {
    int          rc     = 0;

    // init with default parameters_t
    init_parameters(&params);

    // parsing arguments
    parsing_parameters(argc, argv, optString, long_options, &params);

    // execute commands
    rc = execute(&params);

    return rc;
}