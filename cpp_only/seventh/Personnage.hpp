#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Personnage 
{
    public:

    void getHurt(int nbHurt) {
        this->m_life -= nbHurt;
        if(!isAlive()) cout << this->myName() << " is dead." << endl;
    }

    int bim(){
        return this->m_hurtWeapon;
    }
    
    string myName(){
        return this->m_name;
    }

    int myLife(){
        return this->m_life;
    }

    void attack(Personnage &target){
        cout << "Character " << myName() << " attack " << target.myName() << "." << endl;        
        target.getHurt(bim());
	cout << "Life of " << target.myName() << " is now " << target.myLife() << "." << endl;
    }

    void getLife(int qtLife){
        this->m_life += qtLife;
    }

    void changeWeapon(string nameWeapon, int hurtWeapon){
        this->m_nameWeapon = nameWeapon;
        this->m_hurtWeapon = hurtWeapon;
    }

    bool isAlive(){
        if( myLife() <= 0)
            return false;
        return true; 
    }

    Personnage(string name, int manaa, int life, string wName, int wHurt){
        this->m_name = name;
        this->m_manaa = manaa;
        this->m_life = life;
        this->m_nameWeapon = wName;
        this->m_hurtWeapon = wHurt;
    } 

    private: 

    int m_life;
    string m_name;
    int m_manaa;
    string m_nameWeapon;
    int m_hurtWeapon;
};

#endif // DEFINITIONS_H_INCLUDED
