#pragma once
#include <string>

using namespace std;

class CollegeClasses {
	friend ostream& operator<<(ostream&, const CollegeClasses&);
	friend istream& operator>>(istream&, CollegeClasses&);

private: 
	string className;
	int numOfStudents;
	int classHours;
public:
	CollegeClasses() {
		className = "";
		numOfStudents = 0;
		classHours = 0;
	}
	CollegeClasses(string, int, int);
	
};
