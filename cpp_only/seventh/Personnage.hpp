#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include "Weapon.hpp" 

class Personnage 
{
    public:

    Personnage();
    Personnage(std::string name, int manaa, int life, Weapon weapon);
    ~Personnage();
    int bim() const;    
    std::string myName() const;
    int myLife() const;
    void displayWeaponUse() const;
    bool isAlive() const;

    void getHurt(int nbHurt);
    void attack(Personnage &target);
    void getLife(int qtLife);
    void changeWeapon(Weapon weapon);
    
    private: 

    int m_life;
    std::string m_name;
    int m_manaa;
    Weapon m_weapon;
};

#endif // DEF_PERSONNAGE
