#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STR_READ 256
#define TAILLE_LISTE 5
#define TAILLE_MAX_NOM 10


typedef struct HIGHT_SCORE
{
    char name[TAILLE_MAX_NOM];
    long score;
}hightScore;

void displayHighScore(hightScore array[], const int);

int main()
{
    hightScore scores[TAILLE_LISTE];

    FILE* pt_file = fopen("HighScore.txt", "r+");
    int numberRead = 0;
    
    if (pt_file == NULL) {
        // File does not exist, initialize number to 0
        perror("File not found. Initializing number to 0.");
    }
    
    // Read the file line by line
    while (numberRead < TAILLE_LISTE && fscanf(pt_file, "%s %li", scores[numberRead].name, &scores[numberRead].score) == 2) {
        numberRead++;
    }

    // Close the file
    fclose(pt_file);

    // Print the read high scores
    displayHighScore(scores, TAILLE_LISTE);

    return 0;
}

void displayHighScore(hightScore scores[], const int size){
    printf("        High Scores         \n");
    printf("   Number | Name  |  Score  \n");
    printf("----------------------------\n");
    for (size_t i = 0; i < size; i++)
    {
        printf(" %d    | %s |  %li  \n", i + 1, scores[i].name, scores[i].score);
    }
    printf("----------------------------\n");
}