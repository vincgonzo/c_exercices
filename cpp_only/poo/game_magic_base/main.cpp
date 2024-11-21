#include <iostream>
#include "Personnage.hpp"
#include "Magician.hpp"

using namespace std;

int main()
{
    Weapon epee("Epee", 20), lance_pierre("Lance Pierre", 5), hache("Hache", 30);

    Personnage david("david", 22, lance_pierre), goliath("goliath", 30, epee);
    Magician harry("Potttter", 10), merlin("Ludo", 40);

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

    harry.attack(goliath);
    cout << "===== GAME STATUS =======" << endl;

    return 0;
}

