#ifndef LIBRARY_HOLDINGS_HOLDING_H
#define LIBRARY_HOLDINGS_HOLDING_H

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Holding {
protected:
    string title;
    int callNumber;
public:
    Holding(string title, int callNumber);

    Holding();

    Holding(const Holding &holding);

    virtual ~Holding();

    virtual void print(ostream &os);
};


#endif //LIBRARY_HOLDINGS_HOLDING_H
