//ZipCode.h

#include <iostream>

#ifndef BARCODELAB_ZIPCODE_H
#define BARCODELAB_ZIPCODE_H

using namespace std;

class ZipCode {
public:
    ZipCode(int zipCode); //Overloaded Constructor takes an int, zipCode, as a parameter
    ZipCode(string barCode); //Overloaded Constructor takes an string, barCode, as a parameter

    int getZipCode(); //returns the Zip Code value
    string getBarCode(); //returns the Bar Code value
private:
    int zipCode; //should meet specification for only way of storing the input internally

    string zipToBar(int zipCode); //converts a Zip Code to a Bar Code
    void barToZip(string barCode); //converts a Bar Code to a Zip Code
};


#endif //BARCODELAB_ZIPCODE_H
