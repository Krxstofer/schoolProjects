#pragma once

using namespace std;

struct StudentInfo
{
	string firstN;
	string lastN;
	char testAns[20];
	double score;
	char letGrade;
};

int OpenFiles(ifstream&, ofstream&);
void CloseFile(ifstream&, ofstream&);
int Readit(ifstream&, StudentInfo[]);
//char LetterGrade(StudentInfo[], int&);
//void Displayit(StudentInfo[], int&);