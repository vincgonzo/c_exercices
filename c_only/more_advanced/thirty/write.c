#include <stdio.h>

int main() {
    //easy open file example
    FILE *filepointer;
    char content[] = "I can write new content in the file.\n";

    filepointer = fopen("example.txt", "w");

    if(filepointer == NULL){
    printf("Error opening file\n");
    return 1;
    }
    fputs(content, filepointer);    
   
    fclose(filepointer);
    return 0;
}