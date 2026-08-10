#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <vector>
#pragma once

using namespace std;

class thing {
private:
	string x, y, z;
	string orientation;
	thing *next;
public:
	thing(string x = "0", string y = "0", string z = "0", string orientation = "0") {
		this->x = x; //stod to turn a string into a double
		this->y = y;
		this->z = z;
		this->orientation = orientation;
		this->next = NULL;
	}

	thing* getNext() {
		return this->next;
	}

	string getOrientation() {
		return this->orientation;
	}

	int setOrientation(string object) {
		return stoi(object);
	}

	double findDistance(thing* original, thing* point) {
		double nx = stod(this->x) - stod(point->x);
		double ny = stod(this->y) - stod(point->y);
		double nz = stod(this->z) - stod(point->z);
		double dist = sqrt((nx * nx) + (ny * ny) + (nz * nz));

		return dist;
	}

	thing* makeThing(thing* head) {
		thing* newThing = new thing();
		return newThing;
	}

	friend void transform(vector<string> stuff, thing* head);
};