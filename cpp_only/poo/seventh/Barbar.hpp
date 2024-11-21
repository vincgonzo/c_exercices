#ifndef DEF_BARABAR
#define DEF_BARABAR

#include <string>
#include <iostream>
#include "Personnage.hpp" 

class Barbar : public Personnage 
{
    public:
// find another example tomorriw       virtual int bim() override;
        Barbar();
        ~Barbar();
        void bruteForce() const;
    
    private: 
       bool m_berserk;
};


#endif // DEF_BARABAR
