#ifndef _RANKER_H
#define _RANKER_H

#include "Competitor.h"
#include <iostream>

using namespace std;

class Ranker {
    Competitor **compList;
    int mVal, count;

public:
    Ranker(int mVal); //one arg ctor, number of competitors to be ranked

    ~Ranker(); //Destructor

    int addList(Competitor *comp); //passes in pointers to Competitor objects one by one

    Competitor *getLane(int val); //returns pointer to the Competitor object in the specified lane

    Competitor *getFinish(int val); //returns pointer to the competitor who finished at the specified position
};
 #endif