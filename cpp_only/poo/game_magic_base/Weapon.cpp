#include "Weapon.hpp"

#include <string>
#include <iostream>

using namespace std;

Weapon::Weapon(){}
Weapon::Weapon(std::string name, int hurt): m_name(name), m_hurt(hurt){

}
Weapon::Weapon(Weapon const &weapon){
   this->m_name = weapon.getWName();
   this->m_hurt = weapon.getForce();
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

void Weapon::display(ostream &stream) const{
   stream << "Weapon use  <" << this->getWName() << "> - force <" << this->getForce() << ">";
}

// Overload the << operator
std::ostream &operator<<(std::ostream &stream, const Weapon  &weapon) {
    weapon.display(stream);

    return stream;
}
