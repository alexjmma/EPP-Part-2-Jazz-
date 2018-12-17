#include "JazzMusicians.h"
#include <string>
#include <fstream>


JazzMusicians::JazzMusicians(string filename)
{
	// Complete this

	JazzMusician JM;

	ifstream inFile(filename.c_str());
	string trash;

	if (inFile.is_open())
	{
		getline(inFile, trash);

		while (!inFile.eof())
		{
			inFile >> JM.firstname >> JM.lastname >> JM.instrument >> JM.yearborn >> JM.yeardied >> JM.numrecs;
			MusicianStorage.push_back(JM);
		}
		inFile.close();
	}

	else
	{
		std::cout << "File didn't open" << endl;
	}


}

void JazzMusicians::addMusician(string first, string last, string instr, int born, int died, int recs) {
	// Complete this
	JazzMusician JM;
	JM.firstname = first;
	JM.lastname = last;
	JM.instrument = instr;
	JM.yearborn = born;
	JM.yeardied = died;
	JM.numrecs = recs;

	MusicianStorage.push_back(JM);
}

void JazzMusicians::DisplayByInstrument(string instrument) {
	// Complete this
	vector<JazzMusician>::iterator iter;

	for (iter = MusicianStorage.begin(); iter != MusicianStorage.end(); iter++)
	{
		if (iter->instrument == instrument)
		{
			cout << iter->instrument << " " << iter->lastname << ", ";
		}
	}
	cout << endl << endl;

}

void JazzMusicians::printInAnyOrder(void) {
	// Complete this
	vector<JazzMusician>::iterator pos;

	for (pos = MusicianStorage.begin(); pos != MusicianStorage.end(); pos++)
	{
		cout << pos->firstname << " " << pos->lastname << " Instrument: " << pos->instrument;
		cout << " " << pos->yearborn << "-" << pos->yeardied << " played on " << pos->numrecs << " recordings" << endl;

	}
}

void JazzMusicians::printMostProlific(void) {
	// Complete this
	vector<JazzMusician>::iterator pos;
	JazzMusician MostProlific;
	int bestaverage = 0;
	int currentaverage;

	for (pos = MusicianStorage.begin(); pos != MusicianStorage.end(); pos++)
	{
		currentaverage = pos->numrecs / (pos->yeardied - pos->yearborn);
		
		if (currentaverage > bestaverage)
		{
			bestaverage = currentaverage;
			MostProlific.firstname = pos->firstname;
			MostProlific.lastname = pos->lastname;
		}
	}
	cout << "Most prolific jazz musician is " << MostProlific.firstname << " " << MostProlific.lastname << endl << endl;
}


