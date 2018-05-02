#include "reverse.h"

using namespace std;
extern ofstream csis;

ReverseString::ReverseString() : String() {}

ReverseString::ReverseString(const ReverseString &rString) : String(rString) {}

ReverseString::ReverseString(const char *tmpChar) : String(tmpChar) {}

ReverseString &ReverseString::operator=(const ReverseString &rString) {
    if (&rString != this) String::operator=(rString);
    return *this;
}

ReverseString ReverseString::operator~() {
    ReverseString rString(*this);
    ReverseString reverse;
    int n = rString.getLength();
    for (int i = 0; i < n / 2; i++)
        swap(rString[i], rString[n - i - 1]);
    return reverse;
}
