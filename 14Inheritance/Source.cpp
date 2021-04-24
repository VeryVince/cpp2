/*
	Your Name: Vincent Apanovitch
	Date: 4/24/21
	Program Name: CIS 1202
	Description: funcs for Trucks

	Fun Stuff:
		So 

	Your task should you choose to accept:
	4.	Write a main function to test the classes and methods.
		a.	Get input from the user for manufacturer and year built, 
				then store this information in a Vehicle object.  
				Call the displayInfo method and display it on the output.
		b.	Get input from the user for manufacturer, year built, and number of doors,
				then store this information in a Car object.  
				Call the displayInfo method and display it on the output.
		c.	Get input from the user for manufacturer, year built, and towing capacity, 
				then store this information in a Truck object.  
				Call the displayInfo method and display it on the output.
*/

#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
	int year, towCap, doors;
	string manu;

	cout << "Vehicle:"
		<< "\nEnter year: ";
	cin >> year;
	cout << "Enter the manufacturer: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
	getline(cin, manu);

	cout << "Displaying Info:\n";

	Vehicle testV(year,manu);
	testV.displayInfo();

	cout << "\n\nCar:"
		<< "\nEnter year: ";
	cin >> year;
	cout << "Enter the manufacturer: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
	getline(cin, manu);
	cout << "Enter the # of doors: ";
	cin >> doors;

	cout << "Displaying Info:\n";

	Car testC(doors,year,manu);
	testC.displayInfo();

	cout << "\n\nTruck:"
		<< "\nEnter year: ";
	cin >> year;
	cout << "Enter the Manufacturer: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
	getline(cin, manu);
	cout << "Enter the Towing Capacity: ";
	cin >> towCap;

	cout << "Displaying Info:\n";

	Truck testT(towCap,year,manu);
	testT.displayInfo();

	cout << endl;
	system("pause");
	return 0;
}