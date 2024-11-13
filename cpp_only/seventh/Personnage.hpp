#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include <iostream>
#include "Weapon.hpp" 

class Personnage 
{
    public:

    Personnage();
    Personnage(Personnage const& copy);
    Personnage(std::string name, int manaa, int life, Weapon const& weapon);
    ~Personnage();
    int bim() const;    
    //TODO another example virtual int bim() const;    
    std::string myName() const;
    int myLife() const;
    void display(std::ostream &stream) const;
    bool isAlive() const;

    void getHurt(int nbHurt);
    void attack(Personnage &target);
    void getLife(int qtLife);
    void changeWeapon(Weapon const& weapon);
    Personnage& operator=(Personnage const& copy); 
    
    private: 

    int m_life;
    std::string m_name;
    int m_manaa;
    Weapon *m_weapon;
};

std::ostream &operator<<(std::ostream &stream, const Personnage &pers);

#endif // DEF_PERSONNAGE
