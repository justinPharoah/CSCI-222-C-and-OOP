#ifndef _REVERSESTRING_H
#define _REVERSESTRING_H

#include <iostream>
#include "string.h"

class ReverseString : public String {
public:
    ReverseString(); //default constructor

    ReverseString(const ReverseString &); //copy constructor

    ReverseString(const char *); //one arg ctor

    ReverseString &operator=(const ReverseString &); //overloaded assignment = operator

    ReverseString operator~(); //overloaded unary operator that reverses letters of string itself
};
#endif //_REVERSESTRING_H
