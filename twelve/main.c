#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

void displayArrayValues(int array[], int n, int dir)
{
    printf((dir == 0 )? "Tableau :": "Inverse: ");
    if(dir == 0)
    	for(int i = 0; i < n;i++){
    		printf(" %d", array[i]);
	    }
    else 
	    for(int i = n - 1; i >= 0;i--){
    		printf(" %d", array[i]);
	    } 
    printf("\n");
}


int main()
{
    int variables[5] = { 80, 78, 13, 44, 34 };
    int length = sizeof(variables) / sizeof(variables[0]);

    displayArrayValues(variables, length, 0);
    displayArrayValues(variables, length, 1);
    return 0;
}
