#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>

#define BIG 10000000UL

// error message poped up if standard for atomics not there
#if __STDC_VERSION__ < 201112 || __STDC_NO_ATOMICS__ == 1
#error "Help, atomics is not supported"
#endif

_Atomic __uint64_t atomic_counter = 0;

void counttobig(){
    for (size_t i = 0; i < BIG; i++)
        atomic_counter += i;
}

void* thread_func( void* arg ){
    counttobig();
    return NULL;
}

int main(void) {

    pthread_t thread1, thread2;
    int* result;

    pthread_create(&thread1, NULL, thread_func, NULL);
    pthread_create(&thread2, NULL, thread_func, NULL);
    
    //wait until the thread is done before exit
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("End Result is %d\n", atomic_counter);
    return 0;
}