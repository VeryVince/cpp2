/*
    Your Name: Vincent Apanovitch
    Date: 2/1/21
    Program Name: CIS 1202
    Description:
        Re-write the previous homework assignment using pointers instead of subscripts.  Also add a "total" option.
    Notes:
ln 63   New/delete:  delete[] ptr; ptr = new float[size];
ln 58   Creating a referance pointer: (float *&ptrRef) read pointers right to left. Here, ptrRef is a reference to a pointer to a float type)
    Story Time:
        MY GOD is c++ fussy about creating a referance pointer in a function.
        It took me HOURS to find/figure out how to do it and of course studio is of no help. I had to use (float**)&myPointer as a watch just to see the memory addresses, and that's after I poked around in the memory window for awhile.
        I tried a few different tactics until I was able to use reinterpret_cast to change a float* to an int then back to a float*
        http://www.cplusplus.com/doc/oldtutorial/typecasting/
        
        you can run this code to see the proof of concept I made to test if it would work
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
void putSomethingAtChangedMemoryLocation(int& memLoc) {
    float* point = new float[9];

    point[3] = 3.14159265; //testnumber

    memLoc = reinterpret_cast<int>(point);
    cout << "\nNew point: " << hex << point << "\n^ casted to int then cout hex: " << memLoc;

    point = reinterpret_cast<float*>(memLoc);
    cout << "\nNew point casted to int then float*: " << hex << point;
}

int main() {
    int memoryLocation = 0;

    cout << "\nOld Loc: " << memoryLocation;

    putSomethingAtChangedMemoryLocation(memoryLocation);

    cout << "\nNew Loc: " << memoryLocation
        << "\nTestnumber: " << *(reinterpret_cast<float*>(memoryLocation) + 3) << endl;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        I wasn't quite satisfied even though that's a hilarious way of fixing the problem. I'd have to copy/past it everywhere.
        I then found this: http://www.cplusplus.com/forum/general/85183/
        Post #2: (remember, read pointers right to left. Here, (float *&ptrRef) is a reference to a pointer to a float type)
        My god has there never been a more perfect sentance. I could kiss post #2

        ...I could have spent just 5mins if I didn't want to use the new/delete stuff lol
*/

#include <iostream>
#include <iomanip>
using namespace std;

void enterRents(float *&rents, int& RENT_SIZE) { //goes through rents[], ask/enter values
    cout << "\nEnter the number of rents you wish to enter: "; 
    cin >> RENT_SIZE;
    cout << "\nEnter -1  at anytime to stop entering rents if needed.\n";

    delete[] rents; //deletes array if it exists, pointer is 0 at start so nothing happens first time
    rents = new float[RENT_SIZE]; //create array at user size

    for (int i = 0; i < RENT_SIZE; i++) {
        cout << "Enter rent amount " << i + 1 << " of " << RENT_SIZE << ": ";
        cin >> *(rents + i);
        if (rents[i] == -1) { //quit loop, shrink array, report size
            //lazy way of "shrinking" the array, it'll still take up whatever space the user said tho.
            //just i because we want to ignore the -1 the user inputed into the system
            RENT_SIZE = i; 
            break;
        }
    }
    cout << endl;
}

void displayRents(float* rents, const int RENT_SIZE) { //goes through rents[], displays values
    cout << "\nRents:" << endl;
    for (int i = 0; i < RENT_SIZE; i++)
        cout << fixed << setprecision(2) << setw(8)
        << *(rents + i)
        << endl;
}

void sumRents(float* rents, const int RENT_SIZE) {
    float sum = 0;

    for (int i = 0; i < RENT_SIZE; i++)
        sum += *(rents + i);

    cout << fixed << setprecision(2)
        << "\nThe total rents is: $" << sum 
        << endl;
}

void displayMemoryLocations(float* rents, const int RENT_SIZE) { //goes through rents[], displays memory loc
    cout << endl;
    for (int i = 0; i < RENT_SIZE; i++)
        cout << "Rent #" << i + 1 << ": "
        << rents + i // &rents[i] would also work here
        << endl;
}

void selectionSort(float *myArray, const int ARRAY_SIZE) { //normal selection sort \o/
    int movePos;

    for (int start = 0; start < ARRAY_SIZE - 1; start++) {
        float moveValue = numeric_limits<float>::max(); //max for small 2 large, min for l2s

        for (int i = start; i < ARRAY_SIZE; i++) {
            if (*(myArray+i) < moveValue) { // < for small 2 large, > for l2s
                moveValue = *(myArray + i);
                movePos = i;
            }
        }
        myArray[movePos] = *(myArray + start);
        *(myArray + start) = moveValue;
    }
    cout << "\nSorting Complete!\n";
}

int getMenuItem() {
    int input;
    while (true) { //menu loop
        cout << "\n====================================================="
            << "\n1: Enter rents"
            << "\n2: Display rents"
            << "\n3: Display total of rents"
            << "\n4: Sort rent from low to high"
            << "\n5: Display memory locations"
            << "\n6: Exit"
            << "\nEnter a number: ";

        cin >> input;

        if (1 <= input && input <= 6)
            return input;
        else
            cout << "\n\"" << input << "\" is not a valid input!!!!\n";
    }
}


int main() {
    int RENT_SIZE;
    float *rents = 0;

    enterRents(rents, RENT_SIZE); //make user enter rents first so that no funny business can happen

    int input;
    while (true) { //menu loop
        input = getMenuItem();

        if (input == 1) enterRents(rents, RENT_SIZE);
        else if (input == 2) displayRents(rents, RENT_SIZE);
        else if (input == 3) sumRents(rents, RENT_SIZE);
        else if (input == 4) selectionSort(rents, RENT_SIZE);
        else if (input == 5) displayMemoryLocations(rents, RENT_SIZE);
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