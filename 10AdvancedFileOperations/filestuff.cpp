/*
	Your Name: Vincent Apanovitch
	Date: 3/28/21
	Program Name: CIS 1202
	Description: Reading from a file and putting recoreds in it
	Notes: I might have taken a few to many liberties with this one >.<

	Uses tellg and seekg and seekp
	Uses getline and the clasic badcar
	Uses Namespace for cheeky modular product names
	Uses strncpy(char array,string) and pre processer _CRT_SECURE_NO_WARNINGS
	Writes Struct to file
	Opens File if not exist for read and write in binary!

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//DO NOT EVER EVER CHANGE THIS EVER EVER!!!!! Entries are saved into the file with this space baked in for ALL products. Think: 11 33 55 77 Turns to: 113 355 77? ;;VERY BAD!
const int PROD_NAME_SIZE = 40; 

namespace PRODUCT_FIELDS {
	const string
		self = "Product",
		number = self + " Number: ",
		name = self + " Name: ",
		price = self + " Price: $",
		quantity = self + " Amount: ";
}

struct Product {
	long number;
	char name[PROD_NAME_SIZE];
	double price;
	int quantity;
};

void createFile(fstream& file) {
	Product temp;
	file.seekp(0L,ios::beg);
	temp = { 21,"Dog Food",1.23,3 };
	file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
	temp = { 23,"Cat Food",1.23,3 };
	file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
	temp = { 29,"RTX 3060 TI",843.00,0 };
	file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
	temp = { 42,"Pie",3.14,15926 };
	file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
}

streampos findRecord(fstream& file, long number) { //returns -1 if not found
	Product item;
	streampos pos;
	bool found = false;
	file.clear();
	file.seekg(0L);

	/*
	* I'm not a fan of this loop
	* Ideally I'd like to say: if match then return file.tellg() - sizeof(Product)
	* Rather than assign the pos to every read and flip a bool. But I get error E0350
	* I suppose I could calc a streamoff but meh ¯\_(ツ)_/¯
	*/
	pos = file.tellg(); //update pos before we read
	file.read(reinterpret_cast<char*>(&item), sizeof(item));
	while (!file.eof()) {
		if (item.number == number) {
			found = true;
			break;
		}
		pos = file.tellg(); //update pos before we read again
		file.read(reinterpret_cast<char*>(&item), sizeof(item));
	}

	//clear up any errors
	file.clear();
	file.seekg(0L);

	return (found) ? pos : static_cast<streampos>(-1);
}

void displayProduct(Product p) {
	cout << setprecision(2) << fixed << endl
		<< PRODUCT_FIELDS::name << p.name << endl
		<< PRODUCT_FIELDS::number << p.number << endl
		<< PRODUCT_FIELDS::price << p.price << endl
		<< PRODUCT_FIELDS::quantity << p.quantity << endl;
}

void findAndDisplayRecord(fstream& file, long numb) {
	streampos pos = findRecord(file, numb);
	if (pos == -1)
		cout << "Error: Can't find item number: " << numb << endl;
	else {
		Product toView;
		file.seekg(pos);
		file.read(reinterpret_cast<char*>(&toView), sizeof(Product));
		displayProduct(toView);
	}
}

void displayFile(fstream& file) {
	file.clear();
	file.seekg(0L);
	Product p;
	
	cout << "\n===================INVENTORY===================";
	file.read(reinterpret_cast<char*>(&p), sizeof(Product));
	while (!file.eof()) {
		displayProduct(p);
		file.read(reinterpret_cast<char*>(&p), sizeof(Product));
	}
	cout << "==================END OF FILE==================\n";
}

void findAndModifyRecord(fstream& file, long numb) {
	streampos pos = findRecord(file, numb);
	if (pos == -1)
		cout << "Error: Can't find item number: " << numb << endl;
	else {
		string name;
		int nameL;
		bool good = true;

		Product p;
		file.seekg(pos);
		
		file.read(reinterpret_cast<char*>(&p), sizeof(Product));
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
		do {
			cout << "New " << PRODUCT_FIELDS::name;
			getline(cin, name);
			nameL = name.length();
			good = nameL < PROD_NAME_SIZE;
			if (!good)
				cout << "ERROR! Name must be less than" << PROD_NAME_SIZE << " chars! Input was " << nameL << " chars :{" << endl;
		} while (!good);

		//hi this line took an hour to figure out, strncpy just didn't seem to work and anything else I tried didn't seem to either :{ but now it works? idk man
		//anyways strncpy_s does not populate ununsed fields in destination so must use reg strncpy instead
		strncpy(p.name, name.data(),PROD_NAME_SIZE); 
		
		cout << "New " << PRODUCT_FIELDS::number;
		cin >> p.number;
		cout << "New " << PRODUCT_FIELDS::price;
		cin >> p.price;
		cout << "New " << PRODUCT_FIELDS::quantity;
		cin >> p.quantity;

		file.seekp(pos);
		file.write(reinterpret_cast<char*>(&p), sizeof(Product));
	}
}

int main()
{
	fstream file;
	file.open("inventory.dat", ios::out | ios::in | ios::binary); 
	if (!file) { //I really hate that there's no eazy open if not exist, who's idea was that? (or maybe there is and I dont know it)
		cout << "Attemting to create file... ";
		file.close();
		file.clear();
		file.open("inventory.dat", ios::out);
		createFile(file);
		file.close();
		file.clear();
		file.open("inventory.dat", ios::out | ios::in | ios::binary);
		if (!file) {
			cout << "Error Creating File!\n";
			exit(500);
		}
		cout << "File Created!\n\n";
	}
	
	long input;
	do {
		cout << "\n---------Main Menu---------"
			<< "\nEnter 1 to Display the Inventory"
			<< "\nEnter 2 to Find and Display a Product by ID"
			<< "\nEnter 3 to Find and Modify a Product by ID"
			<< "\nEnter anything other number to Quit."
			<< "\nEnter a number: ";
		
		cin >> input;
		
		if (input == 1) 
			displayFile(file);
		else if (input == 2) {
			cout << "\nEnter ID to Display or -1 to go to Main Menu: ";
			cin >> input;
			if (input == -1)
				continue;
			findAndDisplayRecord(file, input);
		}
		else if (input == 3) {
			cout << "\nEnter an ID to Modifiy the Product or -1 to go to Main Menu: ";
			cin >> input;
			if (input == -1)
				continue;
			findAndModifyRecord(file, input);
		}
		else input = -1;
	} while (input != -1);

	system("pause");
	return 0;
}

/*
	Write a menu-driven program that creates and updates a binary inventory file named inventory.dat. 
	This file does not exist anywhere, so your program will create it.  
	The file is composed of records.
	1.	Use a menu-driven program that implements the following commands:
		a.	Display the entire inventory
		b.	Display a particular product
		c.	Modify a product
		d.	Exit the program
	3.	In the main function, call the createFile function once at the beginning of the program, then display the menu and call the appropriate functions until the user chooses to exit.
	4.	All operations must access the file directly.  Do not use arrays for this assignment.
	5.	Open and close the file only once in main.  Pass the fstream object to the functions.
	6.	Functions must pass parameters and return values as needed, using only local variables.  Global variables are not allowed.

*/