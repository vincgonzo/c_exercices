#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <time.h> 
#include <math.h> 
#include <ctype.h> 

#define NAME_MAX_SIZE 50

typedef struct WEAPON{
    char name[NAME_MAX_SIZE];
    int force;
}Weapon;

typedef enum Class {
    WARRIOR, WIZARD, NINJA, THIEF
}Class;

typedef struct HERO{
    char name[NAME_MAX_SIZE];
    int pv;
    Class class;
    Weapon weapon;
}Hero;

// declarations



int main()
{
   
   
    return 0;
}