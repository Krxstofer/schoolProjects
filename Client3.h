#ifndef CLIENT_H3
#define CLIENT_H3
#include <string>

using namespace std;
// functions for menu 
bool loadData(string filename);
int searchByBooKTitle(string bookTitle);
int searchByBookAuthor(string authorName);
int searchByISBN(string ISBN);
// printing functions 
void printBooksInStock();
void printAllBooks();
// updating functions
void executeAction(char c);
bool searchAndUpdate(char choice, string identifier);
bool sellAndUpdateBooks(char choice, string identifier);
#endif