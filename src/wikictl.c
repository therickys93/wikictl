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
}

int main(int argc, char *argv[]) {
    int          rc     = 0;
    parameters_t params;

    // init with default parameters_t
    init_parameters(&params);

    // parsing arguments
    parsing_parameters(argc, *argv, &params);

    // execute commands
    rc = execute(&params);

    return rc;
}