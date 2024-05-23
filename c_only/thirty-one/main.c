#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void crypt(size_t , char *);
void decrypt(size_t , char *);
int modify(int , int , int );

int main()
{
    // constantes
    const int TAILLE_MAX = 100;
    const int MIN_TO_MAJ = 'A' - 'a';
    const int CAESER = 3;

    // variables
    char chaine[TAILLE_MAX+1];
    int taille_message = 0;

    // Lecture saisie utilisateur
    printf("Ecrire un message: ");
    if(fgets(chaine, TAILLE_MAX, stdin) == NULL)
        return -1;

    // on retire le \n en fin de chaine
    taille_message = strlen(chaine) -1;
    // redimensionnement de la variable en insérant le \0
    chaine[taille_message] = '\0';
    crypt(CAESER, chaine);
    printf("Encrypted datas : %s\n", chaine);
    
    decrypt(CAESER, chaine);
    printf("Decrypted datas : %s\n", chaine);

    return 0;
}


void crypt(size_t decal, char *str){
    const int MIN = 32;
    const int MAX = 126;
    size_t i = 0;
    while (str[i] != '\0') {
        str[i] = modify(MIN, MAX, str[i]+decal) ;
        i++;
    }
}

void decrypt(size_t decal, char *str){
    crypt(-decal, str);
}


int modify(int min, int max, int nombre)
{
    // printf("value de nombre %d\n", nombre);
    max++;
    const int MAX = (max-min);
    int resultat = nombre - min;
    // Modulo
    resultat = resultat %MAX;

    if(resultat < 0 )
        resultat += MAX;
    resultat += min;

    return resultat;
}