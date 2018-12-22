#ifndef _WIKICTL_UTILITIES_H
#define _WIKICTL_UTILITIES_H

#include <wikictl.h>

void init_parameters(parameters_t *params);
void update_http_request(parameters_t *params);
void show_version();
int  read_content_of_file(char *filename, char *content);

#endif