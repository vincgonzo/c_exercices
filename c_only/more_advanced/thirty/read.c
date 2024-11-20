#include <stdio.h>

int main() {
    //easy open file example
   FILE *filepointer;
   char content[100];

   filepointer = fopen("example.txt", "r");

   if(filepointer == NULL){
    printf("Error opening file\n");
    return 1;
   }

   while (fgets(content, sizeof(content), filepointer) != NULL)
   {
        printf("%s\n", content);
   }
   fclose(filepointer);
   return 0;
}