// LAB WORK 8.1 Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using namespace std;

int main()
{
    // Declaring array of 50 components type double
    double alpha[50];

    // Initialize first 25 components equal to the square of index variable
    for (int i = 0; i < 25; i++) {
        alpha[i] = i * i;
    }

    // Last 25 components are equal to three times the index variable
    for (int i = 25; i < 50; i++) {
        alpha[i] = 3 * i;
    }

    // Print the array with 10 elements per line
    for (int i = 0; i < 50; i++) {
        if (i % 10 == 0) {
            cout << endl;
        }

        cout << alpha[i] << " ";
    }

}