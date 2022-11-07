#include "CollegeClasses.h"
#include <iostream>

using namespace std;

CollegeClasses::CollegeClasses(string name, int num, int hour) {
	className = name;
	numOfStudents = num;
	classHours = hour;
}

friend ostream& operator<<(ostream& output, const CollegeClasses& D) {
	output << "Class Name : " << D.className << ", Num of Studets : " << D.numOfStudents << ", Class hours : " << D.classHours;
	return output;
}

friend istream& operator>>(istream& input, CollegeClasses& D) {
	cout << "Enter Name of Class : ";
	input >> D.className;
	cout << "Enter the class Hours : ";
	input >> D.classHours;
	return input;
}