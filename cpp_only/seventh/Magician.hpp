#ifndef DEF_MAGICIAN
#define DEF_MAGICIAN

#include <string>
#include <iostream>
#include "Personnage.hpp" 

class Magician : public Personnage {
    public:
        Magician();
        Magician(std::string, int manaa);
        void FireBallAttack();
        void restoreLifeMagik();
    
    private: 
        int m_manaa;    
};


#endif // DEF_MAGICIAN
