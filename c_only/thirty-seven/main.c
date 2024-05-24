#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <time.h> 
#include <math.h> 
#include <ctype.h> 

#define LIMIT_CHAR_ARRAY 50
#define REPO_MAX_SIZE 2

typedef struct PERSONN {
    char name[LIMIT_CHAR_ARRAY];
    char nbr[LIMIT_CHAR_ARRAY];
}Person;


// declarations
void displayPerson(Person * pers);
void completeRepository(Person rep[], int nb);

void completePerson(Person* p_pers);
void displayRepository(Person rep[], int nb);
Person* findPerson(Person rep[], int nb, char *nom);

int main()
{
    Person repository[REPO_MAX_SIZE];
    completeRepository(repository, REPO_MAX_SIZE);
    displayRepository(repository, REPO_MAX_SIZE);
    char reponse[10] = {};
    char search_pers[LIMIT_CHAR_ARRAY] = {};

    do
    {
        printf("\nWanna search_pers a Personn ?\n");
        printf("Accepted answer : true / false\n");
        scanf("%s", &reponse);
        if(strcmp(reponse, "true") == 0){
            printf("Please enter Person to search_pers :\n");
            scanf("%s", search_pers);
            findPerson(repository, REPO_MAX_SIZE, search_pers);
        }
    } while (strcmp(reponse, "true") == 0);
    
   
    return 0;
}

void displayPerson(Person * pers){
    printf("%s Nbr : %s -\n", pers->name, pers->nbr);
}

void completeRepository(Person rep[], int nb){
    const int TAILLE_MAX = 50;
    const int MIN_TO_MAJ = 'A' - 'a';
    // variables
    char pers_name[TAILLE_MAX+1], pers_phone_nbr[TAILLE_MAX+1];
    int name_size = 0, phone_nbr_size = 0;
    for (size_t i = 0; i < nb; i++)
        completePerson(&rep[i]);
}

void completePerson(Person* p_pers)
{
	printf("\tName : "); scanf("%s", p_pers->name);
	printf("\tNumber : "); scanf("%s", p_pers->nbr);
}


void displayRepository(Person rep[], int nb){
    for (size_t i = 0; i < nb; i++)
        displayPerson(&rep[i]);
}

Person* findPerson(Person rep[], int nb, char *search_name){
    bool search = false;
    for (size_t i = 0; i < nb; i++)
        if(strcmp(rep[i].name, search_name) == 0){
            displayPerson(&rep[i]);
            search = true;
        }
    if(search == false) printf("No Personn with this name in the Repository\n");
}
