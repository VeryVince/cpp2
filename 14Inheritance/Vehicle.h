/*
	Your Name: Vincent Apanovitch
	Date: 4/24/21
	Program Name: CIS 1202
	Description: Header for Vehicles

	Your task should you choose to accept:
	1.	Define a base class called Vehicle.  
	 Define the member variables and method prototypes in Vehicle.h, 
	 and the implementation of the methods in Vehicle.cpp.
		a.	Define member variables for manufacturer and year built
		b.	Define a constructor and appropriate getters and setters
		c.	Define a displayInfo method to display the contents of the object

*/

#pragma once
#ifndef VEHICLE.H
#define VEHICLE.H

#include <string>

class Vehicle {
	protected: //other classes can inheret protected but not private
		int year; 
		std::string manufacturer;
	public:
		int getYear() const;
		std::string getManufacturer() const;

		void setYear(int);
		void setManufacturer(std::string);

		void displayInfo() const;

		Vehicle(int, std::string);
};

#endif