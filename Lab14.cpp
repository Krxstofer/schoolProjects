// Lab14.cpp : this program is illistrating the contents learned in class 
// Kristofer Norman - 12/09/2021
//1. In main, declare an integer pointer variable intPointer.Declare an
//int variable someInt.
//Assign the address of   someInt  to   intPointer
//Assign the value 451 to someInt and output(cout) the variable someInt
//and output(cout)
//the value pointed to by intPointer(contents of).
//Write an assignment statement that indirectly stores 900 into the value
//pointed to by intPointer.
//Output(cout) the value pointed to by intPointer and output(cout) the
//variable someInt,
//Declaringand using pointers with dynamic memory :
//2. Declare a char pointer variable charPointer.
//Dynamically create memory to store a charand return the address of the
//memory into the char pointer
//variable   charPointer.
//Assign the value  'A'  to the memory pointed to by charPointer(i.e.,
//    dereference operator (contents of))
//    Output(cout) the value pointed to by  charPointer(i.e., dereference
//        operator (contents of))
//    Declaring and using pointers in pointer arithmetic :
//3. Declare a pointer variable charArrPointer.
//4. Dynamically create memory to store a character array of size 3.
//5. Write assignment statements to store 'H', 'i', and '!' into the first
//three elements of
//the array POINTED to by charArrPointer.Store the values into the
//pointer charArrPointer
//using the 'de-reference' operator.  After storing 'H' and 'i',
//increment the address of
//charArrPointer by 1.
//6. Subtract 2 from the address of charArrPointer to get back to the
//beginning of the array.
//Output(cout) the data in array charArrPointer and the data in array
//initials.
//Create a simple linked list of two nodes :
//7. Create a structure named NodeType.Include the datamembers :
//an integer(num)
//a pointer that points to Nodetype(next)
//8. Create 4 Nodetype pointers.
//one to create a new node(newNode),
//one to point to the beginning of the list(first),
//one to point to the end of the list(last),
//and one to point to the current node(current).
//9. Dynamically create a new node and return the address into the NodeType
//pointer declared to
//create a new node(newNode).
//10. Assign the value 10 to the integer data member(num) .
//11. Assign the value NULL to the Nodetype pointer data member(next).
//12. Assign the pointer declared to point to the beginning of the list
//(first)
//the same address as the pointer that contains the new node(newNode).
//13. Assign the pointer declared to point to the end of the list(last) to
//the same address as the
//beginning of the list(first).
//14. Create a second node :
//Dynamically create a new node and return the address into the
//NodeType pointer(as in step 7)
//Assign the value 11 to the integer data member(as in step 9).
//Assign the value NULL to the Nodetype pointer data member(as in step
//    10).
//    Assign the address in newNode to the next data member pointed to by
//    the next pointer
//    Assign the end of list pointer(last) to the new node(newNode)
//    Assign the pointer declared to point to the current node to the
//    pointer beginning of the list(first)
//    Now you have two nodes.
//    15. Write the code to traverse the linked list and output the values of
//    the data member num.

#include <iostream>
#include <cstdlib>

using namespace std; 

int main()
{
	int * intPointer;
	int someInt; 

	intPointer = &someInt;

	someInt = 451; 
	cout << "SomeInt: " << someInt << " " << "contents of intPointer: " << *intPointer << endl;

	*intPointer = 900; 
	cout << "SomeInt: " << someInt << " " << "contents of intPointer: " << *intPointer << endl;

	char * charPointer; 

	charPointer = new char; 

	*charPointer = 'A';

	cout << "contents of charPointer: " << *charPointer << endl;

	delete charPointer; 
	charPointer = nullptr; 

	char * charArrPointer; 

	charArrPointer = new char[3]; 

	*charArrPointer = 'H'; 
	charArrPointer++; 
	*charArrPointer = 'M';
	charArrPointer++; 
	*charArrPointer = '!';

	charArrPointer -= 2;

	for (int i = 0; i < 3; i++) {

		cout << "contents of charArrPointer: " << *charArrPointer << endl; 
		charArrPointer++; 
	}

	cout << endl << endl; 

	struct nodeType {

		int info;
		nodeType * next; 

	};

	nodeType* newNode, * first, * last, * current;

	newNode = new nodeType;
	newNode->info = 10; 
	newNode->next = NULL; 
	
	first = newNode;
	last = newNode; 

	newNode = new nodeType; 
	newNode->info = 11;
	newNode->next = NULL; 

	last->next = newNode; 
	last = newNode; 

	current = first;
	while (current != NULL) {
		cout << "Info : " << current->info << " ";
		current = current->next;
	}

}