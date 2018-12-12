#include <wikictl.h>
#include <stdio.h>
#include <wikictl_execute.h>
#include <wikictl_parsing.h>

static void init_parameters(parameters_t *params)
{
    sprintf(params->port,         "80");
    sprintf(params->url,          "127.0.0.1");
    sprintf(params->endpoint,     "/");
    sprintf(params->http_request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", params->endpoint, params->url);
    params->show_help = 0;
}

int main(int argc, char **argv) {
    int          rc     = 0;
    parameters_t params;

    // init with default parameters_t
    init_parameters(&params);

    // parsing arguments
    // parsing_parameters(argc, *argv, &params);
    for(int i = 0; i < argc; i++){
        if(strcmp("-H", argv[i]) == 0){
            strcpy(params.url, argv[i + 1]);
        } else if(strcmp("-P", argv[i]) == 0){
            strcpy(params.port, argv[i + 1]);
        } else if(strcmp("-h", argv[i]) == 0){
            params.show_help = 1;
        }
    }

    // execute commands
    rc = execute(&params);

    return rc;
}