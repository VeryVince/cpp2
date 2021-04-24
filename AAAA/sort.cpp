/*
    Your Name: Vincent Apanovitch
    Date:
    Program Name:
    Description:
    Resources:
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

bool isSorted(int array[], int arraySize, bool sortAscFlag) {
    for (int i = 0; i < arraySize-1; i++)
        if (! (sortAscFlag ? (array[i] <= array[i + 1]) : (array[i] >= array[i + 1])))
            return false;
    return true;
}

int main()
{
    cout << "Hello World!\n";

    int myArray[] = {6,5,4,3};

    cout << isSorted(myArray,4,false) << endl;

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
