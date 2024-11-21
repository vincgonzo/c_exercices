#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    cout << "What value do you give to pi ?" << endl;
    double piUtilisateur(-1.); 
    cin >> piUtilisateur; 

    cin.ignore();

    cout << "What is your name ?" << endl;
    string nomUtilisateur("NONE"); 
    getline(cin, nomUtilisateur); 
     
    cout << "Your name is " << nomUtilisateur << " and you say pi value is : " << piUtilisateur << "." << endl;

    double a(0), b(0); //declare two vars

    cout << "Calc a^b !" << endl;

    cout << "Give a : ";
    cin >> a;

    cout << "Give b : ";
    cin >> b;

    double const res(pow(a, b)); 

    cout << a << " ^ " << b << " = " << res << endl;

    return 0;
}