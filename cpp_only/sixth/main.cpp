#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
* Little Mystery Word Game
*/
void mangleOut(string *word);

int main()
{
    string mysteryWord, userWord;
    string *mangledWord = nullptr;

    cout << "Enter Secret Word : ";
    cin >> mysteryWord;
    mangledWord = new string(mysteryWord);

    mangleOut(mangledWord);

    cout << "Here is the mangled version of the word < " << *mangledWord << " > " << endl;
    while(userWord != mysteryWord){
        cin.clear();
        cout << "\t give your idea of the answer : ";
        cin >> userWord;
        if(userWord == mysteryWord){
            cout << "Bravo ! you made it !!" << endl;
	}else{
            cout << "Sorry that isn't that. Try again" << endl;
        }
        if (userWord.size() > mysteryWord.size()){
            cout << "Your input is too long to be good" << endl;
        }
    }

    delete mangledWord;
    mangledWord =nullptr;

    return 0;
}

void mangleOut(string *word){
    string melt;
    int pos = 0;
    cout << *word << endl;
    
    while(word->size() != 0){
        pos = rand() % word->size();
        melt += word->at(pos);
        word->erase(pos, 1);   
    }
    *word = melt;
}
