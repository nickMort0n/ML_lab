#pragma once
#include "This_Has_Data.cpp" //strings weren't working when it was only #include <string> or #include "string"

class thing {
protected:
	string x;
	string y;
	string z;
	string orientation;
	thing* next;

public:
	thing* getNext();
	string getOrientation();
	void setOrientation(string);
	double findDistance(thing*, thing*);
	thing* makeThing(thing*);
	string whatOrientation(int orientation);
	string findOrientation(thing*, thing*);
};