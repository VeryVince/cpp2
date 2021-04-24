/*
    Your Name: Vincent Apanovitch
    Date: 4/3/21
    Program Name: CIS 1202
    Description: set up funcs to use in PUBLICATION class

    note you don't need to acess var in class with ClassName::var
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Publication.h"

using namespace std;

string Publication::getTypeName() const {
    string typeNames[] = { "Book", "Magazine", "Newspaper", "Audio", "Video" };
    return typeNames[static_cast<int>(Publication::type)] ;
}
string Publication::getTitle() const {
    return Publication::title;
}

int Publication::getStock() const {
    return Publication::stock;
}

void Publication::storePublication(string itemTitle, string itemPublisher, float itemPrice, int itemYear, PublicationType itemType, int itemStock) {
    //basic vallidity tests
    bool error = false;
    if (itemPrice < 0) {
        cout << "\nERROR: Price is below 0";
        error = true;
    }
    if (itemStock < 0) {
        cout << "\nERROR: Stock is below 0";
        error = true;
    }
    if (error)
        exit(-1);

    //set members
    Publication::title = itemTitle;
    Publication::publisher = itemPublisher;
    Publication::price = itemPrice;
    Publication::year = itemYear;
    Publication::type = itemType;
    Publication::stock = itemStock;
}

void Publication::checkIn() {
    Publication::stock++;
}

void Publication::checkOut() {
    Publication::stock--;
}

void Publication::displayInfo() const {
    cout << fixed << setprecision(2)
        << "\nTitle: " << Publication::getTitle()
        << "\nPublisher: " << Publication::publisher
        << "\nPrice: $" << Publication::price
        << "\nYear: " << Publication::year
        << "\nType: " << Publication::getTypeName()
        << "\nStock: " << Publication::stock
        << endl;
}
