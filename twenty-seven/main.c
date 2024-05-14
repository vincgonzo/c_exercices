#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    // constantes
    const int TAILLE_MAX = 100;
    const int MIN_TO_MAJ = 'A' - 'a';
    bool itis = true;

    // variables
    char paninka[TAILLE_MAX+1];
    int taille_message = 0;

    // Lecture saisie utilisateur
    printf("Ecrire un message: ");
    if(fgets(paninka, TAILLE_MAX, stdin) == NULL)
        return -1;


    // on retire le \n en fin de chaine
    taille_message = strlen(paninka) - 1;

    // redimensionnement de la variable en insérant le \0
    paninka[taille_message] = '\0';
    int endofstr = taille_message - 1;

    for(int i=0; i<taille_message; i++)
    {
        //printf("char [%d] = %c and char [%d] = %c", i, paninka[i], taille_message- i, paninka[taille_message - (i+ 1)]);
        if(paninka[i] != paninka[endofstr - i])
            itis = false;
    }
    if(itis)
        printf("Cette chaine de character %s est un panindrome.", paninka);
    else
        printf("Cette chaine de character %s n'est pas un panindrome.", paninka);
    // Affichage du resultat

    return 0;
}

