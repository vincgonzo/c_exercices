#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 100

int main()
{
    //Allocation de la string
    int taille = TAILLE_MAX;
    char* nom = (char*)malloc(taille * sizeof(char) );

    //lecture saisie
    printf("Quel est votre nom? ");
    if(fgets(nom, TAILLE_MAX, stdin) == NULL)
        return -1;

    // on retire le \n en fin de chaine
    taille = strlen(nom) -1;
    nom[taille] = '\0';

    //Reallocation de la string
    nom = realloc(nom, (taille+1) * sizeof(char));

    //affichage du resultat
    printf("\t-%s\n", nom);
    printf("\t-%d caracteres\n", taille);
    printf("\t-%d octets\n", sizeof(char) * (taille+1));

    //Liberation de la memoire
    free(nom);

    return 0;
}
