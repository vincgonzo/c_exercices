#include <string>
#include <iostream>
#include "Magician.hpp" 

#define BACK_TO_LIFE 10
using namespace std;

void Magician::FireBallAttack() {
    cout << "Magician will burn your ass" << endl;
    //TODO add something here
}

void Magician::restoreLifeMagik(){
    cout << "Magician restore is life" << endl;
    this->getLife(BACK_TO_LIFE);
}
