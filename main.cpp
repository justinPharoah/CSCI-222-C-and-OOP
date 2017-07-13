/*
 * Author: Justin Ferrell
 * Palomar ID: 011564420
 * Compiler: CLion 17.2
 * Operating System: Mac OsX
 *
 *
 * ERROR to be noted: did not succeed in determining a pair without running through the entire hand
 */

#include <iostream>
#include "game2.h"
#include "hand.h"
#include <fstream>
#include "stdlib.h"
#include "time.h"

using namespace std;
ofstream csis;

int main() {
    Game2 game(10, 10000);

    csis.open("csis2.txt");

    srand((unsigned) time(NULL));

    for (int i = 0; i < game.trialCount; i++) {
        for (int j = 1; j <= game.handsToDeal; j++) {
            game.hand.dealHand(game.deck);
            game.typeOfHand(i);
            game.hand.cardsToDeck(game.deck);
        }
    }
    game.generateData();

    csis.close();
}