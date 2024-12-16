#include <iostream>
#include <cctype>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <limits>
 
/*
 * Program: Hash Generator
 * Author: Vincent Castanié
 * Date: 16/12/2024
 * Description:
 *   this program as the purpose of helping generate multiple hash for various security reasons 
 *   it is free of use and expendable if requests is asked in the futur.
 *
 *   Version: 1.0
 *   License: MIT (optional)
 */
using namespace std;

#define hexa 16

void generateHashToken(int length, vector<char> &hash);
void display_vect(vector<char> &v, vector<char>::iterator i);
void clearInputBuffer(); 

int main(){
    srand(time(0));
    int hash_len = 0;
    vector<char> hash;
    vector<char>::iterator it;
    std::cout << " _   _           _        ____                           _             \n";
    std::cout << "| | | | __ _ ___| |__    / ___| ___ _ __   ___ _ __ __ _| |_ ___  _ __ \n";
    std::cout << "| |_| |/ _` / __| '_ \\  | |  _ / _ \\ '_ \\ / _ \\ '__/ _` | __/ _ \\| '__|\n";
    std::cout << "|  _  | (_| \\__ \\ | | | | |_| |  __/ | | |  __/ | | (_| | || (_) | |   \n";
    std::cout << "|_| |_|\\__,_|___/_| |_|  \\____|\\___|_| |_|\\___|_|  \\__,_|\\__\\___/|_|   \n";
    std::cout << "  \n";
    

    while (true) {
        cout << "Give the length of the hash you want to generate (0 to quit): ";
        cin >> hash_len;
        
        if (cin.fail() || hash_len <= 0) {
            // Clear the error flag and discard the rest of the input
            clearInputBuffer();

            if (hash_len == 0) {
                cout << "Exiting program." << endl;
                break;
            } else {
                cout << "Invalid input! Please enter a positive integer greater than 0." << endl;
                continue;  // Retry input
            }
        }

        hash.resize(hash_len);
        generateHashToken(hash_len, hash);
        // Display the vector content (optional)
        display_vect(hash, it);
    }

    return 0;
}

void clearInputBuffer() {
    cin.clear(); // Clears any error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the remaining invalid input
}

void generateHashToken(int length, vector<char> &hash){
    for(auto i = 0; i < length; i++){
        int randVal = rand() % hexa;
        if (randVal < 10) {
            hash[i] = '0' + randVal;  // Store numbers '0' to '9'
        } else {
            hash[i] = 'a' + (randVal - 10);  // Store letters 'A' to 'F'
        }
//        cout << "value is :  " << hash[i] << endl;
    }
}
void display_vect(vector<char> &v, vector<char>::iterator i){
    for(i = v.begin(); i != v.end(); ++i){
        int index = distance(v.begin(), i); // if wanna use / display index
        cout << *i;
    }
    cout << endl;
}
