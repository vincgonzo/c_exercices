#include <iostream>

// Declare the function that is in the shared library
extern "C" {
    int add(int a, int b);  // This is the function from the shared library
}

int main() {
    int result = add(5, 3);  // Calling the function from the shared library
    std::cout << "The result of 5 + 3 is: " << result << std::endl;
    return 0;
}
