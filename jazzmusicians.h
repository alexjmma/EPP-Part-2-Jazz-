#pragma once
#ifndef LONG_DECIMAL_INT_H
#define LONG_DECIMAL_INT_H

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

struct JazzMusician {
	string firstname;
	string lastname;
	string instrument;
	int yearborn;
	int yeardied;
	int numrecs;

};

using namespace std;

class JazzMusicians
{

public:
	JazzMusicians(string filename);
	void addMusician(string first, string last, string instr, int born, int died, int recs);
	void DisplayByInstrument(string instrument);
	void printInAnyOrder(void);
	void printMostProlific(void);


private:
	vector<JazzMusician> MusicianStorage;
};

#endif

