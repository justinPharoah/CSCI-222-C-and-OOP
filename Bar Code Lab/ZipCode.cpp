//ZipCode.cpp

#include "ZipCode.h"
#include <fstream>

using namespace std;
extern ofstream csis;

ZipCode::ZipCode(int zipCode) {
    this->zipCode = zipCode;
    zipToBar(zipCode);
}

ZipCode::ZipCode(string barCode) {
    zipCode = 0;
    barToZip(barCode);
}

int ZipCode::getZipCode() {
    return zipCode;
}

string ZipCode::getBarCode() {
    return zipToBar(zipCode);
}

string ZipCode::zipToBar(int zipCode) {
    string barCode;

    //Runs through each digit of the zip code, backwards.
    //Converts the value to its corresponding bar code string
    //Concatenates each segment to the final Bar Code
    while (zipCode > 0) {
        int tmpVal = zipCode % 10;
        zipCode /= 10;

        if (tmpVal == 0) barCode = "11000" + barCode;
        else if (tmpVal == 1) barCode = "00011" + barCode;
        else if (tmpVal == 2) barCode = "00101" + barCode;
        else if (tmpVal == 3) barCode = "00110" + barCode;
        else if (tmpVal == 4) barCode = "01001" + barCode;
        else if (tmpVal == 5) barCode = "01010" + barCode;
        else if (tmpVal == 6) barCode = "01100" + barCode;
        else if (tmpVal == 7) barCode = "10001" + barCode;
        else if (tmpVal == 8) barCode = "10010" + barCode;
        else barCode = "10100" + barCode;

    }
    return barCode = "1" + barCode + "1"; //adds in the first and last 1's for format
}

void ZipCode::barToZip(string barCode) {
    string segment;
    barCode = barCode.substr(1, barCode.length() - 2); //removes first and last 1's only there for format

    //Runs through each 5 digit segment of the bar code
    //Converts the value to its corresponding zip code integer
    //Sums up all the integers into the final Zip Code
    while (barCode.length() > 0) {
        segment = barCode.substr(0, 5);
        barCode = barCode.substr(5);

        //multiplies by 10 to add the extra digit or space every time we check a 5 length segment
        if (segment == "11000") zipCode *= 10;
        else if (segment == "00011") zipCode = zipCode * 10 + 1;
        else if (segment == "00101") zipCode = zipCode * 10 + 2;
        else if (segment == "00110") zipCode = zipCode * 10 + 3;
        else if (segment == "01001") zipCode = zipCode * 10 + 4;
        else if (segment == "01010") zipCode = zipCode * 10 + 5;
        else if (segment == "01100") zipCode = zipCode * 10 + 6;
        else if (segment == "10001") zipCode = zipCode * 10 + 7;
        else if (segment == "10010") zipCode = zipCode * 10 + 8;
        else zipCode = zipCode * 10 + 9;
    }

}

