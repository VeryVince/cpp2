/*
    Your Name: Vincent Apanovitch
    Date: 1/29/21
    Program Name: CIS 1202
    Description: 
        Write a program that uses an array to store, display, and sort the income for five rental properties.
        2.	Define these functions according to these prototypes:
            a.	int getMenuItem();
                        Displays the menu, gets the user's selection, validates it, and returns a valid menu choice.
            b.	void enterRents(float[], int);
                        Uses a for loop to input the rent amounts into an array using standard array subscript notation.
            c.	void displayRents(float*, int);
                        Uses a for loop to display the contents of the rents array using pointers (not subscripts) to access the array elements.
            d.	void displayMemoryLocations(float[], int);
                        Uses a for loop to display the memory locations of the array elements.
            e.	void selectionSort(float[], int);
                        Use the selection sort algorithm to sort the rents array into ascending order using standard array subscript notation.
        3.	In the main function, repeatedly ask for a menu choice and call the appropriate function based on the menu selection.

    Notes:
        loops through table: *(myTable + i) to display values in table ~ln43
        and rents + i to display memory addresses ~ln51
*/

#include <iostream>
#include <iomanip>
using namespace std;

void enterRents(float rents[], const int RENT_SIZE) { //goes through rents[], ask/enter values
    cout << endl;
    for (int i = 0; i < RENT_SIZE; i++) {
        cout << "Enter rent amount " << i+1 << ": ";
        cin >> rents[i];
    }
    cout << endl;
}

void displayRents(float *rents , const int RENT_SIZE) { //goes through rents[], displays values
    cout << "\nRents:" << endl;
    for (int i = 0; i < RENT_SIZE; i++)
        cout << fixed << setprecision(2) << setw(8)
            << *(rents + i)
            << endl;
}

void displayMemoryLocations(float rents[], const int RENT_SIZE) { //goes through rents[], displays memory loc
    cout << endl;
    for (int i = 0; i < RENT_SIZE; i++)
        cout << "Rent #" << i + 1 << ": "
            << rents + i // &rents[i] would also work here
            << endl;
}

void selectionSort(float myArray[], const int ARRAY_SIZE) { //normal selection sort \o/
    int movePos;

    for (int start=0; start < ARRAY_SIZE - 1; start++) {
        float moveValue = numeric_limits<float>::max(); //max for small 2 large, min for l2s

        for (int i = start; i < ARRAY_SIZE; i++) {
            if (myArray[i] < moveValue) { // < for small 2 large, > for l2s
                moveValue = myArray[i];
                movePos = i;
            }
        }
        myArray[movePos] = myArray[start];
        myArray[start] = moveValue;
    }
    cout << "\nSorting Complete!\n";
}

int getMenuItem(float rents[], const int RENT_SIZE) {
    int input;
    while (true) { //menu loop
        cout << "\n====================================================="
            << "\n1: Enter rents"
            << "\n2: Display rents"
            << "\n3: Sort rent from low to high"
            << "\n4: Display memory locations"
            << "\n5: Exit"
            << "\nEnter a number: ";

        cin >> input;

        if (1 <= input && input <= 5)
            return input;
        else
            cout << "\n\"" << input << "\" is not a valid input!!!!\n";
    }
}


int main() {
    const int RENT_SIZE = 5;
    float rents[RENT_SIZE];

    int input;
    while (true) { //menu loop
        input = getMenuItem(rents, RENT_SIZE);
    
        if      (input == 1) enterRents(rents, RENT_SIZE);
        else if (input == 2) displayRents(rents, RENT_SIZE);
        else if (input == 3) selectionSort(rents, RENT_SIZE);
        else if (input == 4) displayMemoryLocations(rents, RENT_SIZE);
        else
            break;
    }

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
