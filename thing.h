#ifndef THING_H
#define THING_H
#include <string> //strings weren't working when it was only #include <string> or #include "string"

using namespace std;

class thing {
protected:
	string x, y, z;
	string orientation;
	thing* next;

public:
	thing();
	string getX();
	string getY();
	string getZ();
	thing* getNext();
	string getOrientation();
	void setOrientation(string);
	double findDistance(thing*, thing*);
	thing* makeThing(thing*);
	string whatOrientation(int orientation);
	string findOrientation(thing*, thing*);
	void transform(vector<string>, thing*);
};
#endif