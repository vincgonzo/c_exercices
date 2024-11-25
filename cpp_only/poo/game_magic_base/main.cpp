#include <iostream>
#include <vector>
#include "Personnage.hpp"
#include "Magician.hpp"

using namespace std;

void gameStatus(vector<Personnage*> const& list);

int main()
{
    Weapon epee("Epee", 20), lance_pierre("Lance Pierre", 5), hache("Hache", 30);

    vector<Personnage*> PersList;
    PersList.push_back(new Personnage("david", 22, lance_pierre));
    PersList.push_back(new Personnage("goliath", 30, epee));

    PersList.push_back(new Magician("Potttter", 10));
    PersList.push_back(new Magician("Ludo", 40));

    gameStatus(PersList);

    PersList[1]->attack((Personnage&)*PersList[0]);
    PersList[0]->getLife(20);

    PersList[1]->attack((Personnage&)*PersList[0]);
    PersList[0]->attack((Personnage&)*PersList[1]);

    PersList[1]->changeWeapon(hache);
    PersList[1]->attack((Personnage&)*PersList[0]);

    PersList[2]->attack((Personnage&)*PersList[1]);
    gameStatus(PersList);

    // clean memory
    for(int i = 0; i < PersList.size(); i++){
        delete PersList[i];
        PersList[i] = 0;
    }

    return 0;
}

void gameStatus(vector<Personnage*> const& list){
    cout << "---- Game Status ----" << endl;
    for(int i = 0; i < list.size(); i++){
        cout << *list[i];
    }
}
