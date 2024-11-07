#include <iostream>

using namespace std;

int main()
{
    // full control pointer declaration & memory assignement
    int *ptr = nullptr;
    ptr = new int;

    *ptr = 16;

    cout << "address of userAge is {" << *ptr << "}" << endl;
    cout << "pointer basic value is {" << ptr << "}" << endl;

    delete ptr;
    ptr = nullptr;
    
    return 0;
}
