#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef enum { LUN, MAR, MER, JEU, VEN, SAM, DIM } JOURS_NOMS;
void printfNomJour(int j, char *s);

int main()
{
    int valeurJour;
    char nom_jour[10];
    printf("Quelle jour de la semaine ?\n");

    do
    {
        printf("Donnez le jour de la semaine dont vous voulez le nom :");
        scanf("%d", &valeurJour);
        printf("value enter is : %d\n", valeurJour);
        fflush(stdin);
        if (valeurJour > 6)
            printf ("Impossible de trouver un nom de jour pour une valeur au dessus de 6 !");
    }while (valeurJour < 0 && valeurJour > 6);
    printfNomJour(valeurJour, nom_jour);
    
    printf("le nom du jour est : %s\n", nom_jour);
    return 0;
}

void printfNomJour(int j, char *s){
    if(j < 0 || j > 6)
        perror("Incorrect Number for day.\n");
    switch (j)
    {
        case LUN: strcpy(s, "Lundi"); break;
        case MAR: strcpy(s, "Mardi"); break;
        case MER: strcpy(s, "Mercredi"); break;
        case JEU: strcpy(s, "Jeudi"); break;
        case VEN: strcpy(s, "Vendredi"); break;
        case SAM: strcpy(s, "Samedi"); break;
        case DIM: strcpy(s, "Dimanche"); break;
        default: strcpy(s, "noDay"); break;
    }        
}