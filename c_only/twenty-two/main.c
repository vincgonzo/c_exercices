#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void convertAsMaj(int size, char *array, int cnst){
   int index = 0;
   while (*(array + index) != '\0' && index <= size)
   {
        if(*(array + index) >= 'a' && *(array + index) <= 'z')
            *(array + index) += cnst;
        index++;
   }
   
}

void getIdInfos(int size, char *info, int cnst){
    if( fgets(info, size, stdin) == NULL)
        perror("Error during input text.\n");
    fflush(stdin);
    convertAsMaj(size, info, cnst);
}

int main() {
    const int SIZE = 100;
    const int MIN_MAJ_DIFF = 'A' - 'a';
    char input[SIZE + 1];
    
    printf("Ecrire un texte:\n");
    getIdInfos(SIZE, input, MIN_MAJ_DIFF);
    printf("Donnez en majscule %s", input);

    return 0;
}