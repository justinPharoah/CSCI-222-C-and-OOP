#ifndef POKER_LAB_GAME1_H
#define POKER_LAB_GAME1_H

#include "card.h"
#include "deck.h"

class Game1 {
private:
    Card handArray[5]; //will hold each hand

    Deck deck;

    int flushCount[100], pairCount[100];

    //number of elements in the handArray
    //was taught in AP Computer Science using java to utilize variables so i did not want
    //to continuously use the integer '5' in my for loops
    //found this handy solution online
    int length = sizeof(handArray) / sizeof(*handArray);

    double pairTempVal, flushTempVal;
    double pairPercentage, flushPercentage;

    bool determinePair(); //checks hand for pair

    bool determineFlush(); //checks hand for flush

public:
    Game1(int trialsVal, int handsVal); //overloaded constructor

    int trialCount, handsToDeal; //10 trials, 10000 hands to deal

    void dealHand(); //deals out cards to the hand

    void typeOfHand(int trial); //determines if pair or flush

    void cardsToDeck(); //returns cards to the deck

    void generateData(); //prints out all data required by lab
};

#endif
