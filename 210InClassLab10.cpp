// 210InClassLab10.cpp : Kristofer Norman 02/08/2022
//

#include <iostream>
#include "210InClassLab10.h"

int main()
{
    romanNumbers romanNumeral;
    string RomanNumerals;
    int ConvertedVal{};
    
    romanNumeral.setRomaNumbers(RomanNumerals, ConvertedVal);
    romanNumeral.printValue(ConvertedVal);
    romanNumeral.printRoman(RomanNumerals);

    cout << "Roman Numerals kind of work weird" << endl;

    return 0;

}
