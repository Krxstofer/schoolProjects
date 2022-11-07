#include <iostream>

#include "Students.h"


using namespace std;

int main() {
	Students stu1;
	Students stu2("Bob", "Jackturner", "883 nowhere road", "Virginia Beach", "Virginia", "23463");
	Students stu3("Welks", "Housings", "236 somehwere street", "Houston", "Texas", "35008", 36.00, 12.00);

	stu1.Display;
	stu2.Display;
	stu3.Display;
	
	stu3.setAttemptValue(12.00);
	stu3.setEarnedValue(36.00);

	stu3.StudentsGPAcalc(36.00, 12.00);

	stu3.StudentsGPAcalc();

	stu3.Display();

}

