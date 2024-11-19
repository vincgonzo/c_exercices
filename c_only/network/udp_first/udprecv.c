#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>   // Needed for inet_pton and htons
#include <netinet/in.h> 

int check(int exp, const char *msg);

#define BUFFER_SIZE 1024

int main(int argc, char * argv[]){
    if(argc != 2){
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int my_port = atoi(argv[1]);
    int udp_rx_socket;

    struct sockaddr_in peer_addr;
    struct sockaddr_in my_addr;
    memset(&my_addr, 0, sizeof(my_addr));  // Zero out the structure
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr= INADDR_ANY;
    my_addr.sin_port = htons(my_port);

    char buffer[BUFFER_SIZE];

    if((udp_rx_socket = socket(AF_INET, SOCK_DGRAM, 0)) <= 0){
        perror("Failed to create socket");
        return EXIT_FAILURE;
    }

    //bind the socket to the port
    int res = bind(udp_rx_socket, (struct sockaddr *)&my_addr, sizeof(my_addr));
    check(res, "Could not bind socket to address.");

    socklen_t addr_len = sizeof(peer_addr);
    int bytes_recv = recvfrom(udp_rx_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&peer_addr, &addr_len);
    check(bytes_recv, "Sorry, recvfrom failed.");

    printf("Received a packet from %s:%d - Mesg : %s\n", inet_ntoa(peer_addr.sin_addr), ntohs(peer_addr.sin_port), buffer);

    close(udp_rx_socket); 
    
    return EXIT_SUCCESS;
}

#define SOCKETERROR (-1)
int check(int exp, const char *msg){
    if(exp == SOCKETERROR){
        perror(msg);
        exit(EXIT_FAILURE);
    }
    return exp;
}
