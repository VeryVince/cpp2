/*
    Your Name: Vincent Apanovitch
    Date: 1/13/21
    Program Name: CIS 1202
    Description: Reads Inventory from file into arrays, calcs the total value, then displays table and extra info.
    Notes:
    -EOF flag doesn't get raised when last item is read, rather when you try reading something not there. (or when reads THE eof?)
        When eof and nothing to read, nothing is read to code (fortunatly) and will not error out or warn (unfortunatly)

    -cerr is a thing, outputs errors. Use like cout.
    -passes arrays: func(array[])
    -passes referance: func(&myVar){cout << myVar}
    -uses: (cond) ? true : false ~ln68
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int const MAXSIZE = 20;

void loadArrays(string product[], int quantity[], float cost[], int& tableSize) {
    ifstream InventoryFile;
    InventoryFile.open("inventory.txt");
    
    if (!InventoryFile) {
        cerr << "Failed to open inventory file!!!";
        exit(404);
    }

    for (int i = 0; !InventoryFile.eof() && i<MAXSIZE; i++) {//NOTE EOF flag doesn't get raised when last item is read, rather when you try reading something not there.
        InventoryFile >> product[i];
        InventoryFile >> quantity[i];
        InventoryFile >> cost[i];
        tableSize = i; // should be i+1 but see EOF note
    }

    InventoryFile.close();
}

void calculateValues(int quantity[], float cost[], float value[], int tableSize) {
    for (int i = 0; i < tableSize; i++) 
        value[i] = cost[i] * quantity[i];
}

void displayTable(string product[], int quantity[], float cost[], float value[], int tableSize) {
    const int COL_W[] = {13,12,12,14}; // the column widths for output
    const float HIGH_INDICATOR = 9000; // adds indicator for values over this

    int totalQty = 0;
    float totalValue = 0, topValue = 0;
    string topProduct;

    //table headers
    cout << setw(COL_W[0]) << left << "Product Code" 
        << setw(COL_W[1]) << right << "Qty On Hand" 
        << setw(COL_W[2]) << "Cost Each" 
        << setw(COL_W[3]) << "Total Value" << endl;
    //table
    for (int i = 0; i < tableSize; i++) {
        cout << setprecision(2) << fixed
            << setw(COL_W[0]) << left << product[i]
            << setw(COL_W[1]) << right << quantity[i]
            << setw(COL_W[2]) << cost[i]
            << setw(COL_W[3]) << value[i]
            << ((value[i] > HIGH_INDICATOR) ? " !!!" : "") // adds indicator for high values
            << endl;
        
        //find top product
        if (value[i] > topValue) {
            topProduct = product[i];
            topValue = value[i];
        }
        
        //calcs for average
        totalQty += quantity[i];
        totalValue += value[i];
    }

    //display Highest product and avg cost of inv item
    cout << fixed << setprecision(2)
        << "\nThe product with the highest inventory value is: " << topProduct
        << "\nThe average cost of an inventory item is: $" << totalValue / totalQty
        << endl;
}

int main()
{
    string product[MAXSIZE];
    int quantity[MAXSIZE], tableSize;
    float cost[MAXSIZE], value[MAXSIZE];

    loadArrays(product, quantity, cost, tableSize);
    calculateValues(quantity, cost, value, tableSize);
    displayTable(product, quantity, cost, value, tableSize);

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
