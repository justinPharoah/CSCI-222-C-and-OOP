#include "string.h"
#include <fstream>

using namespace std;
extern ofstream csis;

//Constructors / Destructor
String::String() {
    buf = new char[1];
    buf[0] = NULL;
    strLength = 0;
}

String::String(const char *tmpStr) {
    strLength = (int) (strlen(tmpStr));
    buf = new char[strLength + 1];

    for (int i = 0; i < strLength; i++) { buf[i] = tmpStr[i]; }

    buf[strLength] = NULL;
}

String::String(char tmpChar) {
    buf = new char[2];
    buf[0] = tmpChar;
    buf[strLength = 1] = NULL;
}

String::String(int tmpInt) {
    int count = 0, temp = tmpInt;
    if (tmpInt < 0) tmpInt = 0;
    if (temp > 0) {
        do {
            temp /= 10;
            count++;
        } while (temp > 0);
    }
    buf = new char[count + 1];
    sprintf(buf, "%d", tmpInt);
    buf[strLength = count] = NULL;
}

String::String(const String &tmpStr) {
    strLength = tmpStr.strLength;
    buf = new char[strLength];
    buf = tmpStr.buf;
}

String::String(char tmpChar, int tmpInt) {
    int index = 0;
    buf = new char[tmpInt];
    char charArray[tmpInt];

    while (index < tmpInt) {
        charArray[index] = tmpChar;
        index++;
    }

    charArray[tmpInt] = NULL;
    buf = charArray;
    strLength = (int) (strlen(buf));
}

String::~String() { strLength = 0; }

//Overloaded Operators
String &String::operator=(const String &tmpStr) {
    if (this == &tmpStr) return *this;
    strLength = tmpStr.strLength;
    buf = tmpStr.buf;
    return *this;
}

String &String::operator=(const char *tmpChar) {
    strLength = (int) (strlen(tmpChar));
    buf = (char *) tmpChar;
    return *this;
}

String &String::operator+=(const String &tmpStr) {
    int tmpLen = strLength + tmpStr.strLength;
    String temp(*this);
    strLength = tmpLen;
    delete []buf;
    buf = new char[strLength + 1];
    strcpy(buf, temp.buf);

    if (tmpStr.buf == buf) {
        const char *tmpChar(tmpStr.buf);
        strcat(buf, tmpChar);
    } else strcat(buf, tmpStr.buf);
    return *this;
}


String &String::operator++() {
    for (int i = 0; i < strLength; i++) { buf[i] = buf[i + 1]; }
    return *this;
}

String &String::operator--() {
    for (int i = 1; i <= strLength; i++) { buf[i] = buf[i - 1]; }
    return *this;
}

String String::operator++(int) {
    *this = *this + 1;
    return *this;
}

String String::operator--(int) {
    String temp(*this);
    --(*this);
    return temp;
}

String String::operator+() const {
    String temp;
    temp.buf = buf;
    temp.strLength = strLength;

    for (int i = 0; i < temp.strLength; i++) { temp[i] = (char) toupper(temp[i]); }

    return temp;
}

char &String::operator[](int tmpInt) {
    static char tmpChar;
    if (tmpInt < 0 || tmpInt > strLength) {
        cout << "Range Error: Index out of Bounds" << endl;
        return tmpChar;
    } else return buf[tmpInt];
}

String operator+(const String &tmpStr1, const String &tmpStr2) {
    int i, j, sumLength = tmpStr1.strLength + tmpStr2.strLength;
    String tmp(sumLength);
    tmp.strLength = sumLength;

    for (i = 0; i < tmpStr1.strLength; i++) { tmp.buf[i] = tmpStr1.buf[i]; }

    j = 0, i = tmpStr1.strLength;
    while (j < tmpStr2.strLength) {
        tmp.buf[i] = tmpStr2.buf[j];
        j++;
        i++;
    }

    tmp[sumLength] = NULL;
    return tmp;
}

String operator+(const String &tmpStr1, const char *tmpChar) {
    int i, j, sumLength = (int) (tmpStr1.strLength + (strlen(tmpChar)));
    String tmp(sumLength);
    tmp.strLength = sumLength;

    for (i = 0; i < tmpStr1.strLength; i++) { tmp.buf[i] = tmpStr1.buf[i]; }

    j = 0, i = tmpStr1.strLength;
    while (j < (strlen(tmpChar))) { tmp.buf[i] = tmpChar[j];
        j++;
        i++;
    }
    tmp[sumLength] = NULL;
    return tmp;
}

String operator+(const char *tmpChar, const String &tmpStr) {
    int i, j, sumLength = (int) (tmpStr.strLength + (strlen(tmpChar)));
    String tmp(sumLength);
    tmp.strLength = sumLength;

    for (i = 0; i < (strlen(tmpChar)); i++) { tmp.buf[i] = tmpChar[i]; }

    j = 0, i = (int) (strlen(tmpChar));
    while (j < tmpStr.strLength) { tmp.buf[i] = tmpStr.buf[j];
        j++;
        i++;
    }
    tmp[sumLength] = NULL;
    return tmp;
}

String operator+(const String &tmpStr, const char tmpChar) {
    int i, sumLength = tmpStr.strLength + 1;
    String tmp(sumLength);
    tmp.strLength = sumLength;

    for (i = 0; i < tmpStr.strLength; i++) { tmp.buf[i] = tmpStr.buf[i]; }

    tmp[sumLength] = NULL;
    tmp[sumLength - 1] = tmpChar;
    return tmp;
}

String operator+(const char tmpChar, const String &tmpStr) {
    int i, j, sumLength = tmpStr.strLength + 1;
    String tmp(sumLength);
    tmp.strLength = sumLength;
    tmp[0] = tmpChar;

    i = 0, j = 1;
    while (i < tmpStr.strLength) { tmp.buf[j] = tmpStr.buf[i];
        i++;
        j++;
    }
    tmp[sumLength] = NULL;
    return tmp;
}

int operator==(const String &tmpStr1, const String &tmpStr2) { return tmpStr1.buf == tmpStr2.buf; }

int operator!=(const String &tmpStr1, const String &tmpStr2) { return tmpStr1.buf != tmpStr2.buf; }

int operator<(const String &tmpStr1, const String &tmpStr2) { return tmpStr1.buf < tmpStr2.buf; }

int operator<=(const String &tmpStr1, const String &tmpStr2) { return tmpStr1.buf <= tmpStr2.buf; }

int operator>(const String &tmpStr1, const String &tmpStr2) { return tmpStr1.buf > tmpStr2.buf; }

int operator>=(const String &tmpStr1, const String &tmpStr2) { return tmpStr1.buf >= tmpStr2.buf; }

char *operator+(const String &tmpStr, int tmpInt) { return &tmpStr.buf[tmpInt]; }

char *operator+(int tmpInt, const String &tmpStr) { return &tmpStr.buf[tmpInt]; }

ostream &operator<<(ostream &os, const String &tmpStr) {
    for (int i = 0; i < tmpStr.strLength; i++) { os << tmpStr.buf[i]; }
    return os;
}

//Methods
int String::getLength() { return strLength; }

String String::substr(int start, int end) {
    String s;

    int i = start, j = 0;
    while (j < end) {
        s.buf[j] = buf[i];
        s.strLength++;
        i++, j++;
    } return s;
}

void String::print() {
    cout << "\"" << buf << "\"" << "  " << "Length = " << strLength << endl;
    csis << "\"" << buf << "\"" << "  " << "Length = " << strLength << endl;
}