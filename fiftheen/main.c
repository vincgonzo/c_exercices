#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

void displayArray(char array[], int length){
    for (size_t i = 0; i < length; i++)
        printf(" %c", *(array + i));
}


int main()
{
    const int VALEUR_MIN = 'A', VALEUR_MAX = 'Z', LENGTH = 1000;
    srand(time(NULL));
    char arr[27];
    int intArr[27];
    int i;

    for(i=0; i<26; i++)
    {
        arr[i] = 'A'+i;
        intArr[i] = 0;
    }

    // generation aleatoire d’une lettre majuscule
    char tabLettres[LENGTH];
    for(size_t i = 0; i < LENGTH; i++){
        char lettre = (char)((rand() % (VALEUR_MAX-VALEUR_MIN+1)) + VALEUR_MIN);
        tabLettres[i] = lettre;
    }
    displayArray(tabLettres, LENGTH);
    printf("\n ========= \n");
    for (size_t i = 0; i < LENGTH; i++)
        for (size_t j = 0; j < 27; j++)
            if(arr[j] == tabLettres[i])
                intArr[j]++;
    
    for (size_t i = 0; i < 27; i++)
    {
        printf("{ %c : %d } ", arr[i], intArr[i]);
    }
    
    return 0;
}
