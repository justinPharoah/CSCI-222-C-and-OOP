#include "competitor.h"
#include <fstream>

using namespace std;
extern ofstream csis;

Competitor::Competitor(char *strName, int laneNum) {
    int val = (int) strlen(strName);
    compName = new char[val + 1];
    strcpy(compName, strName);
    this -> laneNum = laneNum;
    raceTime = 0;
}

Competitor::~Competitor() { delete[] compName; }

void Competitor::setTime(float raceTime) { this -> raceTime = raceTime; }

char *Competitor::getCompName() { return compName; }

int Competitor::getCompLane() { return laneNum; }

float Competitor::getCompTime() { return raceTime; }

void Competitor::print() {
    cout << fixed << setprecision(1);
    csis << fixed << setprecision(1);

    cout << "Name: " << compName << setw((int) (25 - strlen(compName))) << " Lane: " << laneNum << setw(10) << " Time: " << raceTime << endl;
    csis << "Name: " << compName << setw((int) (25 - strlen(compName))) << " Lane: " << laneNum << setw(10) << " Time: " << raceTime << endl;

}