#include <stdio.h>
#include <stdlib.h>


int main(){
    float euros, dollars;
    const float TAUX_CHANGE = 1.20;

    printf("Donnez un montant en euros : ");
    scanf("%f", &euros);

    fflush(stdin);
    dollars = (euros * TAUX_CHANGE);
    printf("Au vu du taux de change %.2f vous avez %.2f $.", TAUX_CHANGE, dollars);

    return 0;

}