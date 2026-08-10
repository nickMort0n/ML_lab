#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <sstream>
#include "thing.h"

using namespace std;

thing::thing() {
	this->x = "0";
	this->y = "0";
	this->z = "0";
	this->orientation = "0";
	this->next = NULL;
}

string thing::getX() {
	return this->x;
}

string thing::getY() {
	return this->y;
}

string thing::getZ() {
	return this->z;
}

thing* thing::getNext() {
	return this->next;
}

string thing::getOrientation() {
	return this->orientation;
}

void thing::setOrientation(string object) {
	this->orientation = object;
}

double thing::findDistance(thing* original, thing* point) {
	double nx = stod(this->x) - stod(point->x);
	double ny = stod(this->y) - stod(point->y);
	double nz = stod(this->z) - stod(point->z);
	double dist = sqrt((nx * nx) + (ny * ny) + (nz * nz));

	return dist;
}

thing* thing::makeThing(thing* head) {
	thing* newThing = new thing();
	return newThing;
}

string thing::whatOrientation(int orientation) {
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

string thing::findOrientation(thing* nData, thing* head) {
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

void thing::transform(vector<string> stuff, thing* head) {
	string line;
	vector<string> nLine = stuff;
	thing* current = head;
	for (int i = 0; i < stuff.size(); i++) {
		thing* node = current->makeThing(current);
		istringstream issLine(nLine[i]);

		getline(issLine, node->x, ',');
		getline(issLine, node->y, ',');
		getline(issLine, node->z, ',');
		getline(issLine, node->orientation);

		current->next = node;
		current = node;
	}
}