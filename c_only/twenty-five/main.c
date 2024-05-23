#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int camelCaseStr(int size, char *array){
    char tmp[size];
    const int DIFF = 'A' - 'a';
    bool maj = false;
    int indexDiff = 0;
    for (size_t i = 0; i < size; i++)
    {
        printf("indexDiff %d\n", indexDiff);
        if(*(array + i) == ' '){
            indexDiff--;
            maj = true;
        }
        printf("value array[i] : %c -- [indexDiff] %c -- [diff + 1] %c // i %d\n", 
        *(array + i), *(array + indexDiff), *(array + i + 1) + DIFF, i);
        tmp[i] = (maj == true)? *(array + i + 1) + DIFF : *(array + i);
        *(array + i) = *(tmp + i);
        indexDiff++;
        printf("String @ this step : %s\n", tmp);
        maj = false;
    }
    printf("Size %d and diff %d -- result %d", size, indexDiff, (size - indexDiff));
    *(array + indexDiff) = '\0';
    return indexDiff;
}

int getTextInfos(int size, char *info){
    if( fgets(info, size, stdin) == NULL)
        return -1;
    fflush(stdin);
    return strlen(info);
}

int main() {
    // exercice
    // change a text with space in it into camelCase string
    const int SIZE = 100;
    int strl, diff;
    char chaine[SIZE + 1];
    
    printf("Entrez une chaine de charactère avec des espaces:\n");
    strl = getTextInfos(SIZE, chaine);
    printf("size before %d", strl);
    printf("la chaine avant modif %s", chaine);
    diff = camelCaseStr(strl, chaine);
    printf("size after %d", diff);
    printf("la chaine apres modif %s", chaine);


    return 0;
}
