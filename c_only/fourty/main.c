#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <time.h> 
#include <math.h> 
#include <ctype.h> 

#define TITLE_MAX_SIZE 256
#define NB_MEDIAS 3
#define NB_CLIENTS 2

#include "client.h"
#include "media.h"


int main()
{
    Media mediatheque[NB_MEDIAS] ={
        { "Programmer pour les Nuls grand format", "Olivier ENGLER et Wallace WANG", TYPE_BOOK, 5 },
        { "Apex legends", "Respawn Entertainment", TYPE_GAMES, 3 },
        { "MATRIX", "Wachowski", TYPE_MOVIE, 2 }
    };
    Client clients[NB_CLIENTS] ={
        { "Arnaud", 33 },
        { "Marc", 23 }
    };

    for (size_t i = 0; i < NB_MEDIAS; i++)
    {
        displayMedia(mediatheque[i]);
    }

    for (size_t i = 0; i < NB_CLIENTS; i++)
    {
        displayClient(clients[i]);
    }
    
    
}