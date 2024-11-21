#include "Personnage.hpp" 

#include <string>
#include <iostream>

using namespace std;

Personnage::Personnage(): m_name("connu"), m_life(20), m_weapon(nullptr) {
    this->m_weapon = new Weapon();
}

Personnage::Personnage(string name): m_name(name), m_life(20), m_weapon(nullptr) {
    this->m_weapon = new Weapon();
}

Personnage::Personnage(Personnage const& personna): m_name(personna.m_name), m_life(personna.m_life) {
     this->m_weapon = new Weapon(*(personna.m_weapon));
}
 
Personnage::Personnage(string name, int life, Weapon const& weapon): m_weapon(nullptr){
     this->m_name = name;
     this->m_life = life;
     this->m_weapon = new Weapon(weapon);
} 

Personnage::~Personnage(){
     delete this->m_weapon;
}


int Personnage::bim() const{
    return this->m_weapon->getForce();
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

void Personnage::display(ostream &stream) const {
    stream << "Character: " << m_name << ", Life: " << m_life;
    stream << ", Weapon: " << *m_weapon << "\n";  // Display weapon obj 
}

void Personnage::attack(Personnage &target) const{
    cout << "Character " << myName() << " attack " << target.myName() << "." << endl;        
    target.getHurt(bim());
    cout << "Life of " << target.myName() << " is now " << target.myLife() << "." << endl;
}

void Personnage::getLife(int qtLife) {
     this->m_life += qtLife;
}

void Personnage::changeWeapon(Weapon const& weapon){
     if(this->m_weapon != nullptr)
         delete this->m_weapon;
     this->m_weapon = new Weapon(weapon);
}

bool Personnage::isAlive() const{
     if( myLife() <= 0)
         return false;
     return true; 
}

Personnage& Personnage::operator=(Personnage const& copy) 
{
    if(this != &copy) // verify is not a copy of the this obj
    {
        m_life = copy.m_life;
	delete m_weapon;
        m_weapon = new Weapon(*(copy.m_weapon));
    }
    return *this; 
}

ostream  &operator<<( ostream &stream, Personnage const &pers){
    pers.display(stream);

    return stream;
}
