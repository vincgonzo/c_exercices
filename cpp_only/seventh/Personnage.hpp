#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>

class Personnage 
{
    public:

    Personnage();
    Personnage(std::string name, int manaa, int life, std::string wName, int wHurt);
    void getHurt(int nbHurt);
    int bim();    
    std::string myName();
    int myLife();
    void attack(Personnage &target);
    void getLife(int qtLife);
    void changeWeapon(std::string nameWeapon, int hurtWeapon);
    bool isAlive();
    
    private: 

    int m_life;
    std::string m_name;
    int m_manaa;
    std::string m_nameWeapon;
    int m_hurtWeapon;
};

#endif // DEF_PERSONNAGE
