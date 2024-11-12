#include "Personnage.hpp" 

#include <string>
#include <iostream>

using namespace std;

Personnage::Personnage(): m_name("connu"), m_manaa(0), m_life(20) {}
 
Personnage::Personnage(string name, int manaa, int life, string wName, int wHurt){
     this->m_name = name;
     this->m_manaa = manaa;
     this->m_life = life;
     this->m_nameWeapon = wName;
     this->m_hurtWeapon = wHurt;
} 

void Personnage::getHurt(int nbHurt) {
    this->m_life -= nbHurt;
    if(!isAlive()) cout << this->myName() << " is dead." << endl;
}

int Personnage::bim(){
    return this->m_hurtWeapon;
}

string Personnage::myName(){
    return this->m_name;
}

int Personnage::myLife(){
    return this->m_life;
}

void Personnage::attack(Personnage &target){
    cout << "Character " << myName() << " attack " << target.myName() << "." << endl;        
    target.getHurt(bim());
    cout << "Life of " << target.myName() << " is now " << target.myLife() << "." << endl;
}

void Personnage::getLife(int qtLife){
     this->m_life += qtLife;
}

void Personnage::changeWeapon(string nameWeapon, int hurtWeapon){
     this->m_nameWeapon = nameWeapon;
     this->m_hurtWeapon = hurtWeapon;
}

bool Personnage::isAlive(){
     if( myLife() <= 0)
         return false;
     return true; 
}

