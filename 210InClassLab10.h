

#include <iostream>

using namespace std;

class romanNumbers {

public: 
	
	// default constructor 
	romanNumbers();
	romanNumbers(string romanL);
	bool setRomaNumbers(string Roman, int Values);
	void printValue(int IntVal);
	int convertRoman(string Roman,int Value);
	void printRoman(string);
	void printBoth(string, int);
private:
	string RomanNum;
	int ConvertVal = 0;

};