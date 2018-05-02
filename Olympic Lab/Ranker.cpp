#include "ranker.h"

using namespace std;
extern ofstream csis;

Ranker::Ranker(int mVal) {
    this->mVal = mVal;
    count = 0;
    compList = new Competitor *[mVal];
}

Ranker::~Ranker() { delete[] compList; }

int Ranker::addList(Competitor *comp) {
    if (comp == NULL || count == mVal) return 0;
    compList[count] = comp;
    return count++;
}

Competitor *Ranker::getLane(int val) {
    for (int i = 0; i < count; i++)
        if (val == compList[i] -> getCompLane())
            return compList[i];
    return NULL;
}

Competitor *Ranker::getFinish(int val) {
    for (int i = 1; i < count; i++) {
        for (int j = 0; j < count - i; j++) {
            if (compList[j] -> getCompTime() > compList[j + 1] -> getCompTime()) {
                Competitor *compPtr = compList[j];
                compList[j] = compList[j + 1];
                compList[j + 1] = compPtr;
            }
        }
    }
    //if val > 0 and val <= count return compList[val - 1] else return null
    return val > 0 && val <= count ? compList[val - 1] : NULL;
}