#include <wikictl_parsing.h>
#include <string.h>

// not working
// to be fixed
void parsing_parameters(int argc, char *argv, parameters_t *params)
{
    for(int i = 0; i < argc; i++){
        if(strcmp("-H", &argv[i]) == 0){
            strcpy(params->url, &argv[i + 1]);
        } else if(strcmp("-P", &argv[i]) == 0){
            strcpy(params->port, &argv[i + 1]);
        } else if(strcmp("-h", &argv[i]) == 0){
            params->show_help = 1;
        }
    }
}