#pragma once
#include <string>

using namespace std;

class list {
public:
	string getWord() const;
	void setWord(string);
	list* getNext();
	void setNext(list*);

private:
	string aWord;
	list* Next;
};