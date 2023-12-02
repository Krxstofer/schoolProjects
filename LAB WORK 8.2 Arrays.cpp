#include <iostream>

using namespace std;

// Functoin takes int array and its size and returns index of first occurrence of the smallest element in array.
int smallestIndex(int arr[], int size) {
	int index = 0;
	int smallest = arr[0];

	for (int i = 0; i < size; i++) {
		if (arr[i] < smallest) {
			index = i;
		}
	}
	return index;

}

int main() {

	int numArray[15];

	cout << "Enter 15 integers:" << endl;

	for (int i = 0; i < 15; i++) {
		cin >> numArray[i];
	}

	for (int i = 0; i < 15; i++) {
		cout << numArray[i] << " ";
	}

	cout << endl;
	int index = smallestIndex(numArray, 15);
	cout << "The position of the first occurence of the smallest element in list is: " << index << endl;
	cout << "The smallest element in list is: " << numArray[index] << endl;


	return 0;
}