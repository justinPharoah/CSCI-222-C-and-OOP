#include "game1.h"
#include "stdlib.h"
#include "time.h"
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;
extern ofstream csis;

Game1::Game1(int trialsVal, int handsVal) {
    this->trialCount = trialsVal;
    this->handsToDeal = handsVal;

    pairTempVal = 0, flushTempVal = 0, pairPercentage = 0, flushPercentage = 0;
}

void Game1::dealHand() {
    deck.shuffle(100);
    for (int i = 0; i < length; i++) {
        handArray[i] = deck.getCard();
    }
}

void Game1::typeOfHand(int trial) {
    if (determinePair()) {
        pairCount[trial]++;
    } else if (determineFlush()) {
        flushCount[trial]++;
    }
}

//there must be a way to do this without running in O(N^2) but i did not figure it out :(
bool Game1::determinePair() {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (handArray[i].getValue() == handArray[j].getValue()) {
                return true;
            }
        }
    }
    return false;
}

bool Game1::determineFlush() {
    for (int i = 1; i < length; i++) {
        if (handArray[i].getSuit() != handArray[0].getSuit()) {
            return false;
        }
    }
    return true;
}

void Game1::cardsToDeck() {
    int i = 0;
    while (i < length) {
        deck.addCard(handArray[i]);
        i++;
    }
}

void Game1::generateData() {
    int width = 18;

    //print statement broken up for easier viewing
    cout << fixed << setprecision(2);
    csis << fixed << setprecision(2);

    cout << "Hands dealt each trial: " << handsToDeal << endl;
    csis << "Hands dealt each trial: " << handsToDeal << endl;

    cout << "Trial #";
    csis << "Trial #";

    cout << setw(width) << "# of Pairs";
    csis << setw(width) << "# of Pairs";

    cout << setw(width) << "# of Flushes";
    csis << setw(width) << "# of Flushes";

    cout << setw(width) << "Pair Percentage";
    csis << setw(width) << "Pair Percentage";

    cout << setw(width) << "Flush Percentage" << endl;
    csis << setw(width) << "Flush Percentage" << endl;

    for (int i = 0; i < trialCount; i++) {
        pairTempVal = (double) (pairCount[i] * 100) / handsToDeal;
        pairPercentage += pairTempVal;

        flushTempVal = (double) (flushCount[i] * 100) / handsToDeal;
        flushPercentage += flushTempVal;

        //print statement broken up for easier viewing
        cout << setw(3) << (i + 1);
        csis << setw(3) << (i + 1);

        cout << setw(width) << pairCount[i];
        csis << setw(width) << pairCount[i];

        cout << setw(width) << flushCount[i];
        csis << setw(width) << flushCount[i];

        cout << setw(width) << pairTempVal;
        csis << setw(width) << pairTempVal;

        cout << setw(width) << flushTempVal << endl;
        csis << setw(width) << flushTempVal << endl;
    }

    pairPercentage /= trialCount;
    flushPercentage /= trialCount;

    cout << "\n" << pairPercentage << "% of the hands contained at least one pair." << endl;
    csis << "\n" << pairPercentage << "% of the hands contained at least one pair." << endl;

    cout << flushPercentage << "% of the hands were a flush." << endl;
    csis << flushPercentage << "% of the hands were a flush." << endl;

}
