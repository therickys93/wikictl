#ifndef _WIKICTL_H
#define _WIKICTL_H

#include <stdint.h>

typedef enum {
    NONE,
    HOME,
    RESET,
    ACCENDI,
    SPEGNI,
    APRI,
    CHIUDI,
    STATUS,
    DOWNLOAD,
    UPLOAD,
    SERVER
} Operation;

typedef struct {
    char      url[128];
    char      port[8];
    char      endpoint[128];
    char      http_request[512];
    int       show_help;
    int       show_version;
    uint8_t   padding[3];
    Operation operation;
    char      key[128];
    int       position;
    char      message[1000];
} parameters_t;

#endif