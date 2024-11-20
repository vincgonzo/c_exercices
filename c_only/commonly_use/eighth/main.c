#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

void displayCosAndSin(int value);

int main()
{
    int endingPoint;
    printf("Entrez un nombre entier : ");

    scanf("%d", &endingPoint);
    fflush(stdin);

    displayCosAndSin(endingPoint);

    return 0;
}

void displayCosAndSin(int value){
    for(int i=0; i <= value;i++){
	printf("cos(%d) = %f.\n", i, cos(i));
	if(i % 2 == 0)
		printf("sin(%d) = %f.\n", i, sin(i));
    }
}

