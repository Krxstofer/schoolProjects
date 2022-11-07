
//**********************************************************
// Author: D.S. Malik
// 
// Implementation file personTypeImp.cpp
// This file contains the definitions of the functions to 
// implement the operations of the class personType.
//**********************************************************
  
#include <iostream>
#include <string>
#include "personType.h"

using namespace std;

void personType::print() const
{
    cout << firstName << " " << lastName;
}

void personType::setName(string first, string last)
{
    firstName = first;
    lastName = last;
}

string personType::getFirstName() const
{
    return firstName;
}

string personType::getLastName() const
{
    return lastName;
}

	//constructor
personType::personType(string first, string last) 
{ 
    firstName = first;
    lastName = last;
}

// patienType inherited class

patientType::patientType(int id, int age, int birth, int aDate, int dDate)
{
    numberID = id;
    Age = age;
    birthDate = birth;
    admissionDate = aDate;
    dischargeDate = dDate;
}

void patientType::setID(int id)
{
    numberID = id;
}

int patientType::getID(int id)
{
    return id;
}