#include <string>
#include <iostream>
#include <memory>
#include "BookFormat3.h"

BookFormat::BookFormat() {
    this->numberOfFormats = 0;
    for (int i = 0; i < 3; i++)
        this->FormatList[i] = "NA";
    this->numberOfPages = 0;
}

BookFormat::BookFormat(int numberOfFormats, string[], int numberOfPages) {
    this->numberOfFormats = numberOfFormats;
    for (int i = 0; i < numberOfFormats; i++)
        this->FormatList[i] = FormatList[i];
    this->numberOfPages = numberOfPages;
}

int BookFormat::getNumberOfFormats() {
    return this->numberOfFormats;
}

string* BookFormat::getWhichFormat() {
    return this->FormatList;
}

int BookFormat::getNumberofPages() {
    return this->numberOfPages;
}

void BookFormat::setNumberOfFormats(int numberOfFormats) {
    this->numberOfFormats = numberOfFormats;
}

void BookFormat::setWhichFormat(string* FormatList) {
    for (int i = 0; i < this->numberOfFormats; i++) {
        this->FormatList[i] = FormatList[i];
    }
}

void BookFormat::setNumberOfPages(int numberOfPages) {
    this->numberOfPages = numberOfPages;
}
void BookFormat::print() {
    BookType::printBookDetails();
    cout << "Formats: \n";
    for (int i = 0; i < this->numberOfFormats; i++)
    cout << "\t" << this->FormatList[i] << "\n";      
    cout << "Number of Pages: " << this->numberOfPages << "\n";
    cout << "------------------------------";
    cout << "\n";
}