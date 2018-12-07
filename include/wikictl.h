#ifndef _WIKICTL_H
#define _WIKICTL_H

typedef struct {
    char url[100];
    char port[5];
    char endpoint[100];
    char http_request[500];
} parameters_t;

#endif