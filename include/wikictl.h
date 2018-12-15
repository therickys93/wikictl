#ifndef _WIKICTL_H
#define _WIKICTL_H

#include <stdint.h>

typedef enum {
    HOME,
    RESET,
    ACCENDI,
    SPEGNI,
    APRI,
    CHIUDI,
    STATUS
} Operation;

typedef struct {
    char      url[128];
    char      port[8];
    char      endpoint[128];
    char      http_request[512];
    int       show_help;
    uint8_t   padding[3];
    Operation operation;
    char      key[128];
    int       position;
} parameters_t;

#endif