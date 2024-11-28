#include <iostream>
#include <string>

using namespace std;

const char Numbers[11] = "0123456789";
const char AlphabetUpper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char AlphabetLower[27] = "abcdefghijklmnopqrstuvwxyz";
void BruteForce(int length, string ciphertext,  string tempKey);

string XOR(string data, const char* key)
{
   string xorstring = data; //initialize new variable for our xordata
   for (int i = 0; i < xorstring.length(); i++) { //for loop for scrambling   bits in the string
    xorstring[i] = data[i] ^ key[i]; //scrambling the string/descrambling it
   }
   return xorstring;
 }

 string cipher, plain; //store the ORIGINAL ciphertext and plaintext

 int main()
 {
    plain = "crypto{test}"; //set the plaintext
    cipher = XOR(plain, "1234"); //encrypt it with the xor function

    cout << plain << endl;  //output
    cout << cipher << endl; //output

    cout << "press enter to start bruteforcing!" << endl;
    getchar();

    while (true) //loop for bruteforcing
    {
       static int stringlength = 1; //the keylength starts from 1 and then
       //expands to 2,3,4,5, etc...
       BruteForce(stringlength, cipher, ""); //call the brute force function
       stringlength++; //increment the keylength
    }
    return 0;
}

void BruteForce(int length, string ciphertext,  string tempKey)
{
    static int count = 0; // for counting how many times key was generated
    string decipher, recipher; //for storing new XORed strings.
    if (length == 0) 
    {
       //decrypt the given ciphertext with the random key
       decipher = XOR(ciphertext, tempKey.c_str());
       //encrypt it again with the same key for comparison
       recipher = XOR(decipher, tempKey.c_str());

       cout << decipher << endl; //output

       //compare the two ciphertexts
       if (ciphertext == recipher)
       {
         //....
          cout << "Key found! It was: '" << tempKey << "'" << endl;
          cout << "it took " << count << " iterations to find the key!";
          getchar();
       }
      return;
   }
   count++;
   //generate the keys.
   for (int i = 0; i < 26; i++) {
       std::string appended = tempKey + AlphabetLower[i];
       BruteForce(length - 1, ciphertext, appended);
    }
    for (int i = 0; i < 26; i++) {
       std::string appended = tempKey + AlphabetUpper[i];
       BruteForce(length - 1, ciphertext, appended);
     }
    for (int i = 0; i < 10; i++) {
       std::string appended = tempKey + Numbers[i];
       BruteForce(length - 1, ciphertext, appended);
   }
}
