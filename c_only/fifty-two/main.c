#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>

void* myturn( void* arg){
    for (size_t i = 0; i < 8; i++)
    {
        sleep(1);
        printf("My turn ! %d \n", i);
    }
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

    pthread_create(&nthread, NULL, myturn, NULL);
    // myturn();
    yourturn();
    
    pthread_join(nthread, NULL);
    return 0;
}