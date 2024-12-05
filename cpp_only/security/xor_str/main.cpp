#include <iostream>
#include <string>

using namespace std;


string XOR(string data, const char* key);

int main(){

    string flag = "CSCBE{Th1s_1s_1_fl4g_Fr3sh}";
    
    const char *key = "af302bc8910";    

    cout << "flag before : <" << flag << "> " << endl;

    string xored = XOR(flag, key);

    cout << "XORed flag  : <" << xored << "> "  << endl; 

    xored = XOR(xored, key);
    cout << "flag return  : <" << xored << "> " << endl;

    return 0;
}

string XOR(string data, const char* key)
{
   string xorstring = data; //initialize new variable for our xordata
   for (int i = 0; i < xorstring.length(); i++) { //for loop for scrambling   bits in the string
    xorstring[i] = data[i] ^ key[i]; //scrambling the string/descrambling it
   }
   return xorstring;
}
