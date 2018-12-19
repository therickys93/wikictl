#include <wikictl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wikictl_execute.h>
#include <wikictl_help.h>
#include <wikictl_utilities.h>

int execute(parameters_t *params)
{
    struct addrinfo hints, *res;
    int sockfd;
    char buf[10000];

    if(1 == params->show_help){
        show_help();
        return 0;
    }

    if(1 == params->show_version){
        show_version();
        return 0;
    }

    if(RESET == params->operation){
        sprintf(params->endpoint, "/reset/%s", params->key);
        update_http_request(params);
    } else if(ACCENDI == params->operation){
        sprintf(params->endpoint, "/on/%s/%d", params->key, params->position);
        update_http_request(params);
    } else if(SPEGNI == params->operation){
        sprintf(params->endpoint, "/off/%s/%d", params->key, params->position);
        update_http_request(params);
    } else if(APRI == params->operation){
        sprintf(params->endpoint, "/openclose/%s/%d", params->key, params->position);
        update_http_request(params);
    } else if(CHIUDI == params->operation){
        sprintf(params->endpoint, "/openclose/%s/%d", params->key, params->position);
        update_http_request(params);
    } else if(STATUS == params->operation){
        sprintf(params->endpoint, "/status/%s", params->key);
        update_http_request(params);
    } else if(NONE == params->operation){
        return 1;
    }

    memset(&hints, 0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(params->url,params->port, &hints, &res);
    sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    connect(sockfd,res->ai_addr,res->ai_addrlen);
    send(sockfd,params->http_request,strlen(params->http_request),0);
    recv(sockfd,buf,10000,0);
    printf("%s", buf);
    return 0;
}