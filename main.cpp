#include <iostream>
#include "jazzmusicians.h"
#include <string>
#include <iostream>
#include <fstream>

void printmenu() {
	cout << "Menu:" << endl;
	cout << "N: New entry" << endl;
	cout << "P: print any order" << endl;
	cout << "D: Display by Instrument" << endl;
	cout << "M: Print the full name of the most prolific musician" << endl;
	cout << "Q: quit" << endl;
};

int main(void) 
{

	char input;
	string inst;

	JazzMusicians JM("JazzMusicians.txt"); //Functions
	JazzMusician temp; //Data for Names

	// present operator with menu
	printmenu();

	cin >> input;
	while (input != 'Q' && input != 'q') {
		switch (input) {
		case 'n':
		case 'N':
			// Add a new musician to the data store
			cout << "First Name: ";
			cin >> temp.firstname;
			cout << "Last Name: ";
			cin >> temp.lastname;
			cout << "Instrument: ";
			cin >> temp.instrument;
			cout << "Year Born: ";
			cin >> temp.yearborn;
			cout << "Year Died: ";
			cin >> temp.yeardied;
			cout << "Number of Recordings: ";
			cin >> temp.numrecs;
			


			break;

		case 'p':
		case 'P':
			// Print the musicians in any order
			JM.printInAnyOrder();

			break;

		case 'd':
		case 'D':
			// Display musicians according to the instrument they play
			// for example, if the operator enters Bass, display all
			// musicians that play the Bass.  For the purposes of this
			// program bass and Bass are considered different instruments
			// since the capitalization differs.
			cout << "Which instrument? ";
			cin >> inst;
			JM.DisplayByInstrument(inst);


			break;

		case 'm':
		case 'M':
			// Print the name of the musician that performed on the most
			// recordings per year on average.
			JM.printMostProlific();


			break;

		default:
			cout << "what happened?" << endl;
		}

		printmenu();
		cin >> input;
	}

	system("pause");
}