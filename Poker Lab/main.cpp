/*
 * Author: Justin Ferrell
 * Palomar ID: *********
 * Compiler: CLion 17.2
 * Operating System: Mac OsX
 *
 *
 * ERROR to be noted: did not succeed in determining a pair without running through the entire hand
 */

#include <iostream>
#include <fstream>
#include "card.h"
#include "deck.h"
#include "game1.h"

#include "stdlib.h"
#include "time.h"

using namespace std;
ofstream csis;

int main() {
    Game1 game(10, 10000);

    csis.open("csis1.txt");

    srand((unsigned) time(NULL));

    for (int t = 0; t < game.trialCount; t++) {
        for (int i = 1; i <= game.handsToDeal; i++) {
            game.dealHand();
            game.typeOfHand(t);
            game.cardsToDeck();
        }
    }    game.generateData();

    csis.close();
}
