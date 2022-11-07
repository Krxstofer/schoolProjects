// Kristofer Norman 02/07/2022 
// This program demonstrates opening a file, storing data into a structure,
// and outputting the data stored. 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "210Program1.h"

using namespace std;

int main() {
    StudentInfo students[30];
    ifstream inFile;
    ofstream outFile;

    OpenFiles(inFile, outFile);
    Readit(inFile, students);
}

int OpenFiles(ifstream& inF, ofstream& outF) {
    string ifileName;

    cout << "Please enter input fileName";
    cin >> ifileName;
    inF.open(ifileName);

    if (!inF) {
        cout << "Error opening file: " << ifileName << "." << endl;
        return 1;
    }

    string ofileName;

    cout << "Please enter output filename";
    cin >> ofileName;
    outF.open(ofileName);

    if (!outF) {
        cout << "Error opening file: " << ofileName << "." << endl;
        return 1;
    }
    return 0;
}
 
int Readit(ifstream& inputF, StudentInfo students[]) {
    int counter = 0;
    char KEY[20];


    inputF >> KEY;
    // loop reading the file
    while (!inputF.eof()) {
        inputF >> students[counter].firstN >> students[counter].lastN;
        inputF.get();
        for (int i = 0; i < 20; i++)
            inputF.get(students[counter].testAns[i]);
        counter++;
    }
    // loop for getting the test scores
    for (int i = 0; i < counter; i++) {
        students[i].score = 0;
        for (int k = 0; k < 20; k++)
            if (students[i].testAns[k] == KEY[k])
                students[i].score = students[i].score + 5;
    }
    // loop for getting the letter grade 
    for (int i = 0; i < counter; i++) {
        if (students[counter].score >= 90.00) {
            students[counter].letGrade = 'A';
        }
        else if (students[counter].score >= 80.00) {
            students[counter].letGrade = 'B';
        }
        else if (students[counter].score >= 70.00) {
            students[counter].letGrade = 'C';
        }
        else if (students[counter].score >= 60.00) {
            students[counter].letGrade = 'D';
        }
        else if (students[counter].score >= 40.00) {
            students[counter].letGrade = 'F';
        }
        else if (students[counter].score <= 40.00) {
            students[counter].letGrade = 'F';
        }
    }
    cout << setw(55) << "-------- My little class and their Grades ---------" << endl;
    cout << setw(9) << "Name :" << setw(15) << "Grade :" << setw(10) << "Score :" << setw(17) << " Test Answers :" << '\n' << endl;
    for (int i = 0; i < counter; i++) {
        cout << setw(7) << students[i].firstN << " " << setw(7) << students[i].lastN << setw(6) << students[counter].letGrade
            << " " << fixed << setprecision(2) << setw(10) << students[i].score << setw(28) << students[i].testAns << '\n' << endl;
    }

    return 0;
}

void CloseFile(ifstream& finc, ofstream& foutc) {
    finc.close();
    foutc.close();
}