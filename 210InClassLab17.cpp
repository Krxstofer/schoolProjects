// 210InClassLab17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

//node structure
struct node
{
    int data;
    struct node* next;
};
struct node typedef LLNode;

LLNode* head = NULL;

//function creates and returns a new node
LLNode* createNode(int data)
{
    LLNode* newNode = (LLNode*)malloc(sizeof(LLNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function inserts value into linked list
void insert(int value)
{
    LLNode* newNode = createNode(value);

    //If list is empty make newNode as head
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    //If value is less than head then make newNode as head
    if (value < head->data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    LLNode* temp = head;
    //Iterate untill list ends or we have inserting position
    while (temp->next != NULL && value >= temp->next->data)
    {
        temp = temp->next;
    }
    //Insert node
    newNode->next = temp->next;
    temp->next = newNode;
}

// function searches corresponding values
void search(int value)
{
    LLNode* temp = head;
    //Iterate list
    while (temp)
    {
        //If found
        if (temp->data == value)
        {
            cout << value << " found" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << value << " not found" << endl;
}
//function delets node with value
void deleteNode(int value)
{
    //If list is empty
    if (head == NULL)
    {
        cout << "Linked list is empty, we cannot delete" << endl;
        return;
    }
    //If head node has value then delete head
    if (head->data == value)
    {
        cout << "Deleting " << value << endl;
        LLNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    LLNode* temp = head;
    //Iterate till end of list or greater than value found
    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }
    //If list is empty or greater or equal value found
    if (temp->next == NULL || !temp->next->data >= value)
    {
        cout << value << " not found in linkedlist so deletion is not possible" << endl;
        return;
    }
    //If value found
    cout << "Deleting " << value << endl;
    LLNode* dummy = temp->next;
    temp->next = temp->next->next;
    free(dummy);
}

void display()
{
    cout << "Data in linkedlist: ";
    LLNode* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    //File reading
    fstream infile("input.txt");
    //File invalidation
    if (!infile.is_open())
    {
        cout << "file not found";
        return 0;
    }

    string choice;
    int value;
    while (infile >> choice)
    {
        infile >> value;
        switch (choice[0])
        {
        case 'I':
            insert(value);
            break;
        case 'D':
            deleteNode(value);
            break;
        case 'S':
            search(value);
            break;
        }
    }
    display();
    infile.close();
    return 0;
}