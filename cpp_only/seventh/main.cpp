#include <iostream>
#include "Personnage.hpp"

using namespace std;

int main()
{
    Weapon epee("Epee", 20), lance_pierre("Lance Pierre", 5), hache("Hache", 30);

    Personnage david("david", 10, 22, lance_pierre), goliath("goliath", 0, 30, epee);

    goliath.displayWeaponUse();
    david.displayWeaponUse();
    goliath.attack(david);
    david.getLife(20);

    goliath.attack(david);
    david.attack(goliath);

    goliath.changeWeapon(hache);
    goliath.displayWeaponUse();
    goliath.attack(david);

    return 0;
}

