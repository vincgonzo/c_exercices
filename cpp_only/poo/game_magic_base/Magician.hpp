#ifndef DEF_MAGICIAN
#define DEF_MAGICIAN

#include <string>
#include <iostream>
#include "Personnage.hpp" 

class Magician : public Personnage {
    public:
        Magician();
        Magician(std::string, int manaa);
        virtual ~Magician();
        void FireBallAttack();
        void restoreLifeMagik();
        virtual void attack(Personnage &target) const;
        virtual void display(std::ostream &stream) const;
    
    private: 
        int m_manaa;    
};


#endif // DEF_MAGICIAN
