#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <string>
#include <iostream>

class Weapon 
{
    public:

    Weapon();
    Weapon(std::string name, int hurt);
    ~Weapon();

    int getForce() const;
    std::string getWName() const;
    void change(std::string name, int hurt);
    void displayAttr() const;
    
    private: 

    std::string m_name;
    int m_hurt;
};

#endif // DEF_WEAPON
