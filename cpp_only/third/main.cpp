#include <iostream>

using namespace std;

#include "./definition.h"

int main()
{
    string const fileName("./examples.txt");
    // write
    ofstream wFile(fileName.c_str(), ios::app); // specify second param to add info @EOF
    int wCursorPos = wFile.tellp(); // to get current cursor pos in w-mode
    
    wFile.seekp(0, ios::end); // set cursor @EOF useless here

    cout << "Size of file : " << wCursorPos << " o.\n" << endl; 
    if(wFile){
        wFile << "Hello World ! \n" << endl;
    }else{
        cout << "Error during opening of file" << endl;
    }
    wFile.close();

    // read 
    ifstream rFile(fileName.c_str()); // specify second param to add info @EOF
    int rCursPos = wFile.tellp(); // to get current cursor pos in r-mode

    rFile.seekg(5, ios::cur); // move the cursor 20 character after is actual position
    if(rFile){
	string line;

        while(getline(rFile, line)){
	    cout << line << endl;
	}
    }else{
        cout << "Error during opening of file" << endl;
    }
    rFile.close();


    return 0;
}

