#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
#include <sstream>

const size_t MAX_NUM_STRINGS = 1000; 

std::string generateRandomHexString(size_t length) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 15); // Hexadecimal digits (0-F)

    std::stringstream ss;
    for (size_t i = 0; i < length; ++i) {
        ss << std::hex << distrib(gen);
    }
    return ss.str();
}

int main() {
    size_t numStrings;

    // Get input from the user with input validation and buffer overflow protection
    do {
        std::cout << "Enter the desired number of strings (1-" << MAX_NUM_STRINGS << "): ";
        if (!(std::cin >> numStrings) || numStrings < 1 || numStrings > MAX_NUM_STRINGS) {
            std::cin.clear(); // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cerr << "Invalid input. Please enter a number between 1 and " << MAX_NUM_STRINGS << ".\n";
        }
    } while (numStrings < 1 || numStrings > MAX_NUM_STRINGS);

    size_t stringLength = 74;

    std::vector<std::string> hexStrings;
    hexStrings.reserve(numStrings); // Reserve space for efficiency

    for (size_t i = 0; i < numStrings; ++i) {
        hexStrings.push_back(generateRandomHexString(stringLength));
    }

    // Print the vector (optional)
    std::cout << "std::vector<std::string> hexStrings = {" << std::endl;
    for (size_t i = 0; i < hexStrings.size(); ++i) {
        std::cout << "\"" << hexStrings[i] << "\"";
        if (i < hexStrings.size() - 1) {
            std::cout << ",";
        }
        std::cout << std::endl;
    }
    std::cout << "};" << std::endl;

    return 0;
}
