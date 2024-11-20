#include "common.h"


int main(int argc, char **argv) {
    int listenfd, connfd, n;
    struct sockaddr_in servaddr;
    uint8_t buff[MAX_LINES+1];
    uint8_t recvline[MAX_LINES+1];

    // if(argc != 2)
    //     err_n_die("usage %s <server address>", argv[0]);

    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_n_die("Socket error");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERVER_PORT);

    if(bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
        err_n_die("Bind Error");

    if(listen(listenfd, 10) < 0)
        err_n_die("Listen Error.");

    for ( ; ; )
    {
        struct sockaddr_in addr;
        socklen_t addr_len;

        printf("Waiting for connection on port %d \n", SERVER_PORT);
        fflush(stdout);
        connfd = accept(listenfd, (SA *) NULL, NULL);

        memset(recvline, 0, MAX_LINES);

        while ((n = read(connfd, recvline, MAX_LINES-1)) > 0)
        {
            fprintf(stdout, "\n%s\n\n%s", bin2hex(recvline, n), recvline);
            if(recvline[n-1] == '\n') //hacky way of determine end request
                break;
            memset(recvline, 0, MAX_LINES);
        }
        if(n < 0)
            err_n_die("Read error");
        
        //send response to connection
        snprintf((char* ) buff, sizeof(buff), "HTTP/1.0 200 OK\r\n\r\nHello");
        write(connfd, (char* )buff, strlen((char* )buff));
        close(connfd);
    }


    exit(0); //end successfully
}
