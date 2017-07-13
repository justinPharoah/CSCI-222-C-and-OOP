#ifndef POKER_LAB_HAND_H
#define POKER_LAB_HAND_H

#include "deck.h"

class Hand {
private:
    Card handArray[5]; //will hold each hand

    //number of elements in the handArray
    //was taught in AP Computer Science using java to utilize variables so i did not want
    //to continuously use the integer '5' in my for loops
    //found this handy solution online
    int length = sizeof(handArray) / sizeof(*handArray);

public:

    bool determinePair(); //checks hand for pair

    bool determineFlush(); //checks hand for flush

    void dealHand(Deck deck); //deals out cards to the hand

    void cardsToDeck(Deck deck); //returns cards to the deck
};

#endif
