// Written by Kristofer Norman 01/24/2022
// Lab 9 understanding of some of the concepts covered in Chapter 9: arrays, structures.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Header.h"


using namespace std;


int main()
{

	personInfo student[3];
	ifstream infile;

	infile.open("inPut.txt");
		if (!infile) {
			cout << "Input file did not open..exiting program" << endl;

				return 0;
		}
		read(infile, student);
		output(student);

}

void read(ifstream& inFile, personInfo people[])
{
	int index = 0; 
	
	while (inFile) {
		
		inFile >> people[index].firstName >> people[index].middleName >> people[index].lastName >> people[index].regiDate.dateMonth >> people[index].regiDate.dateDay >>
			people[index].regiDate.dateYear >> people[index].birthDate.dateMonth >> people[index].birthDate.dateDay 
			>> people[index].birthDate.dateYear >> people[index].personGpa;
		if (!inFile) break;
		index++;

	}

}

void output(const personInfo people[])
{
	for(int index = 0; index < 3; index++) {
		cout << people[index].firstName << " " << people[index].middleName << " " << people[index].lastName << " " << people[index].regiDate.dateMonth << " " <<
			people[index].regiDate.dateDay << " " << people[index].regiDate.dateYear << " " << people[index].birthDate.dateMonth << " " << people[index].birthDate.dateDay<< " " <<
			people[index].birthDate.dateYear << " " << people[index].personGpa;

		cout << endl;
	}

}