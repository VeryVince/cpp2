/*
    Your Name: Vincent Apanovitch
    Date: 4/18/21
    Program Name: CIS 1202
    Description: testing the publication stuff

    Notes:
        I'm spoiled by lua, you can not just assign a class like: class TEST; TEST b; TEST a = b; A is NOT now b. Use a pointer or something else.
        class TEST; TEST b; TEST *a = &b; now a->member is the same as b.member
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Publication.h"

using namespace std;

void getPublicationInfo(Publication& pub) {
    // no input guards bc want to test bad input

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
    int year, stock, type; //type is a pub type but get converted at storePublication time
    
    while (data) {
        getline(data, title);
        getline(data, publisher);
        data >> price >> year >> type >> stock;
        
        data.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!

        Publication temp;
        temp.storePublication(title, publisher, price, year, static_cast<PublicationType>(type), stock);
        lib.push_back(temp);
    }

    data.close();
}

void showPublications(const vector<Publication> lib) {
    cout << "\n========= Showing Publications =========";

    for (int i = 0; i < lib.size(); i++)
        lib[i].displayInfo();

    cout << "\n========= End Of Publications =========\n";
}

void showTitles(const vector<Publication> lib) {
    cout << "\n========= Showing Titles =========\n";

    for (int i = 0; i < lib.size(); i++)
        cout << lib[i].getTitle() << endl;

    cout << "========= End Of Titles =========\n";
}

int findPublicaton(const vector<Publication> lib, string searchTitle) { //returns -1 if not found
    for (int i = 0; i < lib.size(); i++)
        if (lib[i].getTitle() == searchTitle)
            return i;
    return -1;
}


int getMenuChoice (){
    int input;
    bool again = false;
    do {
        again = false;
        cout << "\n===== Main Menu ======"
            << "\nEnter 1 to Display all publications."
            << "\nEnter 2 to Display all publications' titles."
            << "\nEnter 3 to Find a publication."
            << "\nEnter 4 to Check Out a publication."
            << "\nEnter 5 to Check In a publication."
            << "\nEnter 6 to Exit."
            << "\nEnter a number: ";
        cin >> input;
        
        if (1 > input || input > 6) {
            cout << "\nERROR: " << input << " is not a valid number!\n";
            again = true;
        }
    } while (again);
    return input;
}

int main() {
    vector<Publication> library;
    getPublications(library);
    
    //there's a bit of code repeation for stuff that uses findPublicaton() consider consolidating
    
    bool quit = false;
    do { // main program / menu loop
        int input = getMenuChoice();

        if (input == 1) showPublications(library);
        else if (input == 2) showTitles(library);
        else if (input == 3) { //find pub
            string title;
            cout << "\nEnter a publication to Find: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
            getline(cin, title);
            
            int pubNum = findPublicaton(library, title);
            if (pubNum == -1) {
                cout << "\nERROR: Publication Title not found: " << title << endl;
            }
            else {
                cout << "\nPublication Title was found: " << title;
                library[pubNum].displayInfo();
            }
        }
        else if (input == 4) {//check out
            string title;
            cout << "\nEnter a publication to Check Out: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
            getline(cin, title);

            int pubNum = findPublicaton(library, title);
            if (pubNum == -1) {
                cout << "\nERROR: Publication Title not found: " << title << endl;
            }
            else {
                Publication* p = &(library[pubNum]);
                cout << "\nPublication Title was found: " << title;
                if (p->getStock() <= 0) {
                    cout << "\nError: Can't Check Out because stock is " << p->getStock() << endl;
                }
                else {
                    p->checkOut();
                    cout << "\nStock is now: " << p->getStock() << endl;
                }
            }
        }
        else if (input == 5) {//check in
            string title;
            cout << "\nEnter a publication to Check In: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
            getline(cin, title);

            int pubNum = findPublicaton(library, title);
            if (pubNum == -1) {
                cout << "\nERROR: Publication Title not found: " << title << endl;
            }
            else {
                library[pubNum];
                cout << "\nPublication Title was found: " << title;
                library[pubNum].checkIn();
                cout << "\nStock is now: " << library[pubNum].getStock() << endl;
            }
        }
        else
            quit = true;
    } while (!quit);

    system("pause");
    return 0;
}

/*
3.	Write the following functions according to the prototypes, placing them in the same source code file as the main function:
    a.	void getPublications(Publication[], int&);
            Reads the input file publications.txt to load the file data into the parameter array.  
            For each publication, call the Publication::storePublication function
            to transfer the data from the file into the next location in the array.
    b.	void showPublications(Publication[], int);
                Loops through all of the publications in the array, calling the method displayInfo for each item in the array.
    c.	void showTitles(Publication[], int);
                Loops through all of the publications in the array, calling the method getTitle for each item in the array, and displays it on the screen.
    d.	int findPublication(Publication[], int, string);
                Loops through all of the publications in the array, calling the method getTitle for each item in the arrayand compares it to the string parameter.
                Returns the position in the array of the match, or a sentinel indicating that the publication was not found.
    e.	int getMenuChoice();
                Display the menu and return a valid choice.
                    i.Display all publications
                    ii.Display publication titles
                    iii.Find a publication
                    iv.Check out
                    v.Check in
                    vi.Exit
    f.Menu commands "Find a publication", "Check out", and "Check in" prompt for the title of a publication, 
        invoke findPublication to determine if the publication is available, 
        then the appropriate displayInfo, checkOut, or checkIn method, 
        or display an error message if the publication was not found.

4.	Write a main function that :
    a.Calls getPublications to read the input file into the array.
    b.Displays the menu and calls the appropriate functions.

*/