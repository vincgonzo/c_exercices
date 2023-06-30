#include <stdio.h>
#include <stdlib.h>


int main(){
    float taille;
    int age;
    char initials[2];

    printf("Donnez votre age et votre taille en metres : ");
    scanf("%d %f", &age, &taille);
    fflush(stdin);  //vide le buffer de lecture
    printf("Donnez vos initiales : ");
    scanf("%s", &initials);

    printf("Vous avez %d ans et mesurez %.2f m.\n", age, taille);
    printf("Vos initiales sont ");
    for(int i=0; i< sizeof(initials); i++){
        printf("%c de valeur int %d et code ASCII %x\n", initials[i], (int)initials[i], initials[i]);
    }
    printf("\n");

    return 0;
}


