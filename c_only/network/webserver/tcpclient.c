#include "common.h"


int main(int argc, char **argv) {
    int sockfd, n;
    int sendbytes;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINES];
    char recvline[MAX_LINES];

    if(argc != 2)
        err_n_die("usage %s <server address>", argv[0]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_n_die("Error creating socket");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);

    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err_n_die("inet_pton error for %s ", argv[1]);

    if(connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
        err_n_die("Error connection.");

    // from now we are connected
    sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
    sendbytes = strlen(sendline);
    
    if(write(sockfd, sendline, sendbytes) != sendbytes)
        err_n_die("Error writing");

    memset(recvline, 0, MAX_LINES);

    while ((n = read(sockfd, recvline, MAX_LINES-1)) > 0)
    {
        printf("%s", recvline);
    }
    if(n < 0)
        err_n_die("Read error");

    exit(0); //end successfully
}
