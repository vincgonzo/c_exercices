#include <iostream>
#include <memory>


void noLeak(){
    std::unique_ptr<int[]> ptr(new int[10]); // automatically cleaned
}

int main(){
    noLeak();
    return 0;
}

