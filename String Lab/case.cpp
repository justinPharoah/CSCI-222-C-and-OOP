#include "case.h"
#include <fstream>

using namespace std;
extern ofstream csis;

CaseString::CaseString() : String() {}

CaseString::CaseString(const CaseString &cString) : String(cString) {}

CaseString::CaseString(const char *tmpChar) : String(tmpChar) {}

CaseString &CaseString::operator=(const CaseString &cString) {
    if (&cString != this) String::operator=(cString);
    return *this;
}

void CaseString::print() {
    cout << lower << "  " << upper << endl;
    csis << lower << "  " << upper << endl;
}

CaseString::~CaseString() {}
