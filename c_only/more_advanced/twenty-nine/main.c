#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void playGame(char *user_entry, int *lifes, const char word_to_find[], char *display, int wordsize) {
    int user_entry_length = 0;
    printf("Donner une lettre in UPPERCASE : ");
 
    if(fgets(user_entry, wordsize, stdin) == NULL)
        return;

    // on retire le \n en fin de chaine
    user_entry_length = strlen(user_entry);
    if (user_entry_length > 0 && user_entry[user_entry_length - 1] == '\n')
        user_entry[user_entry_length - 1] = '\0'; // Remove trailing newline
    
    bool found = false;
    for (int i = 0; i < wordsize; i++) {
        // printf("Cmp letter %c with %c.\n", word_to_find[i], user_entry);
        if (word_to_find[i] == *user_entry) {
            display[i] = *user_entry;
            found = true;
        }
    }
    if (!found && *lifes > 0)
        (*lifes)--;

    printf("le mot mystère est %s.\n", display);
    printf("\t il vous reste %d vies.\n", *lifes);
}

int main() {
    const int SIZE_WORD = 14;
    const char WORD_TO_FIND[] = "PROGRAMMATION";
    char DISPLAY[SIZE_WORD + 1]; // +1 for null terminator
    for (int i = 0; i < SIZE_WORD; i++) DISPLAY[i] = '-';
    DISPLAY[SIZE_WORD] = '\0';

    char userTest[2]; // Array to hold one character and null terminator
    int lifes = 10;

    do {
        playGame(userTest, &lifes, WORD_TO_FIND, DISPLAY, SIZE_WORD);
    } while (lifes > 0 && strcmp(DISPLAY, WORD_TO_FIND) != 0);

    return 0;
}