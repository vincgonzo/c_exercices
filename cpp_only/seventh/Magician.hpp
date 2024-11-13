#ifndef DEF_MAGICIAN
#define DEF_MAGICIAN

#include <string>
#include <iostream>
#include "Personnage.hpp" 

class Magician : public Personnage {
    public:
        void FireBallAttack();
        void restoreLifeMagik();
    
    private: 
        int m_manaa_extra;    
};


#endif // DEF_MAGICIAN
