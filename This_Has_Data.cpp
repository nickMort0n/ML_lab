#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class thing {
public:
	string x, y, z;
	string orientation;
	struct thing* next;

	thing(double x = 0, double y = 0, double z = 0, int orientation = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->orientation = orientation;
		this->next = NULL;
	}

	thing* makeThing(thing* head) {
		thing newThing(0, 0, 0, 0);
		head->next = &newThing;
	}
};