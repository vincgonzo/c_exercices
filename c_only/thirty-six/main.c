#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <time.h> 
#include <math.h> 
#include <ctype.h> 

typedef struct {
    char nom[100];
    char prenom[100];
    float moyenne;
}Student;


// declarations
void displayStudent(Student);

int main()
{
    size_t s = 3;
    Student list[3] = { {"Vincent","castanié",14.5}, {"eric","ducastel",09.8}, {"georges","henry",16.2} };


    for (size_t i = 0; i < s; i++)
    {
        if(list[i].moyenne >= 10)
            displayStudent(list[i]);
    }
    

    return 0;
}

void displayStudent(Student student){
    printf("%s %s - average : %f \n", student.nom, student.prenom, student.moyenne);
}