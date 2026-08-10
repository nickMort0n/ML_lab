#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
#pragma once

using namespace std;

struct thing { //variables need to be public for the NN method to find them so theres no reason for this to be a struct
	string x, y, z;
	string orientation;
	thing *next;

	thing(string x = "0", string y = "0", string z = "0", string orientation = "0") {
		this->x = x; //stod to turn a string into a double
		this->y = y;
		this->z = z;
		this->orientation = orientation;
		this->next = NULL;
	}

	double findDistance(thing* original, thing* point) {
		double nx = stod(this->x) - stod(point->x);
		double ny = stod(this->y) - stod(point->y);
		double nz = stod(this->z) - stod(point->z);
		double dist = sqrt((nx * nx) + (ny * ny) + (nz * nz));

		return dist;
	}
};