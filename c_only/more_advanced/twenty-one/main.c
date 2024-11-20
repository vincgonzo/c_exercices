#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getIdInfos(int size, char *info){
    if( fgets(info, size, stdin) != NULL)
        printf("%s\n", info);
    else
        printf("Une erreur est survenue \n");
    fflush(stdin);
}

int main() {
    int NOM = 45, PRENOM = 50, BIRTH = 15, EYESC = 30;
    char nom[NOM], prenom[PRENOM], birthday[BIRTH], colors[EYESC];
    int count = 4;
    
    printf("Donnez les informations suivantes:\n");

    printf("Date de naissance: ");
    getIdInfos(BIRTH, birthday);
    printf("Nom: ");
    getIdInfos(NOM, nom);
    printf("Prenom: ");
    getIdInfos(PRENOM, prenom);
    printf("Couleur des yeux: ");
    getIdInfos(EYESC, colors);

    printf("Vous vous appelez %s %s, vous etes nee le %s et vos yeux sont %s", prenom, nom, birthday, colors);


    return 0;
}