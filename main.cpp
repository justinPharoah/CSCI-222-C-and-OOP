/**
 * Name: Justin Ferrell
 * Palomar ID: 011564420
 */


// main.cpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ZipCode.h"

using namespace std;
ofstream csis;

int main() {
    ZipCode zip1(99504);
    ZipCode zip2(12345);
    ZipCode zip3(67890);
    ZipCode zip4("100101010011100001100110001");
    ZipCode zip5("110100001011100001100010011");
    ZipCode zip6("100011000110101000011100101");

    csis.open("csis.txt");

    cout << "Digits" << "       " << "Bar Code" << endl;
    csis << "Digits" << "       " << "Bar Code" << endl;

    cout << zip1.getZipCode() << setw(35) << zip1.getBarCode() << endl;
    csis << zip1.getZipCode() << setw(35) << zip1.getBarCode() << endl;

    cout << zip2.getZipCode() << setw(35) << zip2.getBarCode() << endl;
    csis << zip2.getZipCode() << setw(35) << zip2.getBarCode() << endl;

    cout << zip3.getZipCode() << setw(35) << zip3.getBarCode() << endl;
    csis << zip3.getZipCode() << setw(35) << zip3.getBarCode() << endl;

    cout << endl;
    csis << endl;

    cout << zip4.getZipCode() << setw(35) << zip4.getBarCode() << endl;
    csis << zip4.getZipCode() << setw(35) << zip4.getBarCode() << endl;

    cout << zip5.getZipCode() << setw(35) << zip5.getBarCode() << endl;
    csis << zip5.getZipCode() << setw(35) << zip5.getBarCode() << endl;

    cout << zip6.getZipCode() << setw(35) << zip6.getBarCode() << endl;
    csis << zip6.getZipCode() << setw(35) << zip6.getBarCode() << endl;

    csis.close();
    return 0;
}
