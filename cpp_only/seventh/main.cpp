#include <iostream>
#include "Personnage.hpp"

using namespace std;

int main()
{
    Weapon epee("Epee", 20), lance_pierre("Lance Pierre", 5), hache("Hache", 30);

    Personnage david("david", 10, 22, lance_pierre), goliath("goliath", 0, 30, epee);

    cout << "===== GAME STATUS =======" << endl;
    cout << david << " and " << goliath;
    goliath.attack(david);
    david.getLife(20);

    cout << "===== GAME STATUS =======" << endl;
    cout << david << " and " << goliath;
    goliath.attack(david);
    david.attack(goliath);

    goliath.changeWeapon(hache);
    goliath.attack(david);
    cout << "===== GAME STATUS =======" << endl;
    cout << david << " and " << goliath;

    return 0;
}

