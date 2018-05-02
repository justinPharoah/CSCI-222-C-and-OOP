/**
 * Name: Justin Ferrell
 * Palomar ID: 011564420
 */

#include<iostream>
#include<fstream>
#include "Holding.h"
#include "Book.h"
#include "Recording.h"

using namespace std;
ofstream csis;


int main() {
    csis.open("csis.txt");

    Holding *holdArray[100];

    char choiceChar;
    int callNumber;
    string title, author, format, performer;

    int i = 0;
    while (i < 5) {
        cout << "Enter holdings to be stored in a list: " << endl;
        csis << "Enter holdings to be stored in a list: " << endl;

        cout << "Enter B for book, R for recording: ";
        cin >> choiceChar;
        csis << "Enter B for book, R for recording: " << choiceChar << endl;

        cin.ignore();

        if (choiceChar != 'b' && choiceChar != 'B') {
            if (choiceChar == 'r' || choiceChar == 'R') {
                cout << "Enter recording title: ";
                getline(cin, title);
                csis << "Enter recording title: " << title << endl;

                cout << "Enter performer: ";
                getline(cin, performer);
                csis << "Enter performer: " << performer << endl;

                cout << "Enter form: (M)P3, (W)AV, (A)IFF: ";
                getline(cin, format);
                csis << "Enter form: (M)P3, (W)AV, (A)IFF: " << format << endl;

                if (format.compare("M") == 0 || format.compare("m") == 0 ) format = "(MP3)";
                if (format.compare("W") == 0 || format.compare("w") == 0) format = "(WAV)";
                if (format.compare("A") == 0 || format.compare("a") == 0) format = "(AIFF)";

                cout << "Enter call number: ";
                cin >> callNumber;
                csis << "Enter call number: " << callNumber << endl;

                holdArray[i] = new Recording(title, performer, format, callNumber);
            }
        } else {
            cout << "Enter book title: ";
            getline(cin, title);
            csis << "Enter book title: " << title << endl;

            cout << "Enter book author: ";
            getline(cin, author);
            csis << "Enter book author: " << author << endl;


            cout << "Enter call number: ";
            cin >> callNumber;
            csis << "Enter call number: " << callNumber << endl;


            Book *b = new Book(title, author, callNumber);
            holdArray[i] = (Holding *) b;
        }
        i++;
    }
    ostream &os = cout;
    for (int i = 0; i < 5; i++) holdArray[i]->print(os);

    csis.close();
}