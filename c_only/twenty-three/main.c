#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void reverStr(int length, char *str){
    for (size_t i = 0; i < length / 2; i++)
    {
        char tmp = *(str + i);
        int var = i + 2;
        // printf("valu before %c %c - ", *(str + i), *(str + (length - var)));
        *(str + i) = *(str + (length - var));
        *(str + (length - var)) = tmp;
        // printf("and after %c %c - \n", *(str + i), *(str + (length - var)));
    }
}

int getIdInfos(int size, char *info){
    if( fgets(info, size, stdin) == NULL)
        return -1;
    fflush(stdin);
    return strlen(info);
}

int main() {
    const int SIZE = 100;
    int strl;
    char input[SIZE + 1];
    
    printf("Ecrire un texte:\n");
    strl = getIdInfos(SIZE, input);
    if(strl != -1){
        reverStr(strl, input);
    }else
        return -1;
    printf("Donnez en majscule %s longueur %d", input, strl);

    return 0;
}