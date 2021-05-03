/*
    Your Name: Vincent Apanovitch
    Date: 5/2/21
    Program Name: CIS 1202
    Description:
    Resources:
*/

#include <iostream>
#include <string>
using namespace std;


char character(char, int);

int main()
{
    cout << character('a', 1);

    
    try {
        cout << character('z', 1);
    } 
    catch (const char* e){
        cout << "\nERROR: " << e;
    }
    
    try {
        cout << character('a', -15);
    }
    catch (const char* e) {
        cout << "\nERROR: " << e;
    }

    try {
        cout << character('?', 5);
    }
    catch (const char* e) {
        cout << "\nERROR: " << e;
    }

    cout << endl;
    system("pause");
    return 0;
}


char character(char start, int offset){

    //if start not A-Z or a-z
    if (! ('A' <= start && start <= 'Z' || 'a' <= start && start <= 'z') ) {
        throw "invalidCharacterExcpeption";
    }
    char target = start + offset;

    //if target not A-Z or a-z ; Also target must be same case as start ; ASCII A-Z is lower than a-z 
    if (! (('A' <= target && target <= 'Z' && start <= 'Z') || ('a' <= target && target <= 'z' && start >= 'a')) ) {
        throw "invalidRangeExpection";
    }

    return target;
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