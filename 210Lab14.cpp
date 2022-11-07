// 210Lab14.cpp : This lab exercises understanding of some concepts covered 
// in Chapter 14 -> e.g exception handling
// Kristofer Norman , 04/19/2022

#include <iostream>

#include <limits>

#define CENTIMETER 2.54

using namespace std;

int getInches(int low)
{
    int num;
    // check if input is valid or not
    if (!(cin >> num) || (num <= low))
    {
        // clear the cin data
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        throw "The number is out of bounds: Try again : ";
    }
    return num;
}

int main()
{
    int inches = 0;
    cout << "Enter a length in feet and inches : ";
    while (1)
    {
        try
        {
            inches = getInches(0);
            cout << "Feet-inch input values to centimeter conversion value : " << (inches * CENTIMETER) << endl;
            break;
        }
        catch (const char* str)
        {
            cout << str;
        }
    }
    return 0;
}