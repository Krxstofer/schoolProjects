// student class declaration

#include <string>

using namespace std;


class Students {
private:
	string firstN;
	string lastN;
	string address;
	string city;
	string state;
	string zip;
	float earnedGpoints;
	float attemptCredhours;
	float gpa;
public:
	Students();
	Students(string, string, string, string, string, string);
	Students(string, string, string, string, string, string, float, float);
	void StudentsGPAcalc();
	void StudentsGPAcalc(float, float);
	void setEarnedValue(float);
	void setAttemptValue(float);
	void Display() const; 
};