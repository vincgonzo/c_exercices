#include <iostream>

using namespace std;

#include "./definition.h"

int main()
{
    int const array_size = 5;
    vector<int> nbrs(array_size, 4);
    vector<string> names(10, "Unknown");


    display_vector_nbr(nbrs);
    nbrs.push_back(6);
    nbrs.push_back(9);
    display_vector_nbr(nbrs);

    display_vector_str(names);

    return 0;
}


void display_vector_nbr(vector<int> const& vect){
    for(int i(0);i < vect.size();i++){
        cout << "value(" << i << ") : " << vect[i] << "\n" << endl;
    }
    return;
}

void display_vector_str(vector<string> const& vect){
    for(int i(0);i < vect.size();i++){
        cout << "\t - name index(" << i << ") :  " << vect[i] << "\n" << endl;
    }
    return;
}
