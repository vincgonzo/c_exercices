#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool nbrIsInteger(float r);
float racineCarreNbr(int nbr);

int main()
{
    int userEntry;
    float result;
    bool reponse;
    printf("Entrez un nombre entier : ");

    scanf("%d", &userEntry);
    fflush(stdin);

    result = racineCarreNbr(userEntry);
    reponse = nbrIsInteger(result);
    
    if(reponse)
        printf("%d est un carré parfait (%.fx%.f).\n", userEntry, result, result);
    else
        printf("Le nombre %d n'est pas un carré parfait.\n", userEntry);

    return 0;
}

float racineCarreNbr(int nbr){
    return (float) sqrt(nbr);
}

bool nbrIsInteger(float r){
    return roundf(r) == r;
}