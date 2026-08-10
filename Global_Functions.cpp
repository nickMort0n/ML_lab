#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "This_Has_Data.cpp"

using namespace std;

inline vector<string> train() {
	ifstream file;

	file.open("trainingData.txt"); //hard coded to trainingData because this is only for training

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

inline void transform(vector<string> stuff, thing* head) {
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

//put this function somewhere else
inline string whatOrientation(int orientation) {
	switch (orientation) {// case statements indented for readability
		case '1': {
			return "This is face up";
		}
		case '2': {
			return "This is face down";
		}
		case '3': {
			return "This is portrait";
		}
		case '4': {
			return "This is portrait upside down";
		}
		case '5': {
			return "This is landscape left";
		}
		case '6': {
			return "This is landscape right";
		}
		default: {
			return "This is not a valid input, try harder next time.";
		}
	}
}