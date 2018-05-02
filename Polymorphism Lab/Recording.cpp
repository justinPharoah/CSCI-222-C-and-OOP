#include <fstream>
#include "Recording.h"

using namespace std;
extern ofstream csis;

Recording::Recording(string title, string performer, string format, int callNumber) : Holding(title, callNumber) {
    this -> performer = performer;
    this -> format = format;
}

Recording::Recording(const Recording &recording) {
}

Recording::~Recording() {
}

void Recording::print(ostream &os) {
    os << "RECORDING: " << "\"" << title  + " " << '\"' << performer + " " << format + " " << callNumber << endl;
    csis << "RECORDING: " << "\"" << title  + " " << '\"' << performer + " " << format + " " << callNumber << endl;
}
