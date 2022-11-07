#pragma once

using namespace std;

struct StudentData
{
	int dateMonth;
	int dateDay;
	int dateYear;
};
struct personInfo
{
	string firstName;
	string middleName;
	string lastName;
	StudentData regiDate;
	StudentData birthDate;
	float personGpa;
};

void read(ifstream&, personInfo[]);
void output(const personInfo[]);