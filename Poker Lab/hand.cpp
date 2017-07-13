#include "hand.h"

void Hand::dealHand(Deck deck) {
    deck.shuffle(100);
    for (int i = 0; i < length; i++) {
        handArray[i] = deck.getCard();
    }
}

//there must be a way to do this without running in O(N^2) but i did not figure it out :(
bool Hand::determinePair() {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (handArray[i].getValue() == handArray[j].getValue()) {
                return true;
            }
        }
    }
    return false;
}

bool Hand::determineFlush() {
    for (int i = 1; i < length; i++) {
        if (handArray[i].getSuit() != handArray[0].getSuit()) {
            return false;
        }
    } return true;
}

void Hand::cardsToDeck(Deck deck) {
    int i = 0;
    while (i < length) {
        deck.addCard(handArray[i]);
        i++;
    }
}
