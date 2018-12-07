#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wikictl.h>

int main(void) {
    //Stream sockets and rcv()

    struct addrinfo hints, *res;
    int sockfd;
    FILE *file;
    char buf[10000];
    long byte_count;
    parameters_t params;
    char header[500];

    // init with default parameters_t
    sprintf(params.port,     "80");
    sprintf(params.url,      "therickys93.altervista.org");
    sprintf(params.endpoint, "/");
    sprintf(header,          "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", params.endpoint, params.url);

    // parsing arguments

    // execute commands
    memset(&hints, 0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(params.url,params.port, &hints, &res);
    sockfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    printf("Connecting...\n");
    connect(sockfd,res->ai_addr,res->ai_addrlen);
    printf("Connected!\n");
    send(sockfd,header,strlen(header),0);
    printf("GET Sent...\n");
    //all right ! now that we're connected, we can receive some data!
    byte_count = recv(sockfd,buf,10000,0);
    printf("recv()'d %ld bytes of data in buf\n",byte_count);
    file = fopen("response.txt", "w");
    if(file != NULL){
        fprintf(file, "%s", buf);
        fclose(file);
    }
    return 0;
}