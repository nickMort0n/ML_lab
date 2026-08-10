#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "This_Has_Data.cpp"

using namespace std;

class NN : protected thing {
	//NN* head;

public:
	NN(string x = "0", string y = "0", string z = "0", string orientation = "0") {
		this->x = x; //stod to turn a string into a double
		this->y = y;
		this->z = z;
		this->orientation = orientation;
		this->next = NULL;
	}

	vector<string> train(string fileName) {
		ifstream file;

		file.open(fileName);

		if (file.fail()) {
			cout << "Training file failed to open";
		}

		vector<string> data;
		string line;

		while (!file.eof()) {
			getline(file, line);
			data.push_back(line); //last line read pushed to the back of the vector
		} //after the loop the vector contains the entire file

		file.close();

		return data;
	}

	void transform(vector<string> stuff, thing* head) {
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

	void printToFile(string fileName, thing* head) {
		vector<string> stuff = train(fileName);
		transform(stuff, head);
		thing* current = head->getNext();

		string holderFile = "result.txt";
		ofstream file;
		file.open(holderFile);
		if (file.is_open()) {
			while (current != NULL) {
				file << current->x << current->y << current->z << findOrientation(current, head) << current->whatOrientation(stoi(findOrientation(current, head))) << endl;
			}
		}
	}
};