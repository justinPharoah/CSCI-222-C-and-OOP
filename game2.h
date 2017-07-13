#ifndef POKER_LAB_GAME2_H
#define POKER_LAB_GAME2_H

#include "card.h"
#include "deck.h"
#include "hand.h"

class Game2 {
private:
    int pairCount[100], flushCount[100]; //keeps track of pair and flush count

    double pairTempVal, flushTempVal, pairPercentage, flushPercentage; //used in pair and flush percentage calculations

public:
    Game2(int trialsVal, int handsVal); //overloaded constructor

    Deck deck;
    Hand hand;

    int trialCount, handsToDeal; //10 trials, 10000 hands to deal

    void generateData(); //prints out all data required by lab
    void typeOfHand(int trial); //determines if pair or flush

};

#endif