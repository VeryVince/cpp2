/*
	Your Name: Vincent Apanovitch
	Date: 4/24/21
	Program Name: CIS 1202
	Description: Header for Trucks

	Your task should you choose to accept:
	3.	Define a Truck class that inherits from Vehicle.  
	  Define the member variables and method prototypes in Truck.h, 
	  and the implementation of the methods in Truck.cpp.
		a.	Define a member variable for the towing capacity
		b.	Define a constructor and appropriate getters and setters
		c.	Define a displayInfo method to display the contents of the object (call the base class method to display the Vehicle info, then display the Truck info)


*/

#pragma once
#ifndef TRUCK.H
#define TRUCK.H

#include "Vehicle.h"
#include <string>


class Truck : public Vehicle {
	protected: //other classes can inheret protected but not private
		int towCap;
	public:
		void setTowCap(int);
		int getTowCap() const;

		void displayInfo() const;

		Truck(int towCap, int year, std::string manu);
};

#endif