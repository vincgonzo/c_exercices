#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

void verifyPremier(int value);
int is_prime(int num);
void errorMsg();
void sucessMsg(int value);

void verifyPremier(int value)
{
    int verification = 0;
    if(is_prime(value) != 1)
        errorMsg();
    else
        sucessMsg(value);
}

int is_prime(int num)
{
    if (num <= 1) return 0;
    if (num % 2 == 0 && num > 2) return 0;
    for(int i = 3; i < num / 2; i+= 2)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void errorMsg()
{
    printf("Ce nombre n'est pas premier\n");
}

void sucessMsg(int value)
{
    printf("Ce nombre %d est premier\n", value);
}

int main()
{
    int premier;
    printf("Entrez un nombre entier : ");

    scanf("%d", &premier);
    fflush(stdin);

    verifyPremier(premier);

    return 0;
}
