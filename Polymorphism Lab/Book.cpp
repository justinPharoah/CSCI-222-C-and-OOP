#include <fstream>
#include "Book.h"

using namespace std;
extern ofstream csis;

Book::Book(string title, string author, int Num) : Holding(title, Num) {
    this -> author = author;
}

void Book::print(ostream &os) {
    os << "BOOK: " << author;
    csis << "BOOK: " << author;
    Holding::print(os);
}

Book::Book(const Book &) {

}
