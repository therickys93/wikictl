#include <wikictl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wikictl_execute.h>

int execute(parameters_t *params)
{
    struct addrinfo hints, *res;
    int sockfd;
    char buf[10000];
    long byte_count;

    memset(&hints, 0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(params->url,params->port, &hints, &res);
    sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    connect(sockfd,res->ai_addr,res->ai_addrlen);
    send(sockfd,params->http_request,strlen(params->http_request),0);
    byte_count = recv(sockfd,buf,10000,0);
    printf("%s", buf);
    return 0;
}