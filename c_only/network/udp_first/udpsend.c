#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>   // Needed for inet_pton and htons
#include <netinet/in.h> 



int main(int argc, char * argv[]){
    if(argc != 4){
        printf("Usage: %s <peer_ip> <peer_port> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char * peer_ip = argv[1];
    int peer_port = atoi(argv[2]);
    const char * message = argv[3];

    // Need conversion from human readabll <> socket init
    struct sockaddr_in peer_addr;
    memset(&peer_addr, 0, sizeof(peer_addr));  // Zero out the structure
    peer_addr.sin_family = AF_INET;
    peer_addr.sin_port = htons(peer_port);

    if(inet_pton(AF_INET, peer_ip, &(peer_addr.sin_addr)) <= 0){
        perror("Something wrong with ip address");
        return EXIT_FAILURE;
    }

    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);    
    if(udp_socket < 0){
        perror("COuldn't create the socket.");
        return EXIT_FAILURE;
    }

    if(sendto(udp_socket, message, strlen(message) + 1, 0, (struct sockaddr *)&peer_addr, sizeof(peer_addr)) < 0){
        perror("Failed to send the message.");
        close(udp_socket);
        return EXIT_FAILURE;
    }

    printf("Sent \"%s\" to %s:%d\n", message, peer_ip, peer_port);
    close(udp_socket);

    return EXIT_SUCCESS;
}
