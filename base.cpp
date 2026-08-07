#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class entry {
	double x, y, z;
	int orientation;
	struct entry* next;

public:
	entry(double x, double y, double z, int orientation) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->orientation = orientation;
		this->next = NULL;
	}
};

class data {
	

public:
	void read(FILE* file) {
		string fileName = "trainingData.txt";
		ofstream fout;

		fout.open(fileName);
		string line;

		if (fout.is_open()) {
			while (getline(fileName, line)) {
				
			}

		}
	}
};