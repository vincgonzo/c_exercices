#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int million;
    printf("Le million !!\n");

    printf("How much did you win in a day :");
    scanf("%d", &million);

    printf("Can Say you win about ");
    printfcomma2(million);
    printf("\n");
    return 0;
}

void printfcomma2 (int n) {
    if (n < 1000) {
        printf ("%d", n);
        return;
    }
    printfcomma2 (n/1000);
    printf (" %03d", n%1000);
}