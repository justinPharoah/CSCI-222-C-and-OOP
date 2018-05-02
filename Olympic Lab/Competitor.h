#ifndef _COMPETITOR_H
#define _COMPETITOR_H

#include <iostream>
#include <iomanip>

using namespace std;

class Competitor {
private:
    char *compName;
    int laneNum;
    float raceTime;

public:
    Competitor(char *strName, int laneNum); //initializes Competitor object with name and lane assignment

    ~Competitor(); //Destructor

    void setTime(float raceTime); //sets time with double floating point value

    char *getCompName(); //returns the name of the Competitor

    int getCompLane(); //returns the lane of the Competitor

    float getCompTime();

    void print(); //print out object as single line of text: name, lane, and time
};

#endif