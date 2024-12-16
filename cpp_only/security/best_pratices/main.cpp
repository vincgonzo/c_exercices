#include <iostream>
#include <memory>
#include <thread>

int counter = 0;

void increment(){
    for(int i = 0; i < 100000;i++){
        ++counter;
    }
}

void noLeak(){
    std::unique_ptr<int[]> ptr(new int[10]); // automatically cleaned
}

int main(){
    noLeak();


    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter value <" << counter << "> " << std::endl; // explected 200000 but result is non-deterministic
    return 0;
}

