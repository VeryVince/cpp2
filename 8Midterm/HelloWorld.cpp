/*
	Your Name: Vincent Apanovitch
	Date: 3/7/21
	Program Name: CIS 1202
	Description: Load Logs from file, edit and add logs
	Resources: http://www.cplusplus.com is epic lol
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


string logToString(vector<string> log) {
	return log[0] + " " + log[1] + ": " + log[2];
}

void viewLogs(vector<vector<string>> logs) {
	for (int r = 0; r < logs.size(); r++) {
		cout << "#" << r+1 << ": " << logToString(logs[r]) <<endl;
	}
}

int searchLogs(vector<vector<string>> logs, string search, int start) { //returns the row or -1 
	int pos = -1;
	for (int r = start; r < logs.size(); r++) {
		pos = ("#" + to_string(r + 1) + ": " + logToString(logs[r])).find(search);
		if (pos != -1) {
			return r;
		}
	}
	return -1;
}

void editLogs(vector<vector<string>> &logs) {
	string input;
	int row;

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
	cout << "Enter in a Search query to find and View/Edit/Delete a log: ";
	getline(cin, input);

	row = searchLogs(logs, input, 0);
	
	if (row == -1) {
		cout << "Was not able to find: " << input;
	}
	else {
		do {
			cout << "\nLog# " << row + 1 << " found: " << logToString(logs[row])
				<< "\nHere are your options: Continue Edit Delete Quit"
				<< "\nEnter an option: ";
			cin >> input;
			
			if (input == "Edit") {
				cout << "\nEnter New Date mm/dd/yyyy: ";
				cin >> logs[row][0];

				cout << "Enter New Action: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //bad \n bad!!
				getline(cin, logs[row][1]);

				cout << "Enter New Details: ";
				getline(cin, logs[row][2]);

				cout << "\nLog Changed to: " << logToString(logs[row]);
				input = "Quit";
			}
			else if (input == "Delete") {
				logs.erase(logs.begin() + row);
				cout << "Deleted log# " << row + 1;

				input = "Quit";
			}
			else if (input == "Continue") {
				row = searchLogs(logs, input, 0);

				if (row == -1) {
					cout << "No more instances found!";
					input = "Quit";
				}
			}
			else if (input == "Quit")
				return;
			else
				cout << "ERROR: Invalid input: " << input;

		} while (input !="Quit");
	}
}


void loadLogs(vector<vector<string>> &logs, fstream& file, string &fileName) {
	string
		log,
		badchars = "\"[],";
	do {
		cout << "\nEnter a file to open. Don't forget the extention!"
			<< "\nEnter File or q to quit: ";
		cin >> fileName;

		//quit now if they want to quit, otherwise they lose data.
		if (fileName == "q" || fileName == "Q" || fileName == "Quit" || fileName == "quit")
			return;
		file.close();
		file.open(fileName, ios::in);

		cout << (file ? "" : "ERROR: " + fileName + " failed to open!\n");
	} while (!file);


	//logs are saved like: ["log1","log2","log3"]
	logs.clear();
	int row = 0;
	while (getline(file, log, '\"')) { //go thru file, stop at all "

		for (int i = 0; i < badchars.length(); i++) { //go thru bad char array, search string for each char, remove if found
			size_t pos = log.find(badchars[i]);
			if (pos != -1) {
				//cout << "\nBadchar: " << badchars[i] << " :Found in log: " << log;
				log.erase(pos, 1);
				i--; //the i-- keeps us searching for the bad char
			}
		}
		if (log == "") //don't save empty logs as a result of erasing
			continue;
		logs.push_back(
			{
				log.substr(0,10), //date
				log.substr(11,log.find(":") - 11), //action
				log.substr(log.find(":") + 2) //details
			}
		);
		//cout << "\nGot log: " << logs[row++][1];

	}
	cout << fileName << " was loaded sucessfully! #logs: " << logs.size();
	file.close();
}

void saveLog(vector<vector<string>> logs, fstream &file, string fileName) {
	file.close();//close if somehow open
	file.open("Logs.txt", ios::out);
	
	file << "[";
	for (int r = 0; r < logs.size(); r++) {
		file << "\"" << logToString(logs[r]) << "\",";
	}
	file << "]";
	file.close();
}

int main()
{
	vector<vector<string>> logs; //normally I'd set this up to be a struct but the requirements call for a 2d array >:{
	fstream file;
	string fileName;
	int input;

	loadLogs(logs, file, fileName);
	
	do
	{
		cout << "\n\nMain Menu"
			<< "\nEnter 1 to load logs from file"
			<< "\nEnter 2 to Search for a log and then Edit/View/Delete it"
			<< "\nEnter 3 to View all logs"
			<< "\nEnter -1 to Save logs and quit"
			<< "\nEnter a numb: ";
		cin >> input;

		if (input == 1)
			loadLogs(logs, file, fileName);
		if (input == 2)
			editLogs(logs);
		if (input == 3)
			viewLogs(logs);
	} while (input !=-1);
	

	saveLog(logs, file, fileName);

	cout << endl;
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
