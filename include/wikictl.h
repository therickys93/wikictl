#ifndef _WIKICTL_H
#define _WIKICTL_H

#include <stdint.h>

typedef struct {
    char url[100];
    char port[5];
    char endpoint[100];
    char http_request[500];
    uint8_t show_help;
} parameters_t;

#endif