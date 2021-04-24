/*
	Your Name: Vincent Apanovitch
	Date: 4/24/21
	Program Name: CIS 1202
	Description: funcs for Trucks

	Your task should you choose to accept:
	3.	Define a Truck class that inherits from Vehicle.
	  Define the member variables and method prototypes in Truck.h,
	  and the implementation of the methods in Truck.cpp.
		a.	Define a member variable for the towing capacity
		b.	Define a constructor and appropriate getters and setters
		c.	Define a displayInfo method to display the contents of the object (call the base class method to display the Vehicle info, then display the Truck info)


*/

#include <iostream>
#include <string>
#include "Truck.h"
using namespace std;

void Truck::setTowCap(int tc) { towCap = tc; }

int Truck::getTowCap() const { return towCap; }

void Truck::displayInfo() const {
	cout << "\nTowing Capacity: " << getTowCap();
	Vehicle::displayInfo();
}

Truck::Truck(int tc, int yr, string manu) : Vehicle(yr,manu) {
	setTowCap(tc);
}
