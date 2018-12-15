#include <wikictl_utilities.h>
#include <stdio.h>
#include <version.h>

void init_parameters(parameters_t *params)
{
    sprintf(params->port,         "80");
    sprintf(params->url,          "127.0.0.1");
    sprintf(params->endpoint,     "/");
    sprintf(params->http_request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", params->endpoint, params->url);
    sprintf(params->key,          "");
    params->show_help = 0;
    params->operation = NONE;
    params->position  = 0;
}

void update_http_request(parameters_t *params)
{
    sprintf(params->http_request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", params->endpoint, params->url);
}

void show_version()
{
    printf("wikictl version: %d.%d.%d (0xg%x)\n", MAJOR, MINOR, PATCH, COMMIT);
}
