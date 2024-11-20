#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool verifySubIsin(int pos, char str1[], char str2[], int length1, int length2){
    if(length1 < length2)
        return false;
    int k = 0, res = 0;
    do
    {
        // printf("Compare %c and %c\n", str1[pos + k], str2[k]);
        if(str1[pos + k] == str2[k])
            res++;k++; 
    } while (k < length2);

    // printf("Res == %d and tststr == %d\n", res, length2);

    return res == length2;
}


int main()
{
    // constantes
    const int TAILLE_MAX = 100;
    const int MIN_TO_MAJ = 'A' - 'a';
    bool substrisin = false;

    // variables
    char chaine1[TAILLE_MAX+1], chaine2[TAILLE_MAX+1];
    int taille_message1 = 0, taille_message2 = 0;

    // Lecture saisie utilisateur
    printf("Ecrire un message: ");
    if(fgets(chaine1, TAILLE_MAX, stdin) == NULL)
        return -1;
    // Lecture saisie utilisateur 2
    printf("Ecrire un deuxième message: ");
    if(fgets(chaine2, TAILLE_MAX, stdin) == NULL)
        return -1;

    // on retire le \n en fin de chaine
    taille_message1 = strlen(chaine1) -1, taille_message2 = strlen(chaine2) -1;
    // redimensionnement de la variable en insérant le \0
    chaine1[taille_message1] = '\0', chaine2[taille_message2] = '\0';

    for(int i=0; i<taille_message1; i++)
    {
      if(chaine1[i] == chaine2[0])
        if(substrisin = verifySubIsin(i, chaine1, chaine2, taille_message1, taille_message2))
            break;
    }

    // Affichage du resultat
    // printf("Ctrl value %d", substrisin);
    // printf("2 chaines %s length(%d) and %s length(%d).\n", chaine1, taille_message1, chaine2, taille_message2);
    if(substrisin)
        printf("\tthe sub chain is in the primer string.\n");
    else
        printf("\tthe sub chain isn't in the string.\n");

    return 0;
}

