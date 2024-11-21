#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <string>
#include <iostream>

class Weapon 
{
    public:

    Weapon();
    Weapon(std::string name, int hurt);
    Weapon(Weapon const& wp);
    ~Weapon();

    int getForce() const;
    std::string getWName() const;
    void change(std::string name, int hurt);
    void display(std::ostream &stream) const;
    
    private: 

    std::string m_name;
    int m_hurt;
};

std::ostream &operator<<(std::ostream &stream, const Weapon &weapon);

#endif // DEF_WEAPON
