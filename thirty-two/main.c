#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h> 

void mdpGenerateur(int , char []); 
int generator(int , int);

int main()
{
    const int TAILLE_MAX = 100;
    // variables
    int nbr;
    const int MIN_TO_MAJ = 'A' - 'a';

    // variables
    char chaine[TAILLE_MAX+1];
    memset(chaine, 0, sizeof(chaine));
    srand(time(NULL));
    // int* ptr = &nbr;
    int msg_size = 0;
    msg_size = strlen(chaine) -1;
    // redimensionnement de la variable en insérant le \0
    chaine[msg_size] = '\0';

    // Lecture saisie utilisateur
    printf("What size of password did you want ?  ");
    if (scanf("%d", &nbr) != 1) {
        printf("Error: Invalid input\n");
        exit(1);
    }
    if (nbr >= (TAILLE_MAX - 1)) {
        printf("Error: Input too long.\n");
        exit(1);
    }

    mdpGenerateur(nbr, chaine);
    printf("Password : \t%s\n", chaine);

    return 0;
}

void mdpGenerateur(int x, char y[]){
    const int MIN = 32;
    const int MAX = 126;
    size_t k = 0;
    while (k < x) {
        y[k] = (char) generator(MIN, MAX);
        // printf("Value y[%d] = %c\n", k, y[k]);
        k++;
    }
}


int generator(int min, int max)
{
    return (rand() % (max - min + 1)) + min; 
}