#ifndef __MEDIA_H__
#define __MEDIA_H__

#include <stdio.h>

typedef enum type_media {
    TYPE_BOOK, TYPE_GAMES, TYPE_MOVIE
}TYPE_MEDIA;

typedef struct media
{
    char title[TITLE_MAX_SIZE];
    char author[TITLE_MAX_SIZE / 2];
    TYPE_MEDIA type_media;
    int nbr;
}Media;

char* getTypeName(TYPE_MEDIA type_media){
    switch (type_media)
    {
        case TYPE_GAMES: 
            return "game";
            break;
        case TYPE_MOVIE:
            return "movie";
            break;
        default:
            return "book";
            break;
    }
}

void displayMedia(Media media){
    char* type_name = getTypeName(media.type_media);
    printf("\t{ Media title : %s - author(s) : %s - type : %s - dispo : %d }\n", media.title, media.author, type_name, media.nbr);
}

#endif