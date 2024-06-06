#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>

#define BIG 10000000UL

__uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * count_to_big(void *arg){
    for (__uint32_t i = 0; i < BIG; i++){
        pthread_mutex_lock(&lock); // lock to avoid concurrency problems
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(void) {

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, count_to_big, NULL);
    pthread_create(&thread2, NULL, count_to_big, NULL);
    
    //wait until the thread is done before exit
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("End Result is %d\n", counter);
    return 0;
}