/*
    Your Name: Vincent Apanovitch
    Date: 5/2/21
    Program Name: CIS 1202
    Notes: Looks like I still have to push using vs code! Legit wayyy too frustrating.

    2.	Define functions named "half" that accept a single argument, and return a value of that same type.
    3.	For floating-point types (float, double), return half of the value passed in as argument.
    4.	For integer types (int), return half the value, rounded according to usual rounding rules (0.5 or higher, round up; otherwise round down.)
    5.	Build a driver in main to test these functions and display their output.
*/

#include <iostream>
using namespace std;

template <class T>
T half(T full) {return full / 2;}
int half(int full) { return ((full%2)? full+1 : full) / 2; } //I don't need no stinking round!!!! LOL, realized last sec

int main()
{
    float myF = (float) 5;
    double myD = (double) 8;
    int myI = 13;

    cout << half(myF) << "\t" << half(myD) << "\t" << half(myI) << endl;

    system("pause");
    return 0;
}