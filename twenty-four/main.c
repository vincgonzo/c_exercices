#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

bool verificationPasswd(int length, char *str){
    if(length < 8)
        return false;
    const int COND_OK[6] = {'A', 'Z', '0', '9', 'a', 'z'};
    bool CTRL_MAJ = false, CTRL_SPE = false, CTRL_NBR = false;
    for (size_t i = 0; i < length; i++)
    {
        if(*(str + i) > COND_OK[0] && *(str + i) < COND_OK[1]) CTRL_MAJ = true;
        if(*(str + i) > COND_OK[2] && *(str + i) < COND_OK[3]) CTRL_NBR = true;
        if(*(str + i) < COND_OK[4] || *(str + i) > COND_OK[5]) CTRL_SPE = true;
    }
    return CTRL_MAJ && CTRL_NBR && CTRL_SPE;
}

void enterPasswd(int size, char *info){
    bool ok = false;
    while(ok == false){
        printf("Rentrez un mdp :\n");
        if( fgets(info, size, stdin) == NULL)
            perror("Error getting the input /!\\\n");
        fflush(stdin);
        ok = verificationPasswd(strlen(info), info);
        if(!ok)
            printf("Error entering password do it again!!\n");
    }
}

int main() {
    const int SIZE = 100;
    int strl, allcomplete;
    char passwd[SIZE + 1], verify[SIZE + 1];
    
    while(allcomplete < 2){
        allcomplete = 0;
        enterPasswd(SIZE, passwd);
        allcomplete++;
        printf("Entrez a nouveau le mdp :\n");
        scanf("%s", verify);
        if(strcmp(passwd, verify) == 0)
            allcomplete++;
    }
    printf("Mot de passe changé");

    return 0;
}