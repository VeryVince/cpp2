/*
    Your Name: Vincent Apanovitch
    Date: 2/10/21
    Program Name: CIS 2101
    Description: Write a program to decode parts of a vehicle identification number (VIN), using only C-style string functions.

    Notes:
        char to int for ascii math / checking
        loop thru char[]
            Useage: for (; !vin[i] == '\0'; i++) || for (; vin[i]; i++) || while(vin[i]) i++
        passes char[] to func(char var[])
            Useage: char var[] = "text"; func(var)
        passes "text" to func(const char var[])
            Useage: func("text")
        VS Studio error ignore
            Useage: #pragma warning(disable : numb)
        Overloaded functions
        switch with a fallthrough

    Requirements:
    1.  A VIN never contains the letters I, O, Q, or Z, to avoid confusion with the numerals 1, 0, and 2.  A VIN never contains the letter U because it looks similar to the letter V.
    2.	Use the <cstring> header only.  Do not use the C++ string class.
    2.5 Use a literal, such as "1FTRW14W84KC76110", for the VIN in your program.  Don't prompt the user for input.
    3.	Create these functions according to the prototypes:
        a.	bool valid(char[]);
                Pass a C-string containing a VIN and verify that the VIN consists of exactly 17 numerals or upper-case letters, excluding I, O, Q, U, and Z.  Use the isxxx() functions (e.g. isupper(), isalpha(), etc.)
        b.	void origin(char[], char[]);
                Pass a C-string containing a VIN in the first parameter, and copy a C-string containing the name of the origin in the second parameter.
        c.	int year(char[]);
                Pass a C-string containing a VIN and return the model year as an integer.  (Some ASCII math will simplify this function for you.)
    4.	In main(), call these functions to display information about the VIN.
*/

#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

using namespace std;

//error funcs, one general, one specific
//if this was lua I'd throw them in isValid but it's not :(
void printVinError(const char message[]) {
    cout << "\nVIN Error: " << message;
}
void printVinError(int stringPos, char value, const char message[]) {
    cout << "\nVIN Error: Pos: " << stringPos << " Value: " << value << " Reasion: " << message;
}


bool isValid(char vin[]) { //loops thru vin[] return false if bad and tell why 
    bool isThisGood = true; //innocent until proven guilty :}
    int i=0;

    for (; !vin[i] == '\0'; i++) { //while(vin[i]) is vaid as long as you remember i++ ;;;; for(;vin[i];i++) is also vaild but doesn't really show what's going on 
        char v = vin[i];
        
        if (isalpha(v)) {
            if (islower(v)) {
                isThisGood = false;
                printVinError(i, v, "Must be Upercase");
                v = toupper(v); //Converts to Upper to check for invalid look-a-like chars, will print 2 error messages for same pos tho so might be poor choice (?)
            }

            switch (v){
                case 'I':
                case 'O':
                case 'Q':
                case 'U':
                case 'Z':
                    isThisGood = false;
                    printVinError(i, v, "Is an Invalid Char");
            }
        }
    }
    if (i != 17) {
        isThisGood = false;
        printVinError("Must be Exactly 17 Chars");
    }

    return isThisGood;
}

void getOrigin(char vin[], char origin[]) {
    /*
        A-H	Africa
        J-R	Asia
        S-Y	Europe
        1-5	North America
        6-7	Oceania
        8-0	South America
    */

    int v = vin[0];  //put ascii into var
    //cout << "\nAscii # for Origin: " << v << "\n";

    if (49 <= v && v <= 53) // 1 & 5
        strcpy(origin, "North America");
    else if (v == 54 || v == 55) // 6 & 7
        strcpy(origin, "Oceania");
    else if (v == 58 || v == 59 || v == 48) // 8 & 9 & 0
        strcpy(origin, "South America");
    else if (65 <= v && v <= 72) //A & H
        strcpy(origin, "Africa");
    else if (74 <= v && v <= 82) // J & R 
        strcpy(origin, "Asia");
    else if (83 <= v && v <= 89) // S & Y
        strcpy(origin, "Europe");
}

int returnYear(char vin[]) {
    /*
        P-Y	1993-2000
        1-9	2001-2009
        A-M	2010-2022
    */
    int year = -1, //if ascii doesn't fit it returns this
        v = vin[9];
    
    //cout << "\nAscii # for Year: " << v << "\n";
    if (49 <= v && v <= 57) // 1 & 9
        year = v - 49 + 2001;
    else if (65 <= v && v <= 77) // A & M
        year = v - 65 + 2010;
    else if (80 <= v && v <= 89) // p && y
        year = v - 80 + 1993;

    return year;
}

int main()
{
    char origin[20],
        vin[] = "qIo765";

    cout << "Testing VIN: " << vin;
    if (!isValid(vin)) {
        exit(400);
    }
    else {
        getOrigin(vin, origin);

        cout <<"\nVIN is Valid :}"
            << "\n\tYear: " << returnYear(vin)
            << "\n\tOrigin: " << origin
            << endl;
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
