#include <iostream>
#include "Personnage.hpp"

using namespace std;

int main()
{

    Personnage david("david", 10, 22, "lance pierre", 10), goliath("goliath", 0, 30, "Epee", 20);

    goliath.attack(david);
    david.getLife(20);

    goliath.attack(david);
    david.attack(goliath);

    goliath.changeWeapon("Double Hache", 40);
    goliath.attack(david);

    return 0;
}

