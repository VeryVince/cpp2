/*
	Your Name: Vincent Apanovitch
	Date: 4/24/21
	Program Name: CIS 1202
	Description: Header for Cars

	Your task should you choose to accept:
	2.	Define a Car class that inherits from Vehicle.  
	  Define the member variables and method prototypes in Car.h, 
	  and the implementation of the methods in Car.cpp.
		a.	Define a member variable for the number of doors
		b.	Define a constructor and appropriate getters and setters
		c.	Define a displayInfo method to display the contents of the object (call the base class method to display the Vehicle info, then display the Car info)

*/

#pragma once
#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <string>


class Car : public Vehicle {
	protected: //other classes can inheret protected but not private
		int doors;
	public:
		void setDoors(int);
		int getDoors() const;

		void displayInfo() const;

		Car(int doors, int year, std::string manu);
};

#endif