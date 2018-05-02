#ifndef LIBRARY_HOLDINGS_BOOK_H
#define LIBRARY_HOLDINGS_BOOK_H

#include<iostream>
#include<fstream>
#include<string>
#include "Holding.h"

using namespace std;

class Book : public Holding {
protected:
    string author;
public:
    Book(string title, string author, int Num);

    Book(const Book &);

    void print(ostream &);
};


#endif //LIBRARY_HOLDINGS_BOOK_H
