// Kristofer Norman 12/03/21
// Lab practicing some of the things learned in chapter 12
// implementaion file

#include "Students.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// my default constructor 
Students::Students()
{

	firstN = ' ';
	lastN = ' ';
	address = ' ';
	city = ' ';
	state = ' ';
	zip = ' ';
	earnedGpoints = 0.0;
	attemptCredhours = 0.0;
	gpa = 0.0;
}

Students::Students(string initFirstn, string initLastn, string initAddress, string initCity,
	string initState, string initZip)
{
	firstN = initFirstn;
	lastN = initLastn;
	address = initAddress;
	city = initCity;
	state = initState;
	zip = initZip;
}

Students::Students(string initFirstn, string initLastn, string initAddress, string initCity,
	string initState, string initZip, float initEarned, float initAttempt)
{
	firstN = initFirstn;
	lastN = initLastn;
	address = initAddress;
	city = initCity;
	state = initState;
	zip = initZip;
	earnedGpoints = initEarned;
	attemptCredhours = initAttempt;
}

void Students::setAttemptValue(float inAttemptValue)
{
	attemptCredhours = inAttemptValue;
}

void Students::setEarnedValue(float inEarnedValue)
{
	earnedGpoints = inEarnedValue;
}

void Students::StudentsGPAcalc()
{
	gpa = earnedGpoints / attemptCredhours;
}

void Students::StudentsGPAcalc(float inEarnedValue, float inAttemptValue) 
{
	gpa = inEarnedValue / inAttemptValue;
}

void Students::Display() const
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Student Name: " << firstN << lastN << endl; 
	cout << "Address: " << address << " " << city << " " << state << " " << zip << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Grade points earned: " << earnedGpoints << endl;
	cout << "Grade points attempted: " << attemptCredhours << endl;
	cout << "Grade point Average: " << gpa << endl; 
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

}
