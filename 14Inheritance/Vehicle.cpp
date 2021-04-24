/*
	Your Name: Vincent Apanovitch
	Date: 4/24/21
	Program Name: CIS 1202
	Description: defining the funcs for Vehicles

	Your task should you choose to accept:
	1.	Define a base class called Vehicle.
	 Define the member variables and method prototypes in Vehicle.h,
	 and the implementation of the methods in Vehicle.cpp.
		a.	Define member variables for manufacturer and year built
		b.	Define a constructor and appropriate getters and setters
		c.	Define a displayInfo method to display the contents of the object

*/

#include "Vehicle.h"
#include <string>
#include <iostream>

using namespace std;


int Vehicle::getYear() const { return year; }
string Vehicle::getManufacturer() const { return manufacturer; }

void Vehicle::setYear(int y) { year = y; }
void Vehicle::setManufacturer(string m) { manufacturer = m; }

void Vehicle::displayInfo() const {
	cout << "\nYear: " << getYear()
		<< "\nManufacturer: " << getManufacturer();
}

Vehicle::Vehicle(int y, std::string m) {
	setYear(y);
	setManufacturer(m);
}
