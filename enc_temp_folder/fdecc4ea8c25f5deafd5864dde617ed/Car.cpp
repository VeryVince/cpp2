/*
	Your Name: Vincent Apanovitch
	Date: 4/24/21
	Program Name: CIS 1202
	Description: Func for Cars

	Your task should you choose to accept:
	2.	Define a Car class that inherits from Vehicle.
	  Define the member variables and method prototypes in Car.h,
	  and the implementation of the methods in Car.cpp.
		a.	Define a member variable for the number of doors
		b.	Define a constructor and appropriate getters and setters
		c.	Define a displayInfo method to display the contents of the object (call the base class method to display the Vehicle info, then display the Car info)

*/

#include <iostream>
#include <string>
#include "Car.h"
using namespace std;


void Car::setDoors(int d){ doors = d; }

int Car::getDoors() const{ return doors; }

void Car::displayInfo() const{
	cout << getDoors() << " Door" + (string)((doors==1)?"":"s") << endl;
	Vehicle::displayInfo();
}

Car::Car(int drs, int yr, string manu) : Vehicle(yr,manu){
	setDoors(drs);
}
