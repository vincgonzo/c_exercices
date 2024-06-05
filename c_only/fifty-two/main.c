#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>

void* myturn( void* arg ){
    //void pointer allocate memory
    int *intptr = (int*) malloc(sizeof(int));
    *intptr = 5;
    for (size_t i = 0; i < 8; i++)
    {
        sleep(1);
        printf("My turn ! %d %d \n", i, *intptr);
        (*intptr)++;
    }

    return intptr;
}


void yourturn(){
    for (size_t i = 0; i < 3; i++)
    {
        sleep(2);
        printf("Your turn ! %d\n", i);
    }
}

int main(void) {

    pthread_t nthread;
    int* result;

    pthread_create(&nthread, NULL, myturn, NULL);
    // myturn();
    yourturn();
    
    //wait until the thread is done before exit
    pthread_join(nthread, (void *) &result);
    printf("Thread is end with %d\n", *result);
    free(result);
    return 0;
}