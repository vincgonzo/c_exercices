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
    Personnage(std::string name);
    Personnage(std::string name, int life, Weapon const& weapon);
    virtual ~Personnage();
    int bim() const;    
    //TODO another example virtual int bim() const;    
    std::string myName() const;
    int myLife() const;
    void display(std::ostream &stream) const;
    bool isAlive() const;

    void getHurt(int nbHurt);
    virtual void attack(Personnage &target) const;
    void getLife(int qtLife);
    void changeWeapon(Weapon const& weapon);
    Personnage& operator=(Personnage const& copy); 
    
protected: 

    int m_life;
    std::string m_name;
    Weapon *m_weapon;
};

std::ostream &operator<<(std::ostream &stream, const Personnage &pers);

#endif // DEF_PERSONNAGE
