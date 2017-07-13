#include "game2.h"
#include "stdlib.h"
#include "time.h"
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;
extern ofstream csis;

Game2::Game2(int trialsVal, int handsVal) {
    this->trialCount = trialsVal;
    this->handsToDeal = handsVal;

    pairTempVal = 0, flushTempVal = 0, pairPercentage = 0, flushPercentage = 0;
}

void Game2::typeOfHand(int trial) {
    if (hand.determinePair()) {
        pairCount[trial]++;
    } else if (hand.determineFlush()) {
        flushCount[trial]++;
    }
}

void Game2::generateData() {
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
