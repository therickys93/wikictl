#include <wikictl_utilities.h>
#include <stdio.h>
#include <string.h>
#include <version.h>

void init_parameters(parameters_t *params)
{
    sprintf(params->port,         "80");
    sprintf(params->url,          "127.0.0.1");
    sprintf(params->endpoint,     "/");
    sprintf(params->http_request, "http://%s%s", params->url, params->endpoint);
    strcpy(params->key,           "");
    params->show_help = 0;
    params->operation = NONE;
    params->position  = -1;
}

void update_http_request(parameters_t *params)
{
    sprintf(params->http_request, "http://%s%s", params->url, params->endpoint);
}

void show_version()
{
    printf("wikictl version: %d.%d.%d (0xg%x)\n", MAJOR, MINOR, PATCH, COMMIT);
}

int read_content_of_file(char *filename, char *content)
{
    FILE *file;
    long fSize = 0;
    size_t result = 0;
    file = fopen(filename, "r");
    if(file != NULL) {
        fseek(file, 0, SEEK_END);
        fSize = ftell(file);
        rewind(file);

        result = fread(content, 1, (size_t)fSize, file);
        if((long)result != (long)fSize){
            return 2;
        }

        fclose(file);
        return 0;
    } else {
        return 1;
    }
}
