/*
	Your Name: Vincent Apanovitch
	Date: 4/3/21
	Program Name: CIS 1202
	Description: Header for Publications

	include guard
	header definitions
	ifndef

	Note: don't use: using namespace xyz; in header files, it makes things messy :{ https://stackoverflow.com/questions/167862/how-can-i-unuse-a-namespace
*/

#ifndef ACCOUNT_H //include guard https://en.wikipedia.org/wiki/Include_guard
#define ACCOUNT_H

#include <string> //all headers *should* have an include guard: ISO/IEC 14822:2011 17.6.2.2 Headers[using.headers]

enum class PublicationType {BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO};

class Publication { //members are private by default
	private: 
		//  vars
		std::string title, publisher;
		float price;
		int year, stock;
		PublicationType type;

		//  funcs
		std::string getTypeName() const;

	public:
		//  funcs
		//  getters
		std::string getTitle() const;
		int getStock() const;

		//  setters
		//main setter
		void storePublication(
			std::string itemTitle,
			std::string itemPublisher,
			float itemPrice, 
			int itemYear, 
			PublicationType itemType, 
			int itemStock
		);

		//change stock: in +1, out -1
		void checkIn(), checkOut();

		//  seers  
		//cout vars
		void displayInfo() const;
};




#endif // !ACCOUNT_H