/*
    Your Name: Vincent Apanovitch
    Date: 5/2/21
    Program Name: CIS 1202
    Description:
    Resources:
*/

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template <class T>
T half(T full) {return full / 2;}
int half(int full) { return round(full / 2.0); }

int main()
{
    float myF = (float) 5;
    double myD = (double) 8;
    int myI = 13;

    cout << half(myF) << "\t" << half(myD) << "\t" << half(myF);

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
