#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "This_Has_Data.cpp"

using namespace std;

inline thing* makeThing(thing* head) { //NO REASON FOR THIS TO BE IN THE THING STRUCTURE
	thing* newThing = (struct thing*)malloc(sizeof(struct thing));

	if (head->next == NULL) {
		head = newThing;
	}

	else {
		head->next = newThing;
	}

	return newThing;
}

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
	char deliminator = ',';

	vector<string> nLine = stuff;
	string token;

	for (int i = 0; i < stuff.size(); i++) {
		thing* node = makeThing(head);
		istringstream issLine(nLine[i]);

		getline(issLine, node->x, ',');
		getline(issLine, node->y, ',');
		getline(issLine, node->z, ',');
		getline(issLine, node->orientation);
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
			return "This is not a valid return type";
		}
	}
}