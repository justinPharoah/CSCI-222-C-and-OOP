#ifndef _CASESTRING_H
#define _CASESTRING_H

#include <iostream>
#include "string.h"

class CaseString : public String {
private:
    char *upper, *lower; //holds contents of string literal in upper/lower case
    char *buf;
    int strLength;
public:
    CaseString(); //default constructor

    CaseString(const CaseString &); //copy constructor

    CaseString(const char *); //one arg ctor

    ~CaseString(); //destructor

    CaseString &operator=(const CaseString &); //overloaded assignment = operator

    void print(); //adds to output of string literals pointed to by upper and lower
};
#endif //_CASESTRING_H
