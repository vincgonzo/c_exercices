#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_CODE 4
#define TAILLE_SAISIE 4
#define TAILLE_LISTE_COULEURS 5

void afficherCouleurs() {
    char* couleurs[TAILLE_LISTE_COULEURS] = {"Rouge", "Vert", "Bleu", "Jaune", "Orange"};
    
    printf("Couleurs possibles :\n");
    for (int i = 0; i < TAILLE_LISTE_COULEURS; i++) {
        printf("%d. %s\n", i + 1, couleurs[i]);
    }
}

void genererCode(char* code) {
    srand(time(NULL));
    
    for (int i = 0; i < TAILLE_CODE; i++) {
        int id_couleur_rand = rand() % TAILLE_LISTE_COULEURS;
        code[i] = 'A' + id_couleur_rand; // Utilisation de lettres pour représenter les couleurs
    }
}

int verifierSaisie(const char* code, const char* saisie) {
    int couleurs_correctes = 0;
    int positions_correctes = 0;
    
    for (int i = 0; i < TAILLE_CODE; i++) {
        if (saisie[i] == code[i]) {
            positions_correctes++;
        } else {
            for (int j = 0; j < TAILLE_CODE; j++) {
                if (saisie[i] == code[j]) {
                    couleurs_correctes++;
                    break;
                }
            }
        }
    }
    
    printf("Résultat :\nCouleurs correctes : %d\nPositions correctes : %d\n\n", couleurs_correctes, positions_correctes);
    
    if (positions_correctes == TAILLE_CODE) {
        return 1; // Victoire !
    } else {
        return 0;
    }
}

int main() {
    char code[TAILLE_CODE];
    char saisie[TAILLE_SAISIE];
    
    afficherCouleurs();
    genererCode(code);
    
    printf("\nJeu du Mastermind\n");
    printf("Devinez le code en choisissant %d couleurs parmi les %d possibles.\n", TAILLE_CODE, TAILLE_LISTE_COULEURS);
    
    int tentatives = 0;
    int victoire = 0;
    
    while (tentatives < 10) { // Limite de 10 tentatives
        printf("\nTentative n°%d\n", tentatives + 1);
        
        for (int i = 0; i < TAILLE_SAISIE; i++) {
            printf("Couleur %d : ", i + 1);
            scanf(" %c", &saisie[i]);
        }
        
        victoire = verifierSaisie(code, saisie);
        
        if (victoire) {
            printf("Bravo, vous avez trouvé le code !\n");
            break;
        }
        
        tentatives++;
    }
    
    if (!victoire) {
        printf("Dommage, vous n'avez pas trouvé le code en %d tentatives.\n", tentatives);
    }
    
    return 0;
}