#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increment(){
    for(int i = 0; i < 100000;i++){
        std::lock_guard<std::mutex> lock(mtx);
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

    std::cout << "Final counter value <" << counter << "> " << std::endl; //when mutex implemented they're is no problem anymore 
    return 0;
}

