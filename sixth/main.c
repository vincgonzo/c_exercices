#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool nbrIsInteger(float r);

int main()
{
    float nbrToCompare;
    bool reponse = 0;
    printf("Entrez un nombre float, svp ");

    scanf("%f", &nbrToCompare);
    fflush(stdin);
    printf("Valeur entrer = %.4f\n", nbrToCompare);
    reponse = nbrIsInteger(nbrToCompare);
    
    if(!reponse)
        printf("Ce nombre n'est pas entier.\n");
    else
        printf("Ce nombre est un entier.\n");

    return 0;
}

bool nbrIsInteger(float r){
    return roundf(r) == r;
}