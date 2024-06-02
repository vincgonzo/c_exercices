#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct client
{
    char name[TITLE_MAX_SIZE / 2];
    size_t age;
}Client;

void displayClient(Client client){
    printf("\t{ %s - age : %d }\n", client.name, client.age);
}

#endif