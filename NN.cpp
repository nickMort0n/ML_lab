#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "thing.h"
#include "NNClassifier.h"

using namespace std;

NN::NN() {
	this->x = "0";
	this->y = "0";
	this->z = "0";
	this->orientation = "0";
	this->next = NULL;
}

NN* NN::thingToNN(thing* thing) {
	NN* nNN = new NN();
	nNN->x = thing->getX();
	nNN->y = thing->getY();
	nNN->z = thing->getZ();
	nNN->orientation = thing->getOrientation();
	nNN->next = thing->getNext();
	return nNN;
}

vector<string> NN::train(string fileName) {
	ifstream file;

	file.open(fileName);

	if (file.fail()) {
		cout << "Training file failed to open";
	}

	vector<string> data; //string vector to contain all data
	string line;

	while (getline(file, line)) {
		getline(file, line);
		data.push_back(line); //last line read pushed to the back of the vector
	} //after the loop the vector contains the entire file

	file.close();

	return data;
}

void NN::printToFile(string fileName, NN* head) {
	vector<string> stuff = train(fileName);
	transform(stuff, head);
	thing* current = head->getNext();

	string holderFile = "result.txt";
	ofstream file;
	int memSaver = stoi(findOrientation(current, head)); //only runs findOrientation once instead of twice
	file.open(holderFile); //makes a new txt file and prints all data to that file
	if (file.is_open()) {
		while (current != NULL) {
			file << current->getX() << "," << current->getY() << "," << current->getZ() << "," << memSaver << "," << current->whatOrientation(memSaver) << endl;
			current = current->getNext();
		}
	}

	file.close(); //ends by closing the file
}