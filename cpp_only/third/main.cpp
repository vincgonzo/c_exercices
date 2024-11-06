#include <iostream>

using namespace std;

#include "./definition.h"

int main()
{
    string const fileName("./examples.txt");
    // write
    ofstream wFile(fileName.c_str(), ios::app); // specify second param to add info @EOF

    if(wFile){
        wFile << "Hello World ! \n" << endl;
    }else{
        cout << "Error during opening of file" << endl;
    }
    wFile.close();

    // read 
    ifstream rFile(fileName.c_str()); // specify second param to add info @EOF

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

