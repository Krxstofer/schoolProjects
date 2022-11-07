// 210Program2.cpp .
// Written by : Kristofer Norman
// Date : 3/7/2022
// Input : Requests input file from user (bookData.txt provided)
// Description : This Program demonstartes the use of classes

#include<iostream>
#include<string>
#include <fstream>
#include"BookType3.h"
#include"BookFormat3.h"
#include"Client3.h"

using namespace std;
// global space
int counter = 0;

BookFormat books[50];

int main() {

    string filename;
    cout << "Please enter filename: ";
    cin >> filename;
    cout << "\n";

    if (loadData(filename))
        cout << "Number of books loaded: " << counter << "\n";
    else {
        cout << "Unable to open file\n";
        return 0;
    }

    char choice = 'i';
    // do while function for choosing menu
    do {
        printf("\nEnter your selection\n");
        printf("\t 1: Search a book by title\n");
        printf("\t 2: Search a book by ISBN\n");
        printf("\t 3: Search a book by Author\n");
        printf("\t 4: Update book stock\n");
        printf("\t 5: Print books in stock\n");
        printf("\t 6: Print all books\n");
        printf("\t 7: Sell books\n");
        printf("\t 8: Quit\n");

        cin >> choice;
        executeAction(choice);
    } while (choice != '7');

    return 0;
}

void searchMessage(int index) {
    if (index != -1) {
        cout << "Book Found\n";
        books[index].printBookDetails();
    }
    else {
        cout << "Book not found\n";
    }
}

void executeAction(char c) {

    string input;

    switch (c) {
    case '1':
        cout << "Enter book title: \n";
        cin >> input;
        searchMessage(searchByBooKTitle(input));
        break;
    case '2':
        cout << "Enter ISBN number: \n";
        cin >> input;
        searchMessage(searchByISBN(input));
        break;
    case '3':
        cout << "Enter author name: \n";
        cin >> input;
        searchMessage(searchByBookAuthor(input));
        break;
    case '4':
        cout << "How do you want to search ?\n";
        cout << "[1] Book title\n";
        cout << "[2] ISBN number\n";
        cout << "[3] Author Name\n";
        cin >> c;
        if (c == '1') {
            cout << "Enter book title\n";
        }
        else if (c == '2') {
            cout << "Enter ISBN number\n";
        }
        else if (c == '3') {
            cout << "Enter author name\n";
        }
        cin >> input;
        if (searchAndUpdate(c, input)) {
            cout << "Stock updated successfully\n";
        }
        else {
            cout << "Failed to update stock\n";
        }
        break;
    case '5':
        printBooksInStock();
        break;
    case '6':
        printAllBooks();
        break;
    case '7':
        //sellAndUpdateBooks();
        break;
    case '8':
        break;
    default:
        printf("\nERROR!Please enter a valid input\n");
        cin >> c;
        break;
    }
}
// grabs data
bool loadData(string filename) {
    string authorsList[4];
    string FormatList[4];
    string bookTitle, ISBN, publisher, yearPublished;
    int stocksAvaliable, numberOfAuthors, numberOfFormats, numberOfPages;
    double cost;

    try {

        ifstream cin(filename.c_str());

        if (!cin.good())
            return false;

        // ws gets white spaces 
        while (getline(cin >> ws, bookTitle)) {

            getline(cin >> ws, ISBN);
            getline(cin >> ws, publisher);
            getline(cin >> ws, yearPublished);

            cin >> cost;
            cin >> stocksAvaliable;
            cin >> numberOfAuthors;

            for (int i = 0; i < numberOfAuthors; i++) {
                getline(cin >> ws, authorsList[i]);
            }

            cin >> numberOfFormats;
            for (int i = 0; i < numberOfFormats; i++) {
                getline(cin >> ws, FormatList[i]);
            }
            cin >> numberOfPages;

            // reading the data into array "books"
            books[counter].setBookTitle(bookTitle);
            books[counter].setISBN(ISBN);
            books[counter].setPublisher(publisher);
            books[counter].setYearPublished(yearPublished);
            books[counter].setCost(cost);
            books[counter].setNumberOfAuthors(numberOfAuthors);
            books[counter].setStocksAvailable(stocksAvaliable);
            books[counter].setAuthorList(authorsList);
            books[counter].setNumberOfFormats(numberOfFormats);
            books[counter].setWhichFormat(FormatList);
            books[counter].setNumberOfPages(numberOfPages);

            counter += 1;
        }

        return true;
    }
    catch (...) {
        return false;
    }
    return false;
}

bool searchAndUpdate(char choice, string identifier) {
    int quantity = 0, index = -1;

    cout << "Enter the quantity\n";
    cin >> quantity;

    if (choice == '1') {
        index = searchByBooKTitle(identifier);
    }
    else if (choice == '2') {
        index = searchByISBN(identifier);
    }
    else if (choice == '3') {
        index = searchByBookAuthor(identifier);
    }

    searchMessage(index);

    if (index == -1) return false;

    books[index].updateStock(quantity);

    return true;
}

int searchByBooKTitle(string bookTitle) {
    for (int i = 0; i < counter; i++) {
        if (books[i].getBookTitle() == bookTitle) {
            return i;
        }
    }
    return -1;
}

int searchByBookAuthor(string authorName) {
    for (int i = 0; i < counter; i++) {
        int cnt = 4;
        string* authorsList = books[i].getAuthorList();
        while (cnt--) {
            if (authorsList[cnt - 1] == authorName) {
                return i;
            }
        }
    }
    return -1;
}

int searchByISBN(string ISBN) {
    for (int i = 0; i < counter; i++) {
        if (books[i].getISBN() == ISBN) {
            return i;
        }
    }
    return -1;
}

void printBooksInStock() {
    for (int i = 0; i < counter; i++) {
        if (books[i].getStocksAvailable() > 0) {
            books[i].print();
        }
    }
}

void printAllBooks() {
    for (int i = 0; i < counter; i++) {
        books[i].print();
    }
}