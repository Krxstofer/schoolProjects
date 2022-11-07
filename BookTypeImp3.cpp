#include <string>
#include <iostream>
#include <memory>
#include "BookType3.h"

using namespace std;

BookType::BookType() { //using this pointer to refer to objects adress
    this->bookTitle = "NA";
    this->ISBN = "NA";
    this->publisher = "NA";
    this->yearPublished = "NA";
    this->cost = 0.0;
    this->stocksAvaliable = 0;
    this->numberOfAuthors = 0;
    for (int i = 0; i < 4; i++)
        this->authorsList[i] = "NA";
}

BookType::BookType(string bookTitle, string ISBN, string publisher, string yearPublished,
    double cost, int stocksAvaliable, int numberOfAuthors, string authorsList[]) {
    // declaring said objects
    this->bookTitle = bookTitle;
    this->ISBN = ISBN;
    this->publisher = publisher;
    this->yearPublished = yearPublished;
    this->cost = cost;
    this->stocksAvaliable = stocksAvaliable;
    this->numberOfAuthors = numberOfAuthors;
    for (int i = 0; i < this->numberOfAuthors; i++)
        this->authorsList[i] = authorsList[i];
}

string BookType::getBookTitle() {
    return this->bookTitle;
}
string BookType::getISBN() {
    return this->ISBN;
}
string BookType::getPublisher() {
    return this->publisher;
}
string BookType::getYearPublished() {
    return this->yearPublished;
}
string* BookType::getAuthorList() {
    return this->authorsList;
}
double BookType::getCost() {
    return this->cost;
}
int BookType::getStocksAvailable() {
    return this->stocksAvaliable;
}
int BookType::getNumberOfAuthors() {
    return this->numberOfAuthors;
}

void BookType::setBookTitle(string bookTitle) {
    this->bookTitle = bookTitle;
}
void BookType::setISBN(string ISBN) {
    this->ISBN = ISBN;
}
void BookType::setPublisher(string publisher) {
    this->publisher = publisher;
}
void BookType::setYearPublished(string yearPublished) {
    this->yearPublished = yearPublished;
}
void BookType::setAuthorList(string* authorsList) {
    for (int i = 0; i < this->numberOfAuthors; i++) {
        this->authorsList[i] = authorsList[i];
    }
}
void BookType::setCost(double cost) {
    this->cost = cost;
}
void BookType::setStocksAvailable(int stocksAvaliable) {
    this->stocksAvaliable = stocksAvaliable;
}
void BookType::setNumberOfAuthors(int numberOfAuthors) {
    this->numberOfAuthors = numberOfAuthors;
}

void BookType::printBookDetails() {
    cout << "Book Title: " << this->bookTitle << "\n";
    cout << "ISBN: " << this->ISBN << "\n";
    cout << "Publisher: " << this->publisher << "\n";
    cout << "Cost: " << this->cost << "\n";
    cout << "Year Published: " << this->yearPublished << "\n";
    cout << "Stocks avaliable: " << this->stocksAvaliable << "\n";
    cout << "Number of Authors: " << this->numberOfAuthors << "\n";
    cout << "Authors: \n";
    for (int i = 0; i < this->numberOfAuthors; i++)
    cout << "\t" << this->authorsList[i] << "\n";
}

void BookType::updateStock(int quantity) {
    this->stocksAvaliable += quantity;
}

