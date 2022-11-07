#include "Students.h"

using namespace std;

int main() {

    Studentdata students[10];
    ifstream fin;
    ofstream outF;
    string fName, lName;
    string wittyComment;
    char gradeLetter;
    double calcGrade;
    int index;

    OpenFile(fin); 
    OutputFile(outF);
    ReadFile(fin, students, calcGrade, gradeLetter, wittyComment);
    Display(students, index);

    return 0;
}

int ReadFile(ifstream& fin, Studentdata students[], double& gradecalc, char& leterG, string& comment)
{   
    int numHW, numProgram, numExam;
    double totalHwPoints = 0, totalProgramPoints = 0, totalExamPoints = 0;
    double HwPercentage, ProgramPercentage, ExamPercentage;
    double grade;
    int counter = 0;

    while (!fin.eof())  // loop to read input file until end
    {

        totalHwPoints = totalProgramPoints = totalExamPoints = 0;   // resets total grades homework, program and exam

        fin >> students[counter].firstN >> students[counter].lastN >> numHW; // reads first , last name, number of hw 

        for (int i = 0; i < numHW; i++) // for loop to read then calculate hw grades
        {
            fin >> grade;
            totalHwPoints += grade;
        }

        // read the homework percent and number of program grades
        fin >> HwPercentage >> numProgram;

        for (int i = 0; i < numProgram; i++) // reads then calculates program grades
        {
            fin >> grade;
            totalProgramPoints += grade;
        }

        fin >> ProgramPercentage >> numExam; // read program percent and number of exams

        for (int i = 0; i < numExam; i++) // read and calculates exam grades
        {
            fin >> grade;
            totalExamPoints += grade;
        }

        fin >> ExamPercentage; // reads exam percents 

        Gradecalc(students, totalHwPoints, HwPercentage, ProgramPercentage, ExamPercentage,
            totalExamPoints, totalProgramPoints, numHW, numProgram, numExam, counter);
        LetterGrade(students, counter);
        Comment(students, counter);
    }

    return 0;
}

double Gradecalc(Studentdata students[], double& totalHwP, double& HwPercent, double& ProgramPercent, double& ExamPercent,
    double& totalExamP, double& totalProgramP, int& numberHW, int& numPro, int& numberExam, int& counter)
{   
    students[counter].numGrade
     = (((totalHwP / (100 * numberHW)) * HwPercent) + ((totalProgramP / (100 * numPro)) * ProgramPercent)
        + ((totalExamP / (numberExam * 100)) * ExamPercent)) * 100; 

    return students[counter].numGrade;
}

char LetterGrade(Studentdata students[], int& counter)
{   
        // if statement in order to determine Letter Grade
    if (students[counter].numGrade >= 90) {
        students[counter].letGrade = 'A';
    }
    else if (students[counter].numGrade >= 80) {
        students[counter].letGrade = 'B';
    }
    else if (students[counter].numGrade >= 70) {
        students[counter].letGrade = 'C';
    }
    else if (students[counter].numGrade >= 60) {
        students[counter].letGrade = 'D';
    }
    else if (students[counter].numGrade >= 40) {
        students[counter].letGrade = 'F';
    }
    return students[counter].letGrade;
}

string Comment(Studentdata students[], int& counter)
{
        // switch changes Letter Grade into a 'witty' comment 
    switch (students[counter].letGrade) {
    case 'A':cout << "Superb !!!" << "\n";
        break;
    case 'B':cout << "Nice work bud" << "\n";
        break;
    case 'C':cout << "Not terrible.." << "\n";
        break;
    case 'D':cout << "Pass but study more" << "\n";
        break;
    case 'E': cout << "You failed my guy" << "\n";
        break;
    
    }
    return students[counter].comment;
}

void Display(Studentdata students[], int& index)
{
    // setting the decimal placement to 2
    // cout << fixed << setprecision(2);
    // outputting the results to the console
    cout << fixed << setprecision(2) << students[index].firstN << " " << students[index].lastN << " Total Points (numerical grade): " << students[index].numGrade << " Letter Grade: " << students[index].letGrade << " " << students[index].comment << endl;

    cout << endl;
}

int OpenFile(ifstream& inD) {
    string ifileName;

    cout << "Please enter input fileName"; 
    cin  >> ifileName; 
    inD.open(ifileName);

    if (!inD) {
        cout << "Error opening file: " << ifileName << "." << endl;
        return 1;
    }
    return 0;
}

int OutputFile(ofstream& outF) {
    
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

void CloseFile(ifstream& finc, ofstream& foutc){
    finc.close();
    foutc.close();
}

