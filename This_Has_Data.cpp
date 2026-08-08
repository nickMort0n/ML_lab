#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class data {
	double x, y, z;
	int orientation;
	struct data* next;

public:
	data(double x = 0, double y = 0, double z = 0, int orientation = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->orientation = orientation;
		this->next = NULL;
	}
};