#ifndef _WIKICTL_H
#define _WIKICTL_H

typedef enum {
    HOME,
    RESET,
    ACCENDI,
    SPEGNI,
    APRI,
    CHIUDI
} Operation;

typedef struct {
    char      url[100];
    char      port[5];
    char      endpoint[100];
    char      http_request[500];
    int       show_help;
    Operation operation;
    char      key[100];
    int       position;
} parameters_t;

#endif