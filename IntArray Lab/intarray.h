#ifndef Int_Array
#define Int_Array

#include <iostream>

using namespace std;

class IntArray {
private:
    string name;
    int lowIndex, highIndex, length, intArray[];

public:
    IntArray(); //default constructor - ten elements indexed 0 to 9
    IntArray(int high); //overloaded constructor - indexed 0 to high - 1
    IntArray(int low, int high); //overloaded constructor - indexed low to high
    IntArray(const IntArray &ia); //copy constructor - copy of old array
    ~IntArray(); //destructor

    void setName(string name);

    int low(), high(); //returns minimum and maximum indices of an array

    int operator==(IntArray &ia); //compare number of elements
    int operator!=(IntArray &ia); //compare number of elements
    int &operator[](int temp); //allows index range checking
    friend IntArray
    operator+(IntArray &ia, IntArray &ia2); //allows the sum of two arrays to be assigned to the third array
    void operator+=(IntArray &ia); //allows the sum of two arrays to be assigned to the first array
    friend ostream &operator<<(ostream &os, const IntArray &ia); //allows the contents of an array to be output
};
#endif