#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 99

// dynamic alloc ex02
void displayArrayCharacterPointer(char*, int);

int main()
{
    int nameSize = 0;
    char* name = malloc(sizeof(char) * MAX_STRING_SIZE);
    printf("value of malloc address %p\n", name);

    do
    {
        printf("Quelle est votre nom ? : ");
        // scanf("%s", &name);
        if(fgets(name, MAX_STRING_SIZE, stdin) == NULL)
            exit(-1);
        nameSize = strlen(name) - 1;
        /* code */
    } while (nameSize == 0 || nameSize > MAX_STRING_SIZE);
    name[nameSize] = '\0';
    displayArrayCharacterPointer(name, MAX_STRING_SIZE);

    name = realloc(name, (nameSize + 1) * sizeof(char));
    printf("value of realloc address %p\n", name);

    displayArrayCharacterPointer(name, nameSize);

    // printf("\t-%s\n", name);
    // printf("\t-%d caracteres\n", nameSize);
    // printf("\t-%d octets\n", sizeof(char) * (nameSize+1));

    // never forget to free memory !
    free(name);
    return 0;
}

void displayArrayCharacterPointer(char* array, int size){
    printf("char = \'");
    for (size_t i = 0; i < size; i++)
        printf("%c", *(array + i));
    printf("\'\n");
}