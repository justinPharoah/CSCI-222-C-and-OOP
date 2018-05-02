#ifndef STRING_LAB_STRING_H
#define STRING_LAB_STRING_H

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class String {
private:
    char *buf;
    int strLength;
public:
    //Constructors / Destructor
    String(); //Default Constructor

    String(const char *tmpChar); //Creates String object based upon a string literal

    String(char tmpChar); //String object from single character

    String(int tmpInt); //String object from an int value

    String(const String &tmpStr); //Copy constructor

    String(char tmpChar, int tmpInt); //initialize String object with repeated character tmpInt number of times

    ~String(); //Destructor releases space on the heap

    //Overloaded Operators
    String &operator=(const String &); //assigns String instance to another String instance

    String &operator=(const char *); //assign a string literal to a String instance

    String &operator+=(const String &); //adds Strings together and modifies left-hand argument

    String &operator++(); //add 1 to each character in string literal pointed at by buf and return the result

    String &operator--(); //subtract 1 from each character in string literal pointed at by buf and return the result

    String operator++(int tmpInt); //add 1 to each character pointed at by buf and return the original String

    String operator--(int tmpInt); //subtract 1 from each character pointed at by buf and return the original String

    String operator+() const; //overloads + operator as a unary member operator. ensures string literal is uppercase

    char &operator[](int); //return a particular character from the array of characters

    friend String operator+(const String &tmpStr1, const String &tmpStr2); //concatenates two Strings together

    friend String operator+(const String &tmpStr, const char *tmpChar); //concatenates a string literal to a String

    friend String operator+(const char *tmpChar, const String &tmpStr); //concatenates a String to a string literal

    friend String operator+(const String &tmpStr, const char tmpChar); //concatenates a character to a String

    friend String operator+(const char tmpChar, const String &tmpStr); //concatenates a String to a character

    friend int operator==(const String &tmpStr1, const String &tmpStr2); //compares Strings for equality

    friend int operator!=(const String &tmpStr1, const String &tmpStr2); //compares Strings for inequality

    friend int operator<(const String &tmpStr1, const String &tmpStr2); //is second String greater than the first

    friend int operator<=(const String &tmpStr1, const String &tmpStr2); //is second String greater than or equal to first

    friend int operator>(const String &tmpStr1, const String &tmpStr2); //is first string greater than second

    friend int operator>=(const String &tmpStr1, const String &tmpStr2); //is first String greater than or equal to second

    friend char *operator+(const String &tmpStr, int tmpInt); //adds tmpInt to a String object

    friend char *operator+(int tmpInt, const String &tmpStr); //adds a String to an int

    friend ostream &operator<<(ostream &os, const String &tmpStr); //output contents of the string pointer itself

    //Methods
    int getLength(); //return String length

    String substr(int start, int end); //extract and return substring (from start to end) of a String

    void print(); //outputs literal itself
};

#endif //STRING_LAB_STRING_H
