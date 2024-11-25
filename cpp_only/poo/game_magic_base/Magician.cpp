#include <string>
#include <iostream>
#include "Magician.hpp" 

#define BACK_TO_LIFE 10
#define BURN_MAGIK 20
using namespace std;

Magician::Magician(): Personnage(), m_manaa(20) {}

Magician::Magician(string name, int manaa): Personnage(name), m_manaa(manaa) {}

Magician::~Magician(){}

void Magician::display(ostream &stream) const {
    stream << "Magician : " << m_name << ", Life: " << m_life;
    stream << ", Manaa level <" << m_manaa << ">\n";    
}

void Magician::FireBallAttack() {
    cout << "Magician will burn your ass" << endl;
    //TODO add something here
}

void Magician::restoreLifeMagik(){
    cout << "Magician restore is life" << endl;
    this->getLife(BACK_TO_LIFE);
}

void Magician::attack(Personnage &target) const{
    target.getHurt(BURN_MAGIK);
    cout << "Magician Attack !  " << endl;
}

