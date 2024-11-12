#include "Personnage.hpp" 

#include <string>
#include <iostream>

using namespace std;

Personnage::Personnage(): m_name("connu"), m_manaa(0), m_life(20) {}
 
Personnage::Personnage(string name, int manaa, int life, Weapon weapon){
     this->m_name = name;
     this->m_manaa = manaa;
     this->m_life = life;
     this->m_weapon = weapon;
} 

Personnage::~Personnage(){
     // nothing for now.
}


int Personnage::bim() const{
    return this->m_weapon.getForce();
}

string Personnage::myName() const{
    return this->m_name;
}

int Personnage::myLife() const{
    return this->m_life;
}

void Personnage::getHurt(int nbHurt) {
    this->m_life -= nbHurt;
    if(!isAlive()) cout << this->myName() << " is dead." << endl;
}

void Personnage::displayWeaponUse() const {
    cout << "P <" << myName() << "> use weapon v" << endl;
    this->m_weapon.displayAttr();
}

void Personnage::attack(Personnage &target){
    cout << "Character " << myName() << " attack " << target.myName() << "." << endl;        
    target.getHurt(bim());
    cout << "Life of " << target.myName() << " is now " << target.myLife() << "." << endl;
}

void Personnage::getLife(int qtLife){
     this->m_life += qtLife;
}

void Personnage::changeWeapon(Weapon weapon){
     this->m_weapon = weapon;
}

bool Personnage::isAlive() const{
     if( myLife() <= 0)
         return false;
     return true; 
}

