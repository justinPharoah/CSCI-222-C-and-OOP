#include <fstream>
#include "Holding.h"

using namespace std;
extern ofstream csis;

Holding::Holding(string title, int callNumber) {
    this -> title = title;
    this -> callNumber = callNumber;
}

Holding::~Holding() {
}

void Holding::print(ostream &os) {
    os << '\"' << title << '\"' + " " << callNumber << endl;
    csis << '\"' << title << '\"' + " " << callNumber << endl;
}

Holding::Holding() {
}

Holding::Holding(const Holding &holding) {

}
