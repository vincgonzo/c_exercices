#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <time.h> 
#include <math.h> 
#include <ctype.h> 

#define CITIES_MAX_SIZE 7

typedef struct CITY{
    char name[50];
    long nb_people;
}City;



// declarations
void sortCities(City cities[], int nb);
void displayCities(City cities[], int nb);


int main()
{
    City cities[CITIES_MAX_SIZE] = {{"Beziers", 150000},{"Montpellier",350000},{"Paris", 11500000},{"Pau", 25000},{"Nantes", 800000},{"Strasbourg",750000},{"Lille", 650000}};

    printf("First iteration before sort.\n");
    displayCities(cities, CITIES_MAX_SIZE);
    printf("sorting ...\n");
    sortCities(cities, CITIES_MAX_SIZE);
    printf("Second iteration after sort.\n");
    displayCities(cities, CITIES_MAX_SIZE);
   
    return 0;
}

void sortCities(City cities[], int nb){
    for (size_t i = 0; i < nb - 1; i++)
    {
        for (size_t j = 0; j < nb - i - 1; j++)
        {
            if((j + 1 <= nb) && cities[j].nb_people < cities[j + 1].nb_people){
                City tmp = cities[j + 1];
                cities[j + 1] = cities[j];
                cities[j] = tmp;
            }
        }
    }
}

void displayCities(City cities[], int nb){
    for (size_t i = 0; i < nb; i++)
    {
        printf("%d - %s.\n", i, cities[i].name);
    }   
}