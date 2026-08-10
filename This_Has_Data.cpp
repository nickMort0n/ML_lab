#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <vector>
#pragma once

using namespace std;

class thing {
protected:
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

	void setOrientation(string object) {
		this->orientation = object;
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

	string whatOrientation(int orientation) {
		switch (orientation) {// case statements indented for readability
			case 1: {
				return "Face up";
			}
			case 2: {
				return "Face down";
			}
			case 3: {
				return "Portrait";
			}
			case 4: {
				return "Portrait upside down";
			}
			case 5: {
				return "Landscape left";
			}
			case 6: {
				return "Landscape right";
			}
			default: {
				return "This is not a valid input, try harder next time.";
			}
		}
	}

	string findOrientation(thing* nData, thing* head) {
		thing* holder = head->getNext();
		thing* closest = holder;

		//if the distance between the current held node is less than the current closest, the current held is the new closest
		while (holder != NULL) {
			if (nData->findDistance(nData, closest) > nData->findDistance(nData, holder)) {
				closest = holder;
			}

			holder = holder->getNext();
		}

		nData->setOrientation(closest->getOrientation()); //sets a new orientation for the wanted element

		return nData->getOrientation();
	}
};