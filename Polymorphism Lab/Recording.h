#ifndef LIBRARY_HOLDINGS_RECORDING_H
#define LIBRARY_HOLDINGS_RECORDING_H

#include<iostream>
#include<fstream>
#include<string>
#include "Holding.h"

using namespace std;

class Recording : public Holding {
protected:
    string performer;
    string format;
public:
    Recording(const Recording &recording);

    Recording(string title, string performer, string format, int callNumber);

    ~Recording();

    void print(ostream &os);
};

#endif //LIBRARY_HOLDINGS_RECORDING_H
