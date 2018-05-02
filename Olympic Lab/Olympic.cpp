/**
 * Name: Justin Ferrell
 * Palomar ID: 011564420
 */

#include <iostream>
#include <fstream>
#include "Olympic.h"

using namespace std;

ofstream csis;

int main() {
    const int lanes = 4;
    Ranker rank(lanes);

    csis.open("csis.txt");

    // First make a list of names and lane assignments
    Competitor* starters[lanes];

    starters[0] = new Competitor("EmmyLou Harris", 1);
    starters[1] = new Competitor("Nanci Griffith", 2);
    starters[2] = new Competitor("Bonnie Raitt", 3);
    starters[3] = new Competitor("Joni Mitchell", 4);

    // The race is run; now assign a time to each person
    starters[0]->setTime((float)12.0);
    starters[1]->setTime((float)12.8);
    starters[2]->setTime((float)11.0);
    starters[3]->setTime((float)10.3);

    // Put everyone into the ranker
    for (int i = 0; i < lanes; i++)
        rank.addList(starters[i]);

    // Now print out the list to make sure it's right
    cout << "Competitors by lane are:" << endl;
    csis << "Competitors by lane are:" << endl;
    for (int i = 1; i <= lanes; i++)
        rank.getLane(i)->print();
    cout << "" << endl;
    csis << "" << endl;

    // Finally, show how they finished
    cout << "Rankings by finish are:"  << endl;
    csis << "Rankings by finish are:"  << endl;
    for(int i = 1; i <= lanes; i++)
        rank.getFinish(i)->print();
    for(int i = 0; i < lanes; i++)
        delete starters[i];

    csis.close();
} // myset's destructor will be called automatically here
