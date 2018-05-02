#include "intarray.h"
#include <fstream>

using namespace std;
extern ofstream csis;

//default constructor - ten elements indexed 0 to 9
IntArray::IntArray() {
    lowIndex = 0; highIndex = 9;
    length = 10;
}

//overloaded constructor - indexed 0 to (high - 1)
IntArray::IntArray(int high) {
    lowIndex = 0; highIndex = high - 1;
    length = high;
}

//overloaded constructor - indexed low to high
IntArray::IntArray(int low, int high) {
    //checks for bounds and handles each situation appropriately
    if (low > high) {
        cout << "Runtime Error: Illegal Index - Lower Boundary" << endl;
        csis << "Runtime Error: Illegal Index - Lower Boundary" << endl;
    } else if (low == high) {
        lowIndex = low; highIndex = high;
        length = 1;
    } else {
        lowIndex = low; highIndex = high;
        length = (high - low) + 1;
    }
}

//copy constructor - copy of old array
IntArray::IntArray(const IntArray &ia) {
    lowIndex = ia.lowIndex; highIndex = ia.highIndex;
    length = ia.length;
    for (int i = lowIndex; i <= highIndex; i++)
        intArray[i] = ia.intArray[i];
}

//destructor
IntArray::~IntArray() {

}

void IntArray::setName(string name) {
    this->name = name;
}

//returns minimum index of array
int IntArray::low() {
    return lowIndex;
}

//returns maximum index of array
int IntArray::high() {
    return highIndex;
}

//compare number of elements return 1 if matching, 0 if not
int IntArray::operator==(IntArray &ia) {
    int compVal = 0;
    if (length == ia.length) {
        for (int i = lowIndex; i <= highIndex; i++) {
            if (*((intArray + lowIndex) + i) == *((ia.intArray + ia.lowIndex) + i))
                compVal = 1;
            else return 0;
        }
    } return compVal;
}

//compare number of elements - return 0 if not matching, 1 if matching
int IntArray::operator!=(IntArray &ia) {
    int compVal = 1;
    if (length == ia.length) {
        for (int i = lowIndex; i <= highIndex; i++) {
            if (*((intArray + lowIndex) + i) == *((ia.intArray + ia.lowIndex) + i))
                compVal = 0;
            else return 1;
        }
    } return compVal;
}

//allows index range checking
int &IntArray::operator[](int temp) {
    if (temp >= lowIndex && temp <= highIndex) {
        return temp;
    }
    cout << "Runtime Error: Illegal Index" << endl;
    csis << "Runtime Error: Illegal Index" << endl;
    return temp;
}

//allows the sum of two arrays to be assigned to the third array
IntArray operator+(IntArray &ia, IntArray &ia2) {
    IntArray temp(ia.length);
    if (ia.length != ia2.length) {
        cout << "Runtime Error: Lengths Different" << endl;
        csis << "Runtime Error: Lengths Different" << endl;
    } else {
        int *ptr1 = (ia.intArray + ia.lowIndex);
        int *ptr2 = (ia2.intArray + ia2.lowIndex);
        for (int i = 0; i <= temp.length; i++)
            temp.intArray[i] = *(ptr1 + i) + *(ptr2 + i);
    } return IntArray(temp);
}

//allows the sum of two arrays to be assigned to the first array
void IntArray::operator+=(IntArray &ia) {
    if (highIndex - lowIndex != ia.highIndex - ia.lowIndex) {
        cout << "Runtime Error: Lengths Different" << endl;
        csis << "Runtime Error: Lengths Different" << endl;
    } else {
        for (int i = lowIndex; i <= highIndex; i++)
            intArray[i] = *(intArray + i) + *((ia.intArray + ia.lowIndex) + i);
    }
}

//allows the contents of an array to be output
ostream &operator<<(ostream &os, const IntArray &ia) {
    if (ia.lowIndex == ia.highIndex) {
        int i = ia.lowIndex;
        os << ia.name << "[" << i << "] = " << ia.intArray[i] << endl;
    } else {
        for (int i = ia.lowIndex; i <= ia.highIndex; i++)
            os << ia.name << "[" << i << "] = " << ia.intArray[i] << endl;
    } return os;
}