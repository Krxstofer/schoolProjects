#ifndef BOOKTYPE3_H
#define BOOKTYPE3_H
#include <string>

using namespace std;
    // class booktype declared
class BookType {
    // private data members
private:

    string bookTitle;
    string ISBN;
    string publisher;
    string yearPublished;
    double cost;
    int stocksAvaliable;
    int numberOfAuthors;
    string authorsList[4];
    // public data members
public:
    BookType();
    BookType(string bookTitle, string ISBN, string publisher, string yearPublished,
        double cost, int stocksAvaliable, int numberOfAuthors, string authorsList[]);
    // get functions 
    string getBookTitle();
    string getISBN();
    string getPublisher();
    string getYearPublished();
    string* getAuthorList();
    double getCost();
    int getStocksAvailable();
    int getNumberOfAuthors();
    // set functions
    void setBookTitle(string bookTitle);
    void setISBN(string ISBN);
    void setPublisher(string publisher);
    void setYearPublished(string yearPublished);
    void setAuthorList(string* authorsList);
    void setCost(double cost);
    void setStocksAvailable(int stocksAvaliable);
    void setNumberOfAuthors(int numberOfAuthors);
    // print and update function
    void printBookDetails();
    void updateStock(int quantity);
};

#endif