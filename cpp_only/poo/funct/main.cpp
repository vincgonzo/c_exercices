#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "./fill.h"

#define VECTOR1_LEN 100
#define VECTOR2_LEN 50

using namespace std;

void display_vect(vector<int> v, vector<int>::iterator i);

int main ()
{
    srand(time(0)); // init randomness of values

    vector<int> num(VECTOR1_LEN), num2(VECTOR2_LEN);;
    vector<int>::iterator it;
    Fillin fill(0);

    for(int i=0; i< VECTOR1_LEN;i++){
        num[i] = rand() % 10;
    }
    for(int i=0; i< VECTOR2_LEN;i++){
        num2[i] = rand() % (VECTOR1_LEN * 100);
    }

    generate(num.begin(), num.begin() + 20, fill);
    generate(num.end()-6, num.end(), fill);

    int how_much_fives = count(num.begin(), num.end(), 5); // functor to determine number of 5 in container

    display_vect(num, it);
    cout << "\nAnd for this vector number of five is <" << how_much_fives << "> " << endl;
    
    display_vect(num2, it);
    auto min_it = min_element(num2.begin(), num2.end());
    auto max_it = max_element(num2.begin(), num2.end());

    if(min_it != num2.end())
        cout << "\n\tmin element <" << *min_it << "> " << endl;

    if(max_it != num2.end())
        cout << "\n\tmax element <" << *max_it << "> " << endl;

    return 0;
}

void display_vect(vector<int> v, vector<int>::iterator i){
    for(i = v.begin(); i != v.end(); ++i){
        int index = distance(v.begin(), i);
        cout << " value[" << index << "] : " << *i << " -";
    }
}
