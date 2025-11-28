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

typedef struct {
    hightScore *scores;
    size_t size;
    size_t capacity;
} DHSArray;

void initArray(DHSArray* , size_t );
void freeArray(DHSArray* );
void resizeArray(DHSArray* , size_t );
void addElement(DHSArray* , const char* , long );
int compareScores(const void *, const void *);
void removeElement(DHSArray* , size_t );
void displayHighScore(DHSArray* , const int);
void updateFiles(DHSArray* arr, const char* filename, const char* countfile);

int main()
{
    DHSArray scores;
    const char *highscorefilename = "HighScore.txt", *countfilename = "count.txt";
    char name[TAILLE_MAX_NOM];
    long score;
    FILE* pt_file = fopen(highscorefilename, "r+");
    // this file ref the number of entry into the file
    FILE* count_file = fopen(countfilename, "r+");
    int numberRead = 0;

    initArray(&scores, 10);
    
    if (count_file == NULL) {
        // File does not exist, initialize number to 0
        perror("File not found. Initializing number to 0.");

        count_file = fopen("count.txt", "w+");
        fprintf(count_file, "%d\n", numberRead);
        fclose(count_file);
    } else {
        // File exists, read the number from the file
        if (fscanf(count_file, "%d", &numberRead) != 1) {
            perror("Error reading number from file");
            fclose(count_file);
            return 1;
        }
        // Close the file after reading
        fclose(count_file);
    }
    
    if (pt_file == NULL) {
        // File does not exist, initialize number to 0
        perror("File not found. No High Scores saved.");
    }

    
    while (fscanf(pt_file, "%s %li", name, &score) == 2) {
        addElement(&scores, name, score);
    }

    // Close the file
    fclose(pt_file);

    // addElement(&scores, "Erol", 45893);
    // updateFiles(&scores, highscorefilename, countfilename);

    // Print the read high scores
    displayHighScore(&scores, numberRead);
    
    // free all the memory at the end
    freeArray(&scores);

    return 0;
}

// Initialize the dynamic array
void initArray(DHSArray* arr, size_t initialCapacity) {
    arr->scores = (hightScore *)malloc(initialCapacity * sizeof(hightScore));
    arr->size = 0;
    arr->capacity = initialCapacity;
}

void resizeArray(DHSArray* arr, size_t newCapacity) {
    arr->scores = (hightScore* )realloc(arr->scores, newCapacity * sizeof(hightScore));
    arr->capacity = newCapacity;
}

// Add an element to the dynamic array
void addElement(DHSArray* arr, const char *name, long score) {              
    if (arr->size == arr->capacity) {
        resizeArray(arr, arr->capacity * 2); // Double the capacity if full
    }
    strncpy(arr->scores[arr->size].name, name, TAILLE_MAX_NOM); // copy on the limit bounded by 3 params
    arr->scores[arr->size].score = score;
    arr->size++;
    qsort(arr->scores, arr->size, sizeof(hightScore), compareScores);
}

int compareScores(const void *a, const void *b) {
    hightScore *scoreA = (hightScore *)a;
    hightScore *scoreB = (hightScore *)b;
    return (scoreA->score - scoreB->score);
}

void freeArray(DHSArray* arr) {
    free(arr->scores);
    arr->scores = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void updateFiles(DHSArray* arr, const char* filename, const char* countfile) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening high score file for writing");
        return;
    }
    for (size_t i = 0; i < arr->size; i++) {
        fprintf(file, "%s %ld\n", arr->scores[i].name, arr->scores[i].score);
    }
    fclose(file);
    FILE* count = fopen(countfile, "w");
    if (count == NULL) {
        perror("Error opening count file for writing");
        return;
    }

    // Write the incremented number back to the file
    fprintf(count, "%d\n", arr->size);

    // Close the file after writing
    fclose(count);
}

void removeElement(DHSArray* arr, size_t index) {
    if (index >= arr->size) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    for (size_t i = index; i < arr->size - 1; i++) {
        arr->scores[i] = arr->scores[i + 1];
    }
    arr->size--;
    qsort(arr->scores, arr->size, sizeof(hightScore), compareScores);
}

void displayHighScore(DHSArray* scores, const int size){
    if(scores->size != size)
        perror("Error on capacity of struct compare to file count result");
    printf("        High Scores         \n");
    printf("   Number | Name  |  Score  \n");
    printf("----------------------------\n");
    for (size_t i = 0; i < size; i++)
    {
        printf(" %d    | %s |  %li \n", i + 1, scores->scores[i].name, scores->scores[i].score);
    }
    printf("----------------------------\n");
}