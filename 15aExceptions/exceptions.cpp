/*
    Your Name: Vincent Apanovitch
    Date: 5/2/21
    Program Name: CIS 1202
    Notes: 
    I hate windows and github and vs. I spent an hour trying to log in using various ways and nothing was working. 
    I spent more time with github than this code *sigh*
    I had to sign in using vs code and thankfully that worked >:{


    1.	Write a function according to this prototype: char character(char start, int offset);
    2.	If start is not a letter (A-Z, a-z), throw an invalidCharacterExcpeption.
    3.	If the target is not a letter, throw an invalidRangeException.
    4.	Otherwise, return the letter described by the start and offset.
    5.	Build a driver in main to test this function and display its output.  Use try/catch blocks to call your function with different start and offset values
*/

#include <iostream>
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