#ifndef BOOKFORMAT3_H
#define BOOKFORMAT3_H
#include <string>
#include "BookType3.h"

using namespace std;

class BookFormat :public BookType {

public:
    BookFormat();
    BookFormat(int, string[], int);
    // get functions
    int getNumberOfFormats();
    string* getWhichFormat();
    int getNumberofPages();
    // set functions
    void setNumberOfFormats(int numberOfFormats);
    void setWhichFormat(string* FormatList);
    void setNumberOfPages(int numberOfPages);
    void print();
private:
    int numberOfFormats;
    string FormatList[3];
    int numberOfPages;

};

#endif 