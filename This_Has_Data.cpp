#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct thing {
	string x, y, z;
	string orientation;
	thing *next;

	thing(double x = '0', double y = '0', double z = '0', int orientation = '0') {
		this->x = x;
		this->y = y;
		this->z = z;
		this->orientation = orientation;
		this->next = NULL;
	}

	thing* makeThing(thing* head) {
		thing* newThing;

		if (head->next == NULL) {
			head = newThing;
		}
		else {
			head->next = newThing;
		}

		return newThing;
	}
};