#include "Weapon.hpp"

#include <string>
#include <iostream>

using namespace std;

Weapon::Weapon(){}
Weapon::Weapon(std::string name, int hurt): m_name(name), m_hurt(hurt){

}
Weapon::~Weapon(){
    //nothing for now
}

void Weapon::change(std::string name, int hurt){
     this->m_name = name;
     this->m_hurt = hurt;
}

int Weapon::getForce() const {
    return this->m_hurt;
}

string Weapon::getWName() const {
    return this->m_name;
}

void Weapon::displayAttr() const{
   cout << "Weapon use  <" << this->getWName() << "> - force <" << this->getForce() << ">" << endl;
}


