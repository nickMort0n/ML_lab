#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "This_Has_Data.cpp"

using namespace std;
thing head;

class NN {
public:
	void read() {
		string fileName;
		ifstream file;

		cout << "Enter the name of the file: ";
		cin >> fileName;
		file.open(fileName); //hard coded to trainingData because this is only for training

		if (file.fail()) {
			cout << "Training file failed to open";
			return;
		}
		thing newThing = head;
		if (file.is_open()) {
			while (!file.eof()) {
				string line;
				getline(file, line);
				istringstream issLine(line);
				getline(issLine, newThing.x, ','); //turns up to the first comma into the x coordinate
				getline(issLine, newThing.y, ','); //turns up to the first comma into the y coordinate
				getline(issLine, newThing.z, ','); //turns up to the first comma into the z coordinate
				getline(issLine, newThing.orientation);
				newThing = newThing->next;
			}
		}

		//vector<string> contents;
		//string line;

		//while (!file.eof()) {
		//	getline(file, line);
		//	contents.push_back(line); //last line read pushed to the back of the vector
		//}

		file.close();

		//for (auto file_line : contents) {
		//	cout << file_line << endl;
		//}
	}
};

//put this function somewhere else
/*string whatOrientation(int orientation) {
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
	}*/