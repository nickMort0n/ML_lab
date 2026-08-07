#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class entry {
	double x, y, z;
	int orientation;
	struct entry* next;

public:
	entry(double x = 0, double y = 0, double z = 0, int orientation = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->orientation = orientation;
		this->next = NULL;
	}
};

class data {
	

public:
	void read(string fileName) {
		ofstream fout;

		fout.open(fileName);
		string line;

		if (fout.is_open()) {
			while (getline(fileName, line)) {
				
			}

		}
	}

	string whatOrientation(int orientation) {
		switch (orientation) {
		case '1': {
			return "This is xx";
		}
		case '2': {
			return "This is xx";
		}
		case '3': {
			return "This is xx";
		}
		case '4': {
			return "This is xx";
		}
		case '5': {
			return "This is xx";
		}
		case '6': {
			return "This is xx";
		}
		default: {
			return "This is not a valid return type";
		}
		}
		
	}
};