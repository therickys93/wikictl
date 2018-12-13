#include <wikictl_parsing.h>
#include <string.h>
#include <getopt.h>

// not working
// to be fixed
void parsing_parameters(int argc, char *argv[], const char *optString, struct option *long_options, parameters_t *params)
{
    int cmd_int = 0;
    int option_index = 0;

    while ((cmd_int = getopt_long(argc, argv, optString, long_options, &option_index)) != -1) {
        switch (cmd_int)
        {
            case 'H':
                strcpy(params->url, optarg);
                break;
            case 'P':
                strcpy(params->port, optarg);
                break;
            case 'h':
                params->show_help = 1;
                break;
            default:
                break;
        }
    }

}