#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // constantes
    const int TAILLE_MAX = 100;
    const int MIN_TO_MAJ = 'A' - 'a';
    int nbrChar = 0, nbrMot = 0;

    // variables
    char message[TAILLE_MAX+1];
    int taille_message = 0;

    // Lecture saisie utilisateur
    printf("Ecrire un message: ");
    if(fgets(message, TAILLE_MAX, stdin) == NULL)
        return -1;

    // on retire le \n en fin de chaine
    taille_message = strlen(message) -1;
    // redimensionnement de la variable en insérant le \0
    message[taille_message] = '\0';

    for(int i=0; i<taille_message; i++)
    {
        // recherche des espaces
        if(message[i] >= 'a' && message[i] <= 'z' && i == 0)
            nbrMot++;
        if(message[i] == ' ' && message[i - 1] != ' ')
            nbrMot++;
        if(message[i] >= 'a' && message[i] <= 'z')
            nbrChar++;
    }

    // Affichage du resultat
    printf("Cette chaine contient %d characters et %d mot(s).", nbrChar, nbrMot);

    return 0;
}

