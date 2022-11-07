// Lab12.cpp : Kristofer Norman 
// 02/01/2022

#include <iostream>

using namespace std;

int main()
{
	int x, y;
	int *p, *q;

	x = 2;
	y = 8;
	p = &x;
	q = &y;

	cout << "The adress of x : " << &x << " " << "The value of x : " << x << endl;
	cout << "The value of p : " << p << " " << "The value of *p" << *p << endl;
	cout << "The adress of y : " << &y << " " << "The value of y : " << y << endl;
	cout << "The value of q : " << q << " " << "The value of *q : " << *q << endl;
	cout << "The adress of p : " << &p << endl;
	cout << "The adress of q : " << &q << endl;

	char s[10] = "abcde";
	char * cptr;
	cptr = s;

	cout << *cptr;

	while (*cptr) {
		cptr;
		cout << *cptr;
	}
	
	return 0;

}

