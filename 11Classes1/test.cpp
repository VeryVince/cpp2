/*
    Your Name: Vincent Apanovitch
    Date: 4/3/21
    Program Name: CIS 1202
    Description: testing the publication stuff
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "Publication.h"

using namespace std;

void getPublicationInfo(Publication& pub) {
    // no input guards bc want to test bad input, yeahhhhhh......

    string title, publisher;
    float price;
    int year, stock;
    PublicationType type;

    cout << "Title: ";
    getline(cin, title);

    cout << "Publisher: ";
    getline(cin, publisher);

    cout << "Price: $";
    cin >> price;

    cout << "Year: ";
    cin >> year;

    int n;
    cout << "Types: 0:Book 1:Magazine 2:Newspaper 3:Audio 4:Video"
        << "\nType #: ";
    cin >> n;
    type = static_cast<PublicationType>(n);

    cout << "Stock: ";
    cin >> stock;

    pub.storePublication(title, publisher, price, year, type, stock);
}

void getPublications(vector<Publication>& lib) {
    string filename = "11publications.txt";
    ifstream data (filename);
    if (!data) {
        cout << "Error opening: " << filename << " \nCheck to make sure it exists!";
        exit(-1);
    }

    string title, publisher;
    float price;
    int year, stock, type; //type is a pub type but get converted at save time
    
    while (!data.eof()) {
        getline(data, title);
        getline(data, publisher);
        cin >> price >> year >> type >> stock;

        if (data.eof()) //eof is really after eof. grrrrrrr
            break;

        Publication temp;
        temp.storePublication(title, publisher, price, year, static_cast<PublicationType>(type), stock);
        lib.push_back(temp);
    }
}

int main() {
    vector<Publication> library;
    getPublications(library);

    for (int i = 0; i < library.size(); i++) {
        cout << library[i].getTitle() << endl;
    }
}