#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STR_READ 256

int main() {
    FILE* pt_file = fopen("test.txt", "r");
    int letter = 0;
    signed char txt[MAX_STR_READ];

    if(pt_file == NULL)
        exit(1);

    // first method
    while((letter = fgetc(pt_file)) != EOF)
        printf("%c", letter);

    printf("\n-------- METHOD 2 ------------\n");
    fseek(pt_file, 0, SEEK_SET); // move reading cursor at beginning of File
    // second method with fgets
    while (fgets(txt, MAX_STR_READ, pt_file) != NULL)
        printf("%s", txt);
    
    // third method possible with fscanf if predefine <format> into file

    fclose(pt_file);

    return 0;
}