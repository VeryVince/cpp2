/*
    Your Name: Vincent Apanovitch
    Date: 1/22/20
    Program Name: CIS 1202 C++ Part 2
    Description: 
        Searching and Sorting Arrays
        Write a program to price video game consoles.  Use parallel arrays to input, print, find the most valuable, and sort pricing data.
    Resources:
        Numeric Limits for cin: https://stackoverflow.com/questions/29195285/how-to-avoid-conflict-between-cin-operator-and-getline
    Notes:
        Uses numeric limits to-avoid-conflict-between-cin-and-getline AND for float max/min. Lines 28 / 60
        Load file. Line 115
        Double edged selection sort. Line 56
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_SIZE = 30;

void lookUpPrice(string consoles[], float prices[], int size) {
    string input;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        cout << "\nEnter name to look up the price or (q)uit: ";
        getline(cin, input);

        if (input == "q" || input == "Q" || input == "Quit" || input == "quit" || input == "(q)uit")
            return;

        for (int i = 0; i < size; i++) {
            if (consoles[i] == input) {
                cout << setprecision(2) << fixed << endl
                    << consoles[i] << " is: $" << prices[i];
                return;
            }
        }
        cout << "\"" << input << "\" was not found!";
    } while (true);
}

void highestPrice(string consoles[], float prices[], int size) {
    int highPos = 0;
    for (int i = 0; i < size; i++)
        highPos = (prices[highPos] < prices[i]) ? i : highPos;
    cout << fixed << setprecision(2) << endl
        << "The highest price is the " << consoles[highPos] << " at $" << prices[highPos];
}

void sortArray(string consoles[], float prices[], int size) { //goes through array, picks low and high, moves them to lowest and highest
    int start = 0,
        stop = size - 1,
        lowPos, highPos;
    float lowPrice = numeric_limits<float>::max(),
        highPrice = numeric_limits<float>::min(),
        tempPrice;
    string tempCons;

    while (start < stop) {
        for (int i = start; i <= stop; i++) { //find low and high
            cout << "Price: " << prices[i] << " LowPrice: " << lowPrice << " HighPrice: " << highPrice << " Start/Stop: " << start << "/" << stop << endl;
            if (prices[i] < lowPrice) {
                lowPrice = prices[i];
                lowPos = i;
                cout << "Low Price: " << lowPrice << " Low Pos: " << lowPos << endl;
            }
            if (prices[i] > highPrice) {
                highPrice = prices[i];
                highPos = i;
                cout << "High Price: " << highPrice << " High Pos: " << highPos << endl;
            }
        }
        
        if (stop - start >= 3) { //swap positions
            tempCons = consoles[start];
            consoles[start] = consoles[lowPos];
            consoles[lowPos] = tempCons;

            tempCons = consoles[stop];
            consoles[stop] = consoles[highPos];
            consoles[highPos] = tempCons;

            tempPrice = prices[start];
            prices[start] = prices[lowPos];
            prices[lowPos] = tempPrice;

            tempPrice = prices[stop];
            prices[stop] = prices[highPos];
            prices[highPos] = tempPrice;
        }
        else { //this is done to stop it from switching twice (very annoying to track down, stupid visual studio)
            tempCons = consoles[stop];
            consoles[stop] = consoles[highPos];
            consoles[highPos] = tempCons;

            tempPrice = prices[start];
            prices[start] = prices[lowPos];
            prices[lowPos] = tempPrice;
        }

        start++;
        stop--;
        cout << endl;

        lowPrice = numeric_limits<float>::max();
        highPrice = numeric_limits<float>::min();
    }
}

void loadArrays(string consoles[], float prices[], int &size) {
    ifstream file;
    file.open("prices.txt");

    if (!file) {
        cerr << "Failed to open prices.txt file!!!";
        exit(404);
    }

    //loop pretty much copied from the doc
    //loads data into arrays / calcs size
    size = 0;
    string priceText;
    while (getline(file, consoles[size]) && size < MAX_SIZE) { 
        getline(file, priceText);
        prices[size] = stof(priceText);
        size++;
    }
}

void showArrays(string consoles[], float prices[], int size) {
    const int CONS_W = 30, PRICE_W = 7; //Col widths for output

    cout << "\n==================================================" << endl
        << left << setw(CONS_W) << "Consoles" << right << setw(PRICE_W) << "Prices" << endl;
    for (int i = 0; i < size; i++)
        cout << setprecision(2) << fixed
            << left << setw(CONS_W) << consoles[i] 
            << right << setw(PRICE_W) << prices[i] << endl;
    cout << "==================================================" << endl;
}

void showMenu(string consoles[], float prices[], int size) {
    int input;

        do {
            cout << "\n~~~~~ Main Menu ~~~~~"
                << "\nEnter 1 to display console prices"
                << "\nEnter 2 to look up a console's price"
                << "\nEnter 3 to sort the prices in descending order"
                << "\nEnter 4 to display the highest priced console"
                << "\nEnter anything else to quit"
                << "\n\nEnter a number: ";

            cin >> input;
            if (input == 1) showArrays(consoles, prices, size);
            else if (input == 2) lookUpPrice(consoles, prices, size);
            else if (input == 3) sortArray(consoles, prices, size);
            else if (input == 4) highestPrice(consoles, prices, size);
            else
                return;
        } while (true);
}

int main()
{
    string consoles[MAX_SIZE];
    float prices[MAX_SIZE];
    int size;

    loadArrays(consoles, prices, size);
    showMenu(consoles, prices, size);

    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
