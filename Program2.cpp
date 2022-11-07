// *****************************************
// Program Name: Program2.cpp
// Written by Kristofer Norman 10/17/2021
// i/o file streams
// This program will calculate numerical and letter grades for a student and output a report 
// *****************************************
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    string in_filename, out_filename;
    ifstream fin;
    ofstream fout;

    cout<<"Enter the input filename: "; 
    cin>>in_filename;
    fin.open(in_filename); // open the input file


    if(fin.fail())  // if statement checking that input file opened 
    {
    cout<<"Unable to open input file: "<<in_filename<<". Exiting application"<<endl;
    return 1;
    }

    cout<<"Enter the output filename: ";  
    cin>>out_filename;
    fout.open(out_filename); // open the output file

    if(fout.fail())  // if statement checking that output file opened
    {
    cout<<"Could not open output file: "<<out_filename<<". Now Exiting application"<<endl;
    return 1;
    }

    // defining variables 
    string fName, lName;
    int numHW, numProgram, numExam;
    double totalHwPoints = 0, totalProgramPoints = 0, totalExamPoints = 0;
    double HwPercentage, ProgramPercentage, ExamPercentage;
    double grade;
    double averageGrade;
    char letterGrade;

    while(!fin.eof())  // loop to read input file until end
    {

    totalHwPoints = totalProgramPoints = totalExamPoints = 0;   // resets total grades homework, program and exam

    fin>>fName>>lName>>numHW; // reads first , last name, number of hw 

    for(int i=0;i<numHW;i++) // for loop to read then calculate hw grades
    {
    fin>>grade;
    totalHwPoints += grade;
    }

    // read the homework percent and number of program grades
    fin>>HwPercentage>>numProgram;

    for(int i=0;i<numProgram;i++) // reads then calculates program grades
    {
    fin>>grade;
    totalProgramPoints += grade;
    }

    fin>>ProgramPercentage>>numExam; // read program percent and number of exams

    for(int i=0;i<numExam;i++){ // read and calculates exam grades
        
        fin>>grade;
        totalExamPoints += grade;
        }

    fin>>ExamPercentage; // reads exam percents 

    // average grade in order calculate total Grade
    averageGrade = (((totalHwPoints/(100*numHW))*HwPercentage) + ((totalProgramPoints/(100*numProgram))*ProgramPercentage) + ((totalExamPoints/(numExam*100))*ExamPercentage))*100;

    // if statement in order to determine Letter Grade
    if(averageGrade >= 90){
    letterGrade = 'A';
    }
    else if(averageGrade >= 80){
    letterGrade = 'B';
    }
    else if(averageGrade >= 70){
    letterGrade = 'C';
    }
    else if(averageGrade >= 60){
    letterGrade = 'D';
    }
    else {
    letterGrade = 'F';
    }
    // switch changes Letter Grade into a 'witty' comment 
    switch (letterGrade) {
        case 'A':cout <<"Superb !!!"<<"\n";
                break;
        case 'B':cout<<"Nice work bud"<<"\n";
        break;
        case 'C':cout<<"Not terrible.."<<"\n";
        break;
        case 'D':cout<<"Pass but study more"<<"\n";
        break;
        default: cout<<"You failed my guy"<<"\n";
        break;

    }
    // setting the decimal placement to 2
    cout<<fixed<<setprecision(2);
    fout<<fixed<<setprecision(2);
    // outputting the results to the console
    cout<<endl<<fName<<" "<<lName<<" Total Points (numerical grade): "<<averageGrade<<" Letter Grade: "<<letterGrade<<" = " << endl;
    fout<<fName<<" "<<lName<<" Total Points (numerical grade): "<<averageGrade<<" Letter Grade: "<<letterGrade<<" = "<<endl;

    cout<<endl;

    // closing files
    fin.close();
    fout.close();


    return 0;
}