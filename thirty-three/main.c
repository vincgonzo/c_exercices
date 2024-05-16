#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <time.h> 
#include <ctype.h> 

bool isNumber(char*);

int main()
{
    const int TAILLE_MAX = 100;
    char texte[TAILLE_MAX+1];

    // lecture saisie utilisateur
    printf("Ecrire un nombre: ");
    scanf("%s", texte);

    if(isNumber(texte))
        printf("\tC'est un nombre\n");
    else            
        printf("\tCe n'est pas un nombre\n");

    return 0;
}


bool isNumber(char* text){
    size_t k = 0, one = 0;
    while (text[k] != '\0') {
        if(!isdigit(text[k]))
            if(text[k] == '.' && one == 0)
                one = 1;
            else
                return false;
        printf("Value y[%d] = %c\n", k, text[k]);
        k++;
    }
    return true;
}